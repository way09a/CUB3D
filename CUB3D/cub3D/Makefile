# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahussein <ahussein@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 18:56:20 by Ahussein          #+#    #+#              #
#    Updated: 2023/08/10 19:52:13 by ahussein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

PARSING = parsing/pars.c parsing/texture_checker.c parsing/color_texture.c parsing/pars_map.c parsing/creating_map.c \
		parsing/map_valid.c
		
EXECUTOR = executor/executor.c executor/draw.c executor/movement.c \
			executor/cast_ray.c executor/vertical_inter.c executor/ray_cast_utils.c \
			executor/horizantal_inter.c executor/init.c executor/draw_ceilling.c executor/texture.c \
			executor/render.c executor/init_texture.c 

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS	= cub3d.c $(PARSING) $(GNL) $(EXECUTOR)

LIBFLAG = ../libft/libft.a

OBJS = ${SRCS:.c=.o}


all:	${NAME}

${NAME}: ${OBJS}
	make -C ./mlx
	make -C ../libft
	cc ${CFLAGS}  ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFLAG)  -o ${NAME}
	
clean:
	make -C ../libft clean
	make -C ./mlx clean
	rm -f ${OBJS}


fclean:	clean
	make -C ../libft fclean
	rm -f ${NAME}
re:	fclean all