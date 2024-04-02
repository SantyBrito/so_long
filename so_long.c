/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/02 19:06:14 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	data;
	double		dist;
	int			color;

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
	data.img = mlx_xpm_file_to_image(data.mlx,"img/p.xpm", &data.map_width, &data.map_height);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	set_tile_num(&data);
	create_map(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

//65361 <, 65362 ^, 65363 >, 65364 v, 65307 Esc