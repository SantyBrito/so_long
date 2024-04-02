/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/02 17:17:38 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	//data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img = mlx_xpm_file_to_image(data.mlx,"img/p.xpm", &data.map_width, &data.map_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	while (data.y < WINDOW_HEIGHT) {
        data.x = 0;
        while (data.x < WINDOW_WIDTH) {
            // Calculate distance to center
            dist = sqrt((data.x - WINDOW_WIDTH/2) * (data.x - WINDOW_WIDTH/2) + (data.y - WINDOW_HEIGHT/2) * (data.y - WINDOW_HEIGHT/2));
			// Normalize distance to a range between 0 and 1
			double normalized_dist = dist / (sqrt(WINDOW_WIDTH*WINDOW_WIDTH + WINDOW_HEIGHT*WINDOW_HEIGHT) / 2);

			// Map normalized distance to rainbow colors (red to violet)
			color = (int)(normalized_dist * 255);

            // Set pixel color
            my_mlx_pixel_put(&data, data.x, data.y, (255 << 24) | (255 - color) | (color << 16));

            data.x++;
        }
        data.y++;
    }
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	create_map(&data);
	y_tiles_num(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

//65361 <, 65362 ^, 65363 >, 65364 v, 65307 Esc