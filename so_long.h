/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:54 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 18:00:20 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MLX_ERROR 1
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1100
# define KEY_ARROW_RIGHT 65363
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_UP 65362
# define KEY_ARROW_DOWN 65364

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		keycode;
	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
	char	**map;
	char	**copy_map;
	int		y_tiles;
	int		x_tiles;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		moves;
}			t_mlx_data;

void		ft_movement(int keycode, t_mlx_data *data);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*edited_strjoin(char *s1, char *s2);
void		create_map(t_mlx_data *data, char *argv);
void		set_tile_num(t_mlx_data *data, char *argv);
int			handle_input(int keycode, t_mlx_data *data);
void		ft_error(t_mlx_data *data);
int			so_long_strlen(const char *str);
void		map_check(t_mlx_data *data);
void		collect_check(t_mlx_data *data);
void		dup_check(t_mlx_data *data);
void		draw_map(t_mlx_data *data);
void		ft_destroy(t_mlx_data *data);
int			ft_count_collectable(t_mlx_data *data);
int			ft_printf(const char *str, ...);
int			funct_str(char *c);
int			funct_ptr(unsigned long int n);
int			funct_dec(int n);
int			funct_unsigned_dec(unsigned int n);
int			funct_hex(unsigned int n, int flag);
void		ft_destroy_mlx(t_mlx_data *data);
void		ft_free_map(char **map);

#endif