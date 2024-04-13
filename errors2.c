/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:25:25 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/13 17:29:56 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	not_path(t_mlx_data *data)
{
	int			x;
	int			y;
	int			width;
	int			height;
	static char	to_fill[4] = {'0', 'C', 'E', 'P'};

	data->copy_map = ft_copy_map(data->map);
	x = ft_player_x(data->map);
	y = ft_player_y(data->map);
	width = data->x_tiles;
	height = data->y_tiles;
	fill(data->copy_map, (t_point){width, height}, (t_point){x, y}, to_fill);
	if (ft_count(data->copy_map, 'E') != 0
		|| ft_count(data->copy_map, 'C') != 0)
	{
		write(2, "Error\nNo path to collectibles or exit\n", 38);
		free_line(data);
		ft_error(data);
	}
	ft_free_map(data->copy_map);
}

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int	ft_count(char **map, char c)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	ft_count_collectable(t_mlx_data *data)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < data->y_tiles)
	{
		x = 0;
		while (x < data->x_tiles)
		{
			if (data->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s", map[y]);
		y++;
	}
	printf("\n\n");
}
