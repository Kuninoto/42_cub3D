/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 20:56:57 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB3D_H
# define LIBCUB3D_H

# include "libft.h"
# include "parser.h"
# include "math.h"
# include "events.h"
# include "../mlx/mlx.h"
# include "cub3D.h"

/* ERROR MESSAGES */

# define MLX_INIT_ERR "mlx_init() fail"

/* CONSTANTS */

static inline void	init_cub3d(t_cub3d *this)
{
	this->mlx_ptr = mlx_init();
	this->win_ptr = NULL;
	this->textures.north = NULL;
	this->textures.south = NULL;
	this->textures.east = NULL;
	this->textures.west = NULL;
	this->map = NULL;
	this->canvas = init_img();
}

bool	valid_args(int argc, char **argv);

void	destroy(t_cub3d *this);
void	panic(char *error_msg, t_cub3d *this);
void	put_error(char *error_msg);

#endif // LIBCUB3D_H
