/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:59:24 by ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:59:26 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	checker_color(char **split_color, t_cub *data, char *str, char *ptr)
{
	int		color_atof;
	int		i;

	i = 0;
	while (i < ft_arrlen(split_color))
	{
		color_atof = ft_atoi(split_color[i]);
		if (color_atof > 255 || color_atof < 0)
		{
			free(str);
			ft_free_array(split_color);
			free(ptr);
			free_all(data, "Error!! Color Number ");
		}
		i++;
	}
}

void	color_is_digit(char **split_color, t_cub *data, char *str, char *ptr)
{
	char	*str1;
	int		i;
	int		j;

	i = 0;
	while (split_color[i])
	{
		j = 0;
		str1 = ft_strtrim(&split_color[i][j], " ");
		while (str1[j])
		{
			if (!ft_isdigit(str1[j]) && str1[j] != '.')
			{
				free(str1);
				free(str);
				ft_free_array(split_color);
				free(ptr);
				free_all(data, "Error!! Color Letter");
			}
			j++;
		}
		free(str1);
		i++;
	}
}

void	put_color(int *count, char **split_color, t_cub *data, char *c)
{
	*count += 1;
	if (c[0] == 'F')
		data->floor_color = (ft_atoi(split_color[0]) << 16 | \
			ft_atoi(split_color[1]) << 8 | ft_atoi(split_color[2]));
	else
		data->ceil_color = (ft_atoi(split_color[0]) << 16 | \
			ft_atoi(split_color[1]) << 8 | ft_atoi(split_color[2]));
}

void	semicolon_counter(t_cub *data, char *str, char *ptr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2 || count < 2 || str[ft_strlen(str) - 1] == ',')
	{
		free(str);
		free(ptr);
		free_all(data, "Error!! semicolon");
	}
}

void	color_texture(int *count, char *ptr, t_cub *data, char *c)
{
	char	**split_color;
	char	*str;

	str = ft_substr(ptr, 1, ft_strlen(ptr) - 1);
	semicolon_counter(data, str, ptr);
	split_color = ft_split(str, ',');
	color_is_digit(split_color, data, str, ptr);
	checker_color(split_color, data, str, ptr);
	if (ft_arrlen(split_color) == 3)
		put_color(count, split_color, data, c);
	else
	{
		free(str);
		ft_free_array(split_color);
		free(ptr);
		free_all(data, "Error!! Colorrr");
	}
	free(str);
	ft_free_array(split_color);
}
