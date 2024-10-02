/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:59:33 by ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:59:35 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_checker_error(char *str, t_cub *data)
{
	int		i;
	char	c;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' \
			|| c == 'W' || c == 'E')
		{
			i++;
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				data->map_d.count_player++;
		}
		else
			return (1);
	}
	return (0);
}

void	free_data_ch(char *ptr, char *ptr1)
{
	free(ptr);
	free(ptr1);
}

int	map_checker(char *str, t_cub *data, int i)
{
	char	*ptr;
	char	*ptr1;

	ptr1 = ft_strtrim(str, "\n\t");
	ptr = ft_strtrim(ptr1, " ");
	if (ft_strlen(ptr) == 0)
		return (free(ptr1), free(ptr), 0);
	else
	{
		if (data->map_d.fst_line == 0)
			data->map_d.fst_line = i;
		data->map_d.map_hight++;
	}
	if (data->map_d.map_hight > 0 && ft_strlen(ptr) != 0)
	{
		if (map_checker_error(ptr1, data))
		{
			free_data_ch(ptr, ptr1);
			free_all(data, "Error!! invalid map");
		}
	}
	if ((int)ft_strlen(ptr1) > data->map_d.map_width)
		data->map_d.map_width = ft_strlen(ptr1);
	return (free(ptr1), free(ptr), 0);
}
