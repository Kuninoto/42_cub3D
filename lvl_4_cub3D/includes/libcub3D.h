/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/07 20:21:16 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB3D_H
# define LIBCUB3D_H

# include "libft.h"

#ifdef OS_LINUX
	# include "../mlx_linux/mlx.h"
#else
	# include "../mlx_macos/mlx.h"
#endif // OS_LINUX

# include "math.h"
# include "data.h"
# include "parser.h"
# include "event_handlers.h"

/* ERROR MESSAGES */

# define MLX_INIT_ERR "mlx_init() failed"
# define WIN_INIT_ERR "mlx_new_window() failed"

/* CONSTANTS */

// FOV [0, 0.66]

# define PLANE_X 0.0f
# define PLANE_Y 0.66f

bool	valid_args(int argc, char **argv);

void	destroy(t_data *this);
void	panic(char *error_msg, t_data *this);
void	put_error(char *error_msg);


static inline void	init_cub3d(t_data *this)
{
	this->mlx_ptr = mlx_init();
	if (!this->mlx_ptr)
		panic(MLX_INIT_ERR, NULL);
	this->win_ptr = NULL;
	this->textures.north = NULL;
	this->textures.south = NULL;
	this->textures.east = NULL;
	this->textures.west = NULL;
	this->map = NULL;
	this->canvas = init_img();
	this->player.position.x = 0;
	this->player.position.y = 0;
	this->player.orientation = 0;
	this->direction.x = -1;
	this->direction.y = 0;
}

#endif // LIBCUB3D_H
