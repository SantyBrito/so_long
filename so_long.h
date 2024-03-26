/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:54 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/26 19:19:39 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>

# define MLX_ERROR		1
# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600

typedef struct s_mlx_data
{
	void	*connection;
	void	*window;
}	t_mlx_data;

#endif