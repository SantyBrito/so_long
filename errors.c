/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:05:27 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 18:03:03 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_count(char **map, char c);

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		printf("%s", map[y]);
		y++;
	}
	printf("\n\n");
}

void	fill(char **tab, t_point size, t_point begin, char to_fill[])
{
	char	c;
	int		i;

	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	c = tab[begin.y][begin.x];
	i = 0;
	while (i < 4)
	{
		if (c == to_fill[i])
		{
			tab[begin.y][begin.x] = 'X';
			if (to_fill[i] == 'E')
				return ;
			fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
			fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
			break ;
		}
		i++;
	}
}

int	ft_player_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	ft_player_y(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

char	**ft_copy_map(char **map)
{
	char	**copy;
	int		y;

	y = 0;
	while (map[y])
		y++;
	copy = (char **)malloc(sizeof(char *) * (y + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (map[y])
	{
		copy[y] = ft_strdup(map[y]);
		if (!copy[y])
			return (NULL);
		y++;
	}
	copy[y] = NULL;
	return (copy);
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
		ft_error(data);
	}
	ft_free_map(data->copy_map);
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
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'P' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'C')
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
	not_path(data);
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
