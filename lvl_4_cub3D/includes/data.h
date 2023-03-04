/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:34:03 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/04 19:34:04 by nnuno-ca         ###   ########.fr       */
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

typedef struct s_coords {
	size_t	x;
	size_t	y;
}				t_coords;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**map;
	t_img		canvas;
	t_coords	player;
}				t_data;

#endif // DATA_H