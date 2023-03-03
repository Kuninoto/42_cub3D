/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:44:02 by roramos           #+#    #+#             */
/*   Updated: 2023/03/03 20:45:40 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "img.h"

typedef struct s_textures {
	int		sky_rgb[3];
	int		floor_rgb[3];	
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}				t_textures;

typedef struct s_cub3d {
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**map;
	t_img		canvas;
}				t_cub3d;

#endif // CUB3D_H