/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealsomah <ealsomah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:37:34 by ealsomah         #+#    #+#             */
/*   Updated: 2023/08/10 19:38:50 by ealsomah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	direction(t_graph *lst, t_cub *data)
{
	if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'N')
		lst->plyr.rotationangle = (3 * M_PI / 2) + 0.005;
	else if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'S')
		lst->plyr.rotationangle = M_PI / 2 + 0.005;
	else if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'E')
		lst->plyr.rotationangle = 0 + 0.005;
	else if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'W')
		lst->plyr.rotationangle = M_PI + 0.005;
}

void	init_player(t_graph *lst, t_cub *data)
{
	direction(lst, data);
	lst->plyr.fov = 60 * (M_PI / 180);
	lst->plyr.speed = 4;
	lst->plyr.rotationspeed = 4 * (M_PI / 180);
	lst->plyr.rotatedirection = 0;
	lst->plyr.walkdirection = 0;
	lst->plyr.walkdirectionleftright = 0;
}

void	init_raycast(t_graph *lst)
{
	lst->raycast.facingup = 0;
	lst->raycast.facingdown = 0;
	lst->raycast.facingright = 0;
	lst->raycast.facingleft = 0;
	lst->raycast.horiz_intersaction = 0;
}

void	init_map(t_graph *lst, t_cub *data)
{
	lst->map.floor_color = data->floor_color;
	lst->map.wall_color = 0;
	lst->map.player_color = data->ceil_color;
	lst->map.unit = 32;
	lst->plyr.x_plyr = data->map_d.player_x * lst->map.unit;
	lst->plyr.y_plyr = data->map_d.player_y * lst->map.unit;
	lst->plyr.x_plyr += lst->map.unit / 4;
	lst->plyr.y_plyr += lst->map.unit / 4;
}

void	init_everything(t_graph *lst, t_cub *data)
{
	lst->y = data->map_d.map_hight;
	lst->x = data->map_d.map_width;
	lst->map.map = data->map_d.map;
	lst->map.height = 1000;
	lst->map.width = 1500;
	lst->mlx = mlx_init();
	if (lst->mlx == NULL)
		exit (1);
	lst->wind = mlx_new_window(lst->mlx, \
		lst->map.width, lst->map.height, "Cub3d");
	if (lst->wind == NULL)
		exit (1);
	lst->map.img = NULL;
	lst->map.addr = NULL;
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
	if (lst->map.img == NULL)
		exit (1);
	lst->map.addr = mlx_get_data_addr(lst->map.img, \
		&lst->map.bpp, &lst->map.size_line, &lst->map.endian);
	if (lst->map.addr == NULL)
		exit (1);
}
