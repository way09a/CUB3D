/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:59:14 by ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:59:16 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	empty_map_checker(t_cub *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_d.map[y])
	{
		x = 0;
		while (data->map_d.map[y][x] == ' ' || data->map_d.map[y][x] == '\t')
			x++;
		if (!data->map_d.map[y][x])
			return (1);
		y++;
	}
	return (0);
}

static int	check_symbol(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	else
		return (0);
}

static int	is_valid(t_cub *data, int y, int x)
{
	if (y == 0 || data->map_d.map[y - 1][x] == ' ')
		return (1);
	if (!data->map_d.map[y + 1] || data->map_d.map[y + 1][x] == ' ')
		return (1);
	if (x == 0 || data->map_d.map[y][x - 1] == ' ')
		return (1);
	if (data->map_d.map[y][x + 1] == ' ' || !data->map_d.map[y][x + 1])
		return (1);
	return (0);
}

void	array_map_checker(t_cub *data)
{
	int	y;
	int	x;

	if (empty_map_checker(data))
		free_all(data, "Empyt line!!");
	y = -1;
	while (data->map_d.map[++y])
	{
		x = -1;
		while (data->map_d.map[y][++x])
		{
			if (check_symbol(data->map_d.map[y][x]))
				if (is_valid(data, y, x))
					free_all(data, "Invalid map!!");
		}
	}
}
