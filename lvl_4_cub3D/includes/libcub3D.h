/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/07 01:39:33 by nnuno-ca         ###   ########.fr       */
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

bool	valid_args(int argc, char **argv);

void	destroy(t_data *this);
void	panic(char *error_msg, t_data *this);
void	put_error(char *error_msg);

static inline void	init_cub3d(t_data *this)
{
	this->mlx_ptr = mlx_init();
	if (!this->mlx_ptr)
		panic(MLX_INIT_ERR, this);
	this->win_ptr = NULL;
	this->textures.north = NULL;
	this->textures.south = NULL;
	this->textures.east = NULL;
	this->textures.west = NULL;
	this->camera.camera_plane_x = 0;
	this->camera.camera_plane_y = 0.66;
	this->camera.direction_x = 0;
	this->camera.direction_y = 0;
	this->map = NULL;
	this->canvas = init_img();
}

#endif // LIBCUB3D_H
