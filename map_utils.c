/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:08:58 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 20:33:48 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile_num(t_mlx_data *data, char *argv)
{
	int		fd;
	char	*line;

	data->y_tiles = 0;
	data->x_tiles = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nUnable to open the map file\n", 35);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!data->x_tiles)
			data->x_tiles = so_long_strlen(line);
		data->y_tiles++;
		free(line);
	}
}

void	create_map(t_mlx_data *data, char *argv)
{
	int		y;
	int		fd;
	char	*line;

	data->map = malloc(sizeof(char *) * (data->y_tiles + 1));
	fd = open(argv, O_RDONLY);
	y = 0;
	while (y < data->y_tiles)
	{
		line = get_next_line(fd);
		if (so_long_strlen(line) != data->x_tiles)
		{
			write(2, "Error\nThe map must be rectangular\n", 35);
			free(line);
			ft_error(data);
		}
		data->map[y] = line;
		y++;
	}
	data->map[y] = NULL;
	map_check(data);
}

int	ft_player_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	ft_player_y(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

int	handle_input(int keycode, t_mlx_data *data)
{
	data->keycode = keycode;
	if (XK_Escape == keycode)
	{
		ft_destroy(data);
	}
	ft_movement(keycode, data);
	draw_map(data);
	return (0);
}
