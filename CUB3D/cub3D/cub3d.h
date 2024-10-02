/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:56:29 by Ahussein          #+#    #+#             */
/*   Updated: 2023/08/10 19:55:12 by ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1048
# define MAPWIDTH 12
# define MAPHEIGHT 12
# define HEIGHT 800
# define PI 3.14159265359
# define GRID 64

enum	e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

typedef struct s_mapdata
{
	char	**map;
	int		map_hight;
	int		map_width;
	int		fst_line;
	int		count_player;
	int		player_x;
	int		player_y;
}	t_mapData;

typedef struct s_cub
{
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
	char		*line;
	int			fd;
	int			ceil_color;
	int			floor_color;
	t_mapData	map_d;

}	t_cub;

/* -------------------------PARSING-------------------------------------- */

int		pars(char **argv, t_cub *data);
int		data_process(char *str, t_cub *map, int *count);
void	color_texture(int *count, char *ptr, t_cub *data, char *c);
int		map_checker(char *str, t_cub *data, int i);
void	creat_cub3d_array(t_cub *data, char **argv);
void	array_map_checker(t_cub *data);
void	free_all(t_cub *data, char *str);

/* -------------------------EXECUTOR-------------------------------------- */
void	executor(t_cub *cub);
#endif
