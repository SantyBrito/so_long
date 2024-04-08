/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:05:27 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/08 15:29:19 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_mlx_data *data)
{
	if (data->map)
		free(data->map);
	if (data->mlx)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
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

void	map_check(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y_tiles)
	{
		x = 0;
		while (x < data->x_tiles)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'P' && data->map[y][x] != 'E' && data->map[y][x] != 'C')
			{
				write(2, "Error\nInvalid map\n", 19);
				ft_error(data);
			}
			collect_check(data);
			dup_check(data);
			x++;
		}
		y++;
	}
}

void	collect_check(t_mlx_data *data)
{
	int	count;

	data->y = 0;
	count = 0;
	while (data->y < data->y_tiles)
	{
		data->x = 0;
		while (data->x < data->x_tiles)
		{
			if (data->map[data->y][data->x] == 'C')
				count++;
			data->x++;
		}
		data->y++;
	}
	if (count == 0)
	{
		write(2, "Error\nNo collectibles\n", 23);
		ft_error(data);
	}
}

void	dup_check(t_mlx_data *data)
{
	int	count_p;
	int	count_e;

	data->y = 0;
	count_p = 0;
	count_e = 0;
	while (data->y < data->y_tiles)
	{
		data->x = 0;
		while (data->x < data->x_tiles)
		{
			if (data->map[data->y][data->x] == 'P')
				count_p++;
			if (data->map[data->y][data->x] == 'E')
				count_e++;
			data->x++;
		}
		data->y++;
	}
	if (count_p != 1 || count_e != 1)
	{
		write(2, "Error\nNo player or exit / too many players or exits\n", 52);
		ft_error(data);
	}
}
