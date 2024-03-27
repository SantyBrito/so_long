/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:54 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/27 20:42:44 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define MLX_ERROR		1
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_mlx_data
{
	void	*connection;
	void	*window;
	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
	char	**map;
	int		y_tiles;
	int		x_tiles;
}	t_mlx_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char	*str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*edited_strjoin(char *s1, char *s2);

#endif