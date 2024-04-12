/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:18:27 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 21:20:32 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_wall(t_mlx_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->map_width, &data->map_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 50,
		data->y * 50);
	mlx_destroy_image(data->mlx, data->img);
}

void	ft_draw_grass(t_mlx_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "img/grass.xpm",
			&data->map_width, &data->map_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 50,
		data->y * 50);
	mlx_destroy_image(data->mlx, data->img);
}

void	ft_draw_player(t_mlx_data *data)
{
	if (data->keycode == KEY_ARROW_RIGHT)
		data->img = mlx_xpm_file_to_image(data->mlx, "img/player_right.xpm",
				&data->map_width, &data->map_height);
	else if (data->keycode == KEY_ARROW_LEFT)
		data->img = mlx_xpm_file_to_image(data->mlx, "img/player_left.xpm",
				&data->map_width, &data->map_height);
	else if (data->keycode == KEY_ARROW_UP)
		data->img = mlx_xpm_file_to_image(data->mlx, "img/player_up.xpm",
				&data->map_width, &data->map_height);
	else
		data->img = mlx_xpm_file_to_image(data->mlx, "img/player_down.xpm",
				&data->map_width, &data->map_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 50,
		data->y * 50);
	mlx_destroy_image(data->mlx, data->img);
	data->player_x = data->x;
	data->player_y = data->y;
}

void	ft_draw_exit(t_mlx_data *data, int c)
{
	if (c != 0)
		data->img = mlx_xpm_file_to_image(data->mlx, "img/door_closed.xpm",
				&data->map_width, &data->map_height);
	else
		data->img = mlx_xpm_file_to_image(data->mlx, "img/door_open.xpm",
				&data->map_width, &data->map_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 50,
		data->y * 50);
	mlx_destroy_image(data->mlx, data->img);
}

void	ft_draw_collectable(t_mlx_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "img/collectable.xpm",
			&data->map_width, &data->map_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x * 50,
		data->y * 50);
	mlx_destroy_image(data->mlx, data->img);
}
