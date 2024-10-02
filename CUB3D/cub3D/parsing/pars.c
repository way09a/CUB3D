/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:59:41 by ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:59:43 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_text_col_data(t_cub *data)
{
	if (data->no_t == NULL || data->so_t == NULL || data->ea_t == NULL || \
		data->we_t == NULL || data->ceil_color == -1 || data->floor_color == -1)
		free_all(data, "Error!! map arg");
}

int	ft_map_checker(t_cub	*data)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	data->line = get_next_line(data->fd);
	while (data->line != NULL)
	{
		if (count < 6)
			data_process(data->line, data, &count);
		else
		{
			check_text_col_data(data);
			map_checker(data->line, data, i);
		}
		i++;
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	free(data->line);
	if (data->map_d.count_player == 0 || data->map_d.count_player > 1)
		free_all(data, "Error!! bad player number");
	return (0);
}

int	cub3ddata_init(t_cub *data, char **argv)
{
	char	*str;

	data->no_t = NULL;
	data->so_t = NULL;
	data->ea_t = NULL;
	data->we_t = NULL;
	data->ceil_color = -1;
	data->floor_color = -1;
	data->map_d.map_hight = 0;
	data->map_d.map_width = 0;
	data->map_d.fst_line = 0;
	data->map_d.count_player = 0;
	data->map_d.map = NULL;
	str = ft_strrchr(argv[1], '.');
	if (str && !ft_strcmp(str, ".cub"))
	{
		data->fd = open(argv[1], O_RDONLY);
		if (data->fd < 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	pars(char **argv, t_cub *data)
{
	if (cub3ddata_init(data, argv) || ft_map_checker(data))
		return (1);
	creat_cub3d_array(data, argv);
	array_map_checker(data);
	return (0);
}
