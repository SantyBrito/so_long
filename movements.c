/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:21:01 by sbrito            #+#    #+#             */
/*   Updated: 2024/04/12 20:29:58 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ARROW_RIGHT)
		move_right(data);
	else if (keycode == KEY_ARROW_LEFT)
		move_left(data);
	else if (keycode == KEY_ARROW_UP)
		move_up(data);
	else if (keycode == KEY_ARROW_DOWN)
		move_down(data);
}

void	move_right(t_mlx_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'E')
		{
			if (ft_count_collectable(data) == 0)
				ft_destroy(data);
			return ;
		}
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}

void	move_left(t_mlx_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		if (data->map[data->player_y][data->player_x - 1] == 'E')
		{
			if (ft_count_collectable(data) == 0)
				ft_destroy(data);
			return ;
		}
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}

void	move_up(t_mlx_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		if (data->map[data->player_y - 1][data->player_x] == 'E')
		{
			if (ft_count_collectable(data) == 0)
				ft_destroy(data);
			return ;
		}
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}

void	move_down(t_mlx_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		if (data->map[data->player_y + 1][data->player_x] == 'E')
		{
			if (ft_count_collectable(data) == 0)
				ft_destroy(data);
			return ;
		}
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}

// void	ft_movement(int keycode, t_mlx_data *data)
// {
// 	if (keycode == KEY_ARROW_RIGHT && data->map[data->player_y][data->player_x
// 		+ 1] != '1')
// 	{
// 		if (data->map[data->player_y][data->player_x + 1] == 'E')
// 		{
// 			if (ft_count_collectable(data) == 0)
// 				ft_destroy(data);
// 			return ;
// 		}
// 		data->map[data->player_y][data->player_x + 1] = 'P';
// 		data->map[data->player_y][data->player_x] = '0';
// 		data->moves++;
// 		ft_printf("Moves: %d\n", data->moves);
// 	}
// 	if (keycode == KEY_ARROW_LEFT && data->map[data->player_y][data->player_x
// 		- 1] != '1')
// 	{
// 		if (data->map[data->player_y][data->player_x - 1] == 'E')
// 		{
// 			if (ft_count_collectable(data) == 0)
// 				ft_destroy(data);
// 			return ;
// 		}
// 		data->map[data->player_y][data->player_x - 1] = 'P';
// 		data->map[data->player_y][data->player_x] = '0';
// 		data->moves++;
// 		ft_printf("Moves: %d\n", data->moves);
// 	}
// 	if (keycode == KEY_ARROW_UP && data->map[data->player_y
// 			- 1][data->player_x] != '1')
// 	{
// 		if (data->map[data->player_y - 1][data->player_x] == 'E')
// 		{
// 			if (ft_count_collectable(data) == 0)
// 				ft_destroy(data);
// 			return ;
// 		}
// 		data->map[data->player_y - 1][data->player_x] = 'P';
// 		data->map[data->player_y][data->player_x] = '0';
// 		data->moves++;
// 		ft_printf("Moves: %d\n", data->moves);
// 	}
// 	if (keycode == KEY_ARROW_DOWN && data->map[data->player_y
// 			+ 1][data->player_x] != '1')
// 	{
// 		if (data->map[data->player_y + 1][data->player_x] == 'E')
// 		{
// 			if (ft_count_collectable(data) == 0)
// 				ft_destroy(data);
// 			return ;
// 		}
// 		data->map[data->player_y + 1][data->player_x] = 'P';
// 		data->map[data->player_y][data->player_x] = '0';
// 		data->moves++;
// 		ft_printf("Moves: %d\n", data->moves);
// 	}
// }