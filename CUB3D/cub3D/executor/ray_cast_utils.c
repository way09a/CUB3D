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

int	closing_cub(t_graph *lst)
{
	mlx_destroy_image(lst->mlx, lst->wind);
	free_all(lst->data, "EXIT");
	return (0);
}

double	distance_points(double x1, double x2, double y1, double y2)
{
	double	square_root;

	square_root = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return (square_root);
}

int	calculate_intersactions(t_graph *lst)
{
	double	distance_ho;
	double	distance_ve;

	distance_ho = 0;
	distance_ve = 0;
	if (lst->raycast.horiz_intersaction)
		distance_ho = distance_points(lst->plyr.x_plyr, lst->raycast.xinter_ho, \
		lst->plyr.y_plyr, lst->raycast.yinter_ho);
	else
		distance_ho = -1;
	if (lst->raycast.vertic_intersaction)
		distance_ve = distance_points(lst->plyr.x_plyr, lst->raycast.xinter_ve, \
		lst->plyr.y_plyr, lst->raycast.yinter_ve);
	else
		distance_ve = -1;
	if (distance_ho == -1)
		return (1);
	else if (distance_ve == -1)
		return (0);
	if (distance_ho > distance_ve)
		return (1);
	else
		return (0);
}

void	normilizeangle(double	*ray_angle)
{
	*ray_angle = fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle = (2 * M_PI) + *ray_angle;
}

void	checking_where_plyr_facing(t_graph *lst)
{
	if (lst->raycast.ray_angle >= M_PI && lst->raycast.ray_angle <= (2 * M_PI))
	{
		lst->raycast.facingup = 1;
		lst->raycast.facingdown = 0;
	}
	else
	{
		lst->raycast.facingup = 0;
		lst->raycast.facingdown = 1;
	}
	if (lst->raycast.ray_angle >= (0.5 * M_PI) && \
	lst->raycast.ray_angle <= (1.5 * M_PI))
	{
		lst->raycast.facingright = 0;
		lst->raycast.facingleft = 1;
	}
	else
	{
		lst->raycast.facingright = 1;
		lst->raycast.facingleft = 0;
	}
}
