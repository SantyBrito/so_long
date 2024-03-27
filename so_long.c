/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/27 20:51:01 by sbrito           ###   ########.fr       */
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
		mlx_destroy_window(data->connection, data->window);
		mlx_destroy_display(data->connection);
		free(data->connection);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.connection = mlx_init();
	if (NULL == data.connection)
		return (MLX_ERROR);
	data.window = mlx_new_window(data.connection, \
								WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (NULL == data.window)
	{
		mlx_destroy_display(data.connection);
		free(data.connection);
		return (MLX_ERROR);
	}
	y_tiles_num(&data);
	mlx_key_hook(data.window, handle_input, &data);
	mlx_loop(data.connection);
	mlx_destroy_window(data.connection, data.window);
	mlx_destroy_display(data.connection);
	free(data.connection);
}

//65361 <, 65362 ^, 65363 >, 65364 v, 65307 Esc