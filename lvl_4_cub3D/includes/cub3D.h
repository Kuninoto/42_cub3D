/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:18:36 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 16:24:58 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# include "events.h"
# include "img.h"
# include "../mlx/mlx.h"

/* ERROR MESSAGES */

# define INVALID_ARGC "invalid number of arguments"
# define INVALID_MAP_EXT "invalid map file extension"

# define OPEN_SCENE_ERR "failed to open scene's file"
# define EMPTY_SCENE_ERR "scene's file is empty"
# define MAP_HAS_EMPTY_LINES "scene's map has empty lines"

# define MLX_INIT_ERR "mlx_init() fail"

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
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**map;
	t_img		canvas;
}				t_cub3d;

static inline void	init_cub3d(t_cub3d *this)
{
	this->mlx_ptr = NULL;
	this->win_ptr = NULL;
	this->textures.north = NULL;
	this->textures.south = NULL;
	this->textures.east = NULL;
	this->textures.west = NULL;
	this->map = NULL;
	this->canvas = init_img();
}

bool	valid_args(int argc, char **argv);

bool	parse_scene(t_cub3d *this, char *file_name);

static inline int parser_panic(char *error_msg) {
	ft_putstr_fd("cub3D: error: parser: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return (0);
};


void	destroy(t_cub3d *this);
void	panic(char *error_msg, t_cub3d *this);
void	put_error(char *error_msg);

#endif // CUB3D_H
