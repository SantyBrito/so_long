/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:03:51 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 21:18:57 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

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
				ft_draw_wall(data);
			else if (tile_num == '0')
				ft_draw_grass(data);
			else if (tile_num == 'P')
				ft_draw_player(data);
			else if (tile_num == 'E')
				ft_draw_exit(data, c);
			else if (tile_num == 'C')
				ft_draw_collectable(data);
			data->x++;
		}
		data->y++;
	}
}
