/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 19:21:07 by roramos          ###   ########.fr       */
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

# include <stdint.h>
# include <math.h>
# include "data.h"
# include "parser.h"
# include "event_handlers.h"

/* ERROR MESSAGES */

# define MLX_INIT_ERR "mlx_init() failed"
# define WIN_INIT_ERR "mlx_new_window() failed"


/* CONSTANTS */

# define WHITE 0xFFFAFA
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define MINIMAP_SQUARES_PADDING 4

bool	valid_args(int argc, char **argv);

void	panic(char *error_msg, t_data *this);
void	destroy(t_data *this);
void	put_error(char *error_msg);

static inline void	init_cub3d(t_data *this)
{
	this->mlx_ptr = mlx_init();
	if (!this->mlx_ptr)
		panic(MLX_INIT_ERR, this);
	this->win_ptr = NULL;
	this->textures.north.ptr = NULL;
	this->textures.south.ptr = NULL;
	this->textures.east.ptr = NULL;
	this->textures.west.ptr = NULL;
	this->camera.plane_x = 0;
	this->camera.plane_y = 0.66;
	this->camera.dir_x = -1.0f;
	this->camera.dir_y = 0.0f;
	this->wasd_movement[0] = false;
	this->wasd_movement[1] = false;
	this->wasd_movement[2] = false;
	this->wasd_movement[3] = false;
	this->map = NULL;
	this->canvas = init_img();
}

static inline int create_trgb(int t, int r, int g, int b) {
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_minimap(t_data *this);

void 	a(t_data *this);
void 	move_player(t_data *this);

#endif // LIBCUB3D_H