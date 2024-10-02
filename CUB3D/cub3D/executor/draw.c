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

void	rotate_player(t_graph *lst)
{
	if (lst->plyr.rotatedirection == -1)
		lst->plyr.rotationangle += (-1 * lst->plyr.rotationspeed);
	if (lst->plyr.rotatedirection == 1)
		lst->plyr.rotationangle += lst->plyr.rotationspeed;
	normilizeangle(&lst->plyr.rotationangle);
}

void	player_movement(t_graph *lst)
{
	double	save1;
	double	save2;
	double	step;

	step = lst->plyr.walkdirection * lst->plyr.speed;
	save1 = lst->plyr.x_plyr + (step * cos(lst->plyr.rotationangle));
	save2 = lst->plyr.y_plyr + (step * sin(lst->plyr.rotationangle));
	if (checkwallmovement(lst, save1, save2))
		return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
	step = lst->plyr.walkdirectionleftright * lst->plyr.speed;
	save1 = lst->plyr.x_plyr + (step * sin(lst->plyr.rotationangle));
	save2 = lst->plyr.y_plyr - (step * cos(lst->plyr.rotationangle));
	if (checkwallmovement(lst, save1, save2))
		return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
}
