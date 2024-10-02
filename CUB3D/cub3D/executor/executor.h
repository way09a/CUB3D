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

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../cub3d.h"

typedef struct s_map
{
	int		unit;
	int		floor_color;
	int		wall_color;
	int		player_color;
	char	**map;
	double	minimap;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img;
	char	*addr;
	void	*img1;
	char	*addr1;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	double	x_plyr;
	double	y_plyr;
	double	rotationangle;
	double	speed;
	double	fov;
	double	rotationspeed;
	int		rotatedirection;
	int		walkdirection;
	int		walkdirectionleftright;
}	t_player;

typedef struct s_raycasting
{
	double	ray_angle;
	int		num_rays;
	double	xinter_ho;
	double	yinter_ho;
	double	xinter_ve;
	double	yinter_ve;
	double	xstep;
	double	ystep;
	int		facingup;
	int		facingdown;
	int		facingleft;
	int		facingright;
	int		horiz_intersaction;
	int		vertic_intersaction;
	double	wallstripeheight;
}	t_raycasting;

typedef struct s_texture
{
	void	*textureimgn;
	int		*imgaddrn;
	void	*textureimgs;
	int		*imgaddrs;
	void	*textureimge;
	int		*imgaddre;
	void	*textureimgw;
	int		*imgaddrw;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		widthn;
	int		heightn;
	int		widths;
	int		heights;
	int		widthw;
	int		heightw;
	int		widthe;
	int		heighte;
}	t_texture;

typedef struct s_graph
{
	void				*mlx;
	void				*wind;
	int					x;
	int					y;
	int					x1;
	int					y1;
	int					old_x;
	int					new_x;
	int					minimap_check;
	t_cub				*data;
	struct s_player		plyr;
	struct s_raycasting	raycast;
	struct s_map		map;
	struct s_texture	texture;
}	t_graph;

/* --------------------------------- PARSING ------------------------------- */

int		deal_key(int key, t_graph *var);
int		checkwallmovement(t_graph *lst, int x, int y);
int		checkwall(t_graph *lst, int x, int y);

/* --------------------------------- INIT ------------------------------- */

void	init_player(t_graph *lst, t_cub *data);
void	init_raycast(t_graph *lst);
void	init_map(t_graph *lst, t_cub *data);
void	init_everything(t_graph *lst, t_cub *data);
void	texture_init(t_graph *lst, t_cub *data);

/* --------------------------------- RAYCAST ----------------------------- */

void	rays_casting(t_graph *lst);
void	normilizeangle(double *ray_angle);
void	vertical_intersaction(t_graph *lst);
void	intersaction_horizantal(t_graph *lst);
void	checking_where_plyr_facing(t_graph *lst);
int		calculate_intersactions(t_graph *lst);
double	distance_points(double x1, double x2, double y1, double y2);

/* --------------------------------- DRAWING ----------------------------- */

void	my_mlx_pixel_put(t_graph *lst, int x, int y, int color);
void	floorandceilling_drow(t_graph *lst);
void	draw_walls(t_graph *lst);
void	cub1_drowing(int y, int y1, t_graph *lst, int i);
void	recasting_drow(int x, int y, int y1, t_graph *lst);

/* --------------------------------- MAP ----------------------------- */

int		routine(t_graph *lst);
int		reset(int key, t_graph *var);

/* --------------------------------- TEXTURE ----------------------------- */

double	get_x_of_texture(t_graph *lst, int i, int width);
void	get_widthheight(t_graph *lst, int *width, int *height, int i);
int		take_texture(t_graph *lst, int y, int x, int i);

/* --------------------------------- PROTOTYPES ----------------------------- */

void	rotate_player(t_graph *lst);
void	player_movement(t_graph *lst);
int		closing_cub(t_graph *lst);

#endif
