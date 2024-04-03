/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:08:58 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/03 17:04:08 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile_num(t_mlx_data *data, char *argv)
{
	printf("linegfhgfgjfjhgjhg");
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
			break;
		if (!data->x_tiles)
			data->x_tiles = so_long_strlen(line);
		data->y_tiles++;
		free(line);
	}
}
void	create_map(t_mlx_data *data, char *argv)
{
	int 	y;
	int		fd;
	char	*line;
	
	data->map = malloc(sizeof(char *) * data->y_tiles);
	fd = open(argv, O_RDONLY);
	y = 0;
	printf("data->y_tiles: %d\n", data->y_tiles);
	printf("data->x_tiles: %d\n", data->x_tiles);
	while (y < data->y_tiles)
	{
		line = get_next_line(fd);
		printf("line: %d\n", so_long_strlen(line));
		if (so_long_strlen(line) != data->x_tiles)
		{
			write(2, "Error\nThe map must be rectangular\n", 35);
			free(line);
			ft_error(data);
		}
		data->map[y] = line;
		y++;
	}
}

void	draw_map(t_mlx_data *data)
{
	int	x;
	int	y;
	int	tile_num;
	
	y = 0;
	while (y < data->y_tiles)
	{
		x = 0;
		while (x < data->x_tiles)
		{
			tile_num = data->map[y][x];
			if (tile_num == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

int	handle_input(int keycode, t_mlx_data *data)
{
	if (XK_Escape == keycode)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	if (keycode == KEY_ARROW_RIGHT)
		data->player_x += 1;
	else if (keycode == KEY_ARROW_LEFT)
		data->player_x -= 1;
	else if (keycode == KEY_ARROW_UP)
		data->player_y -= 1;
	else if (keycode == KEY_ARROW_DOWN)
		data->player_y += 1;
	return (0);
}
