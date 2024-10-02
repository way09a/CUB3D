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

void	texture_init(t_graph *lst, t_cub *data)
{
	lst->texture.textureimgn = mlx_xpm_file_to_image(lst->mlx, data->no_t, \
	&lst->texture.widthn, &lst->texture.heightn);
	if (lst->texture.textureimgn == NULL)
		exit (1);
	lst->texture.imgaddrn = (int *)mlx_get_data_addr(lst->texture.textureimgn, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimgs = mlx_xpm_file_to_image(lst->mlx, data->so_t, \
	&lst->texture.widths, &lst->texture.heights);
	if (lst->texture.textureimgs == NULL)
		exit (1);
	lst->texture.imgaddrs = (int *)mlx_get_data_addr(lst->texture.textureimgs, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimge = mlx_xpm_file_to_image(lst->mlx, data->ea_t, \
	&lst->texture.widthe, &lst->texture.heighte);
	if (lst->texture.textureimge == NULL)
		exit (1);
	lst->texture.imgaddre = (int *)mlx_get_data_addr(lst->texture.textureimge, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimgw = mlx_xpm_file_to_image(lst->mlx, data->we_t, \
	&lst->texture.widthw, &lst->texture.heightw);
	if (lst->texture.textureimgw == NULL)
		exit (1);
	lst->texture.imgaddrw = (int *)mlx_get_data_addr(lst->texture.textureimgw, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
}
