/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:40 by Ahussein          #+#    #+#             */
/*   Updated: 2023/08/09 22:02:41 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_cub *data, char *str)
{
	printf("%s\n", str);
	if (data->line != NULL)
		free(data->line);
	if (data->ea_t != NULL)
		free(data->ea_t);
	if (data->no_t != NULL)
		free(data->no_t);
	if (data->so_t != NULL)
		free(data->so_t);
	if (data->we_t != NULL)
		free(data->we_t);
	if (data->map_d.map != NULL)
		ft_free_array(data->map_d.map);
	free(data);
	exit(1);
}

void	free_gar(t_cub	*data)
{
	free(data->ea_t);
	free(data->no_t);
	free(data->so_t);
	free(data->we_t);
	ft_free_array(data->map_d.map);
}

int	main(int argc, char **argv)
{
	t_cub	*data;

	data = (t_cub *)malloc(sizeof(t_cub));
	if (!data)
		return (0);
	if (argc == 2)
	{
		if (pars(argv, data))
			return (write(1, "Error invalid\n", 13), free(data), 0);
		executor(data);
		free_gar(data);
		free(data);
	}
	else
	{
		printf("Error arg number!!\n");
		return (free(data), 0);
	}
}
