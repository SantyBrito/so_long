/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:03:51 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 17:23:01 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// free xpm file to image and destroy put image to window

void	draw_map(t_mlx_data *data)
{
	char	tile_num;
	int		c;

	c = ft_count_collectable(data);
	data->y = 0;
	while (data->y < data->y_tiles)
	{
		data->x = 0;
		while (data->x < data->x_tiles)
		{
			tile_num = data->map[data->y][data->x];
			if (tile_num == '1')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
						&data->map_width, &data->map_height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, data->x
					* 50, data->y * 50);
				mlx_destroy_image(data->mlx, data->img);
			}
			else if (tile_num == '0')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "img/grass.xpm",
						&data->map_width, &data->map_height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, data->x
					* 50, data->y * 50);
				mlx_destroy_image(data->mlx, data->img);
			}
			else if (tile_num == 'P')
			{
				if (data->keycode == KEY_ARROW_RIGHT)
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/player_right.xpm", &data->map_width,
							&data->map_height);
				else if (data->keycode == KEY_ARROW_LEFT)
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/player_left.xpm", &data->map_width,
							&data->map_height);
				else if (data->keycode == KEY_ARROW_UP)
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/player_up.xpm", &data->map_width,
							&data->map_height);
				else
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/player_down.xpm", &data->map_width,
							&data->map_height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, data->x
					* 50, data->y * 50);
				mlx_destroy_image(data->mlx, data->img);
				data->player_x = data->x;
				data->player_y = data->y;
			}
			else if (tile_num == 'E')
			{
				if (c != 0)
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/door_closed.xpm", &data->map_width,
							&data->map_height);
				else
					data->img = mlx_xpm_file_to_image(data->mlx,
							"img/door_open.xpm", &data->map_width,
							&data->map_height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, data->x
					* 50, data->y * 50);
				mlx_destroy_image(data->mlx, data->img);
			}
			else if (tile_num == 'C')
			{
				data->img = mlx_xpm_file_to_image(data->mlx,
						"img/collectable.xpm", &data->map_width,
						&data->map_height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, data->x
					* 50, data->y * 50);
				mlx_destroy_image(data->mlx, data->img);
			}
			data->x++;
		}
		data->y++;
	}
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

void	ft_destroy(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
