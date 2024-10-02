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

void	draw_walls(t_graph *lst)
{
	rotate_player(lst);
	player_movement(lst);
	rays_casting(lst);
}

void	my_mlx_pixel_put(t_graph *lst, int x, int y, int color)
{
	char	*test;

	if ((x >= 0 && x < lst->map.width) && (y >= 0 && y < lst->map.height))
	{
		test = &lst->map.addr[(y * lst->map.size_line) + \
		(x * lst->map.bpp / 8)];
		*(unsigned int *)test = color;
	}
}
