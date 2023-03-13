/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:34:03 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 18:56:10 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "img.h"
# include <stdbool.h>

# define WALL '1'
# define OPEN_SPACE '0'

typedef struct s_textures
{
	int		sky_rgb[3];
	int		floor_rgb[3];	
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}				t_textures;

typedef struct s_player
{
	double	x;
	double	y;
	char	orientation;
}				t_player;

typedef struct s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} 				t_camera;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**map;
	int			map_height;
	t_img		canvas;
	t_player	player;
	t_camera	camera;
	bool		wasd_movement[4];
} 				t_data;

#endif // DATA_H