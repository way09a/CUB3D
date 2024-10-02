/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:05:49 by Ahussein          #+#    #+#             */
/*   Updated: 2023/08/05 19:07:02 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../../libft/libft.h"
# include <stdlib.h>
# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

char	*get_next_line(int fd);
int		read_block(int fd, char **buf);
int		has_new_line(char *buf);
char	*ft_strndup(const char *s, int n);
char	*ft_strnjoin(char **buf, char **new_block);
char	*get_line(char **buf, int bytes_read, int line_len);

#endif
