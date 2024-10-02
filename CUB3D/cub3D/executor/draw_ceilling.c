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

void	cub1_drowing(int y, int y1, t_graph *lst, int i)
{
	int	j;
	int	x1;

	x1 = lst->map.width;
	while (y < y1)
	{
		j = 0;
		while (j <= x1)
		{
			my_mlx_pixel_put(lst, j, y, i);
			j++;
		}
		y++;
	}
}

void	floorandceilling_drow(t_graph *lst)
{
	double	i;

	i = (lst->map.height) / 2;
	cub1_drowing(0, i, lst, lst->map.player_color);
	cub1_drowing(i, lst->map.height, lst, lst->map.floor_color);
}
