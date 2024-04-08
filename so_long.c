/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/08 18:51:39 by sbrito           ###   ########.fr       */
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
	if (NULL == data.mlx)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, \
								WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (NULL == data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (MLX_ERROR);
	}
	set_tile_num(&data, argv[1]);
	create_map(&data, argv[1]);
	map_check(&data);
	draw_map(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

//65361 <, 65362 ^, 65363 >, 65364 v, 65307 Esc