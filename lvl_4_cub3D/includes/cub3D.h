/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 19:24:39 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# include "keys.h"
# include "img.h"
# include "../mlx/mlx.h"

/* ERROR MESSAGES */

# define MLX_INIT_ERR "mlx_init() fail"
# define INVALID_ARGC "invalid number of arguments"
# define INVALID_MAP_EXT "invalid map file extension"

/* CONSTANTS */

# define EXTENSION_LEN 4

typedef struct s_textures {
	int		sky_rgb[3];
	int		floor_rgb[3];	
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}				t_textures;

typedef struct s_cub3d {
	void	*mlx_ptr;
	void	*win_ptr;

	t_img	canvas;
}				t_cub3d;

bool	valid_args(int argc, char **argv);

void	destroy(t_cub3d *this);
void	panic(char *error_msg, t_cub3d *this);
void	put_error(char *error_msg);

#endif // CUB3D_H
