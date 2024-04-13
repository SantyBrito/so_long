/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:03:51 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/13 17:27:08 by sbrito           ###   ########.fr       */
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

void	free_line(t_mlx_data *data)
{
	int i;
	
	i = 0;
	while(i < data->y_tiles)
		free(data->map[i++]);
	exit(1);
}

void	check_ones(t_mlx_data *data)
{
    int	i;
    int	j;

    i = 0;
    j = so_long_strlen(data->map[i]) - 1;
    while (data->map[i])
    {
        if (data->map[i][0] != '1' || data->map[i][j] != '1')
        {
            ft_printf("Error\nInvalid map\n");
            free_line(data);
            ft_error(data);
        }
        i++;
    }
    j = 0;
    int last_row = i - 1;
    while (j <= so_long_strlen(data->map[0]) - 1)
    {
        if (data->map[0][j] != '1' || data->map[last_row][j] != '1')
        {
            ft_printf("Error\nInvalid map\n");
            free_line(data);
            ft_error(data);
        }
        j++;
    }
}
