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

void	recasting_drow(int x, int y, int y1, t_graph *lst)
{
	double	posx;
	double	posy;
	int		pixel_color;
	double	ds;
	int		i;

	pixel_color = 0;
	posx = 0;
	posy = 0;
	i = calculate_intersactions(lst);
	get_widthheight(lst, &lst->texture.width, &lst->texture.height, i);
	posx = get_x_of_texture(lst, i, lst->texture.width);
	ds = 0;
	while (y <= y1)
	{
		ds = y + (lst->raycast.wallstripeheight / 2) - ((lst->map.height) / 2);
		posy = ds * (double)lst->texture.height / lst->raycast.wallstripeheight;
		pixel_color = take_texture(lst, posy, posx, i);
		my_mlx_pixel_put(lst, x, y, pixel_color);
		y++;
	}
}

void	walls_render(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xinter_ho, \
		lst->plyr.y_plyr, lst->raycast.yinter_ho);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xinter_ve, \
		lst->plyr.y_plyr, lst->raycast.yinter_ve);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	lst->raycast.wallstripeheight = (lst->map.unit / distance) * \
	distanceprojectionplane;
	startpointy = (lst->map.height / 2) - (lst->raycast.wallstripeheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = lst->raycast.wallstripeheight + ((lst->map.height) / 2) - \
	(lst->raycast.wallstripeheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	recasting_drow(i,
		startpointy,
		endpointy, lst);
}

void	rays_casting(t_graph *lst)
{
	int		i;
	int		rays_num;
	int		j;

	lst->raycast.xinter_ho = 0;
	lst->raycast.yinter_ho = 0;
	lst->raycast.ray_angle = lst->plyr.rotationangle - lst->plyr.fov / 2;
	i = 0;
	j = 0;
	rays_num = lst->map.width;
	while (i < rays_num)
	{
		normilizeangle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		intersaction_horizantal(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		walls_render(lst, i, j);
		lst->raycast.ray_angle += lst->plyr.fov / rays_num;
		i++;
	}
}
