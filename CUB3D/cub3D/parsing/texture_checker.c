/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:59:50 by ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:59:52 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_checker(t_cub *data, char *str, char *file)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		free(file);
		free_all(data, "Error!! texture file");
	}
	free(str);
}

void	texture_checker(int *count, char *ptr, t_cub *data, char *c)
{
	char	*str;
	char	*ptr1;

	*count += 1;
	ptr1 = ft_strrchr(ptr, '.');
	if (ptr1 && !ft_strcmp(ptr1, ".xpm"))
	{
		ptr1 = ft_substr(ptr, 2, ft_strlen(ptr) - 2);
		str = ft_strtrim(ptr1, " ");
		if (!ft_strcmp(c, "NO ") && !data->no_t)
			data->no_t = ft_strdup(str);
		if (!ft_strcmp(c, "EA ") && !data->ea_t)
			data->ea_t = ft_strdup(str);
		if (!ft_strcmp(c, "WE ") && !data->we_t)
			data->we_t = ft_strdup(str);
		if (!ft_strcmp(c, "SO ") && !data->so_t)
			data->so_t = ft_strdup(str);
		free(ptr1);
		file_checker(data, str, ptr);
	}
}

int	data_process(char *str, t_cub *data, int *count)
{
	char	*ptr;
	char	*ptr1;
	char	c[4];

	ptr1 = ft_strtrim(str, "\n");
	ptr = ft_strtrim(ptr1, " ");
	free(ptr1);
	if (ft_strlen(ptr) == 0)
		return (free(ptr), 0);
	ft_bzero(c, 4);
	c[0] = ptr[0];
	c[1] = ptr[1];
	c[2] = ptr[2];
	if (!ft_strcmp(c, "NO ") || !ft_strcmp(c, "EA ") || \
		!ft_strcmp(c, "WE ") || !ft_strcmp(c, "SO "))
		texture_checker(count, ptr, data, c);
	else if ((c[0] == 'F' || c[0] == 'C') && c[1] == ' ')
		color_texture(count, ptr, data, c);
	else
	{
		free(ptr);
		free_all(data, "error!! process data");
	}
	return (free(ptr), 0);
}
