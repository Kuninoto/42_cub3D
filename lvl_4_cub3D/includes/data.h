/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:34:03 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/09 12:24:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "img.h"

typedef struct s_textures {
	int		sky_rgb[3];
	int		floor_rgb[3];	
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}				t_textures;

typedef struct s_player {
	double	x;
	double	y;
	char	orientation;
}				t_player;

typedef struct s_camera
{
	double direction_x;
	double direction_y;
	double camera_plane_x;
	double camera_plane_y;

} 				t_camera;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**map;
	t_img		canvas;
	t_player	player;
	t_camera	camera;
} t_data;

#endif // DATA_H