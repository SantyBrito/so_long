/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:37:07 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/26 19:22:42 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_mlx_data *data)
{
	if (XK_Escape == keycode) //keysym
	{
		write(1, "Exiting...\n", 11);
		mlx_destroy_window(data->connection, data->window);
		mlx_destroy_display(data->connection);
		free(data->connection);
		exit(1);
	}
	write(1, "Key pressed\n", 12);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.connection = mlx_init();
	if (NULL == data.connection)
		return (MLX_ERROR);
	data.window = mlx_new_window(data.connection, \
								WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (NULL == data.window)
	{
		mlx_destroy_display(data.connection);
		free(data.connection);
		return (MLX_ERROR);
	}
	mlx_key_hook(data.window, handle_input, &data);
	mlx_loop(data.connection);
	mlx_destroy_window(data.connection, data.window);
	mlx_destroy_display(data.connection);
	free(data.connection);
}
