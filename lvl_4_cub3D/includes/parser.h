/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:36:17 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 20:57:09 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "cub3D.h"

// ERROR MESSAGES -------------------------------------------------

# define INVALID_ARGC "invalid number of arguments"
# define INVALID_MAP_EXT "invalid map file extension"

# define OPEN_SCENE_ERR "failed to open scene's file"
# define INVALID_NBR_OF_ATTRIBUTES "exceeded amount of element attributes"
# define OPEN_TEXTURE_ERR "mlx_xpm_file_to_image() failed to open xpm file"
# define INVALID_RGB_VALUES "invalid RGB values"
# define RGB_OUT_OF_BOUNDS "RGB value out of bounds [0, 255]"
# define EMPTY_SCENE_ERR "scene's file is empty"
# define MAP_HAS_EMPTY_LINES "scene's map has empty lines"

// CONSTANTS ------------------------------------------------------

# define EXTENSION_LEN 4

// n >= lowest && n <= highest
static inline bool	fits_in_intrange(int n, int lowest, int highest) {
	return (n >= lowest && n <= highest);
};

static inline int parser_panic(char *error_msg) {
	ft_putstr_fd("cub3D: error: parser: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	return (0);
};

bool	parse_textures(t_cub3d *this, char **map);
bool	parse_scene(t_cub3d *this, char *file_name);

#endif // PARSER_H