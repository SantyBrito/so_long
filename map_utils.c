/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:08:58 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/02 16:08:32 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_mlx_data *data)
{
	int		fd;
	char	*line;
	
	data->y_tiles = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!data->x_tiles)
			data->x_tiles = ft_strlen(line);
		free(line);
		data->y_tiles++;
	}
}

void	y_tiles_num(t_mlx_data *data)
{
	int		fd;
	char	*line;
	
	data->y_tiles = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!data->x_tiles)
			data->x_tiles = ft_strlen(line);
		free(line);
		data->y_tiles++;
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
