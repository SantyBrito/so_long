/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/11 15:26:39 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}
	data.mlx = mlx_init();
	data.moves = 0;
	if (NULL == data.mlx)
		return (MLX_ERROR);
	set_tile_num(&data, argv[1]);
	data.win = mlx_new_window(data.mlx, data.x_tiles * 50, data.y_tiles * 50, "so_long");
	if (NULL == data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (MLX_ERROR);
	}
	create_map(&data, argv[1]);
	draw_map(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

void	ft_error(t_mlx_data *data)
{
	if (data->map)
		free(data->map);
	exit(1);
}

int	so_long_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

// LEFT TO DO:
// fix leaks and norm