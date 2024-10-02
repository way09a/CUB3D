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

void	search_horizantalinter(t_graph *lst, int check)
{
	double	mapx;
	double	mapy;

	mapx = lst->x * lst->map.unit;
	mapy = lst->y * lst->map.unit;
	while ((lst->raycast.xinter_ho >= 0 && lst->raycast.xinter_ho <= mapx) \
	&& (lst->raycast.yinter_ho >= 0 && lst->raycast.yinter_ho <= mapy))
	{
		if (checkwall(lst, lst->raycast.xinter_ho, \
		lst->raycast.yinter_ho - check))
		{
			lst->raycast.horiz_intersaction = 1;
			return ;
		}
		else
		{
			lst->raycast.xinter_ho += lst->raycast.xstep;
			lst->raycast.yinter_ho += lst->raycast.ystep;
		}
	}
	lst->raycast.horiz_intersaction = 0;
}

void	intersaction_horizantal(t_graph *lst)
{
	int		check;

	check = 0;
	lst->raycast.horiz_intersaction = 0;
	lst->raycast.yinter_ho = floor(lst->plyr.y_plyr / lst->map.unit) \
		* lst->map.unit;
	if (lst->raycast.facingdown)
		lst->raycast.yinter_ho += lst->map.unit;
	lst->raycast.xinter_ho = lst->plyr.x_plyr + \
	(lst->raycast.yinter_ho - \
	lst->plyr.y_plyr) / tan(lst->raycast.ray_angle);
	lst->raycast.ystep = lst->map.unit;
	if (lst->raycast.facingup)
		lst->raycast.ystep *= -1;
	lst->raycast.xstep = lst->map.unit / tan(lst->raycast.ray_angle);
	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingright && lst->raycast.xstep < 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingup)
		check = 1;
	search_horizantalinter(lst, check);
}
