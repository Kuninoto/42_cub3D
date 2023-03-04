/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:36:17 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/04 19:35:08 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "data.h"

// ERROR MESSAGES -------------------------------------------------

# define INVALID_ARGC "invalid number of arguments"
# define INVALID_MAP_EXT "invalid map file extension"

# define OPEN_SCENE_ERR "failed to open scene file"
# define OPEN_TEXTURE_ERR "failed to open xpm file"
# define INVALID_NBR_OF_ATTRIBUTES "exceeded amount of element attributes"
# define INVALID_RGB_VALUES "invalid RGB values"
# define RGB_OUT_OF_BOUNDS "RGB value out of bounds [0, 255]"
# define EMPTY_SCENE_ERR "scene's file is empty"
# define MAP_HAS_EMPTY_LINES "scene's map has empty lines"
# define NOT_SURROUNDED_BY_WALLS "scene's map is not surrounded by walls ('1')"
# define INVALID_MAP_COMPOSURE "scene's map is wrongly composed"
# define VALID_INSIDE_MAP "0NSEW"
# define VALID_ELEMENT_SURROUNDING "01NSEW"

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

bool	parse_map(char **map_part);
bool	parse_textures(t_data *this, char **map);
bool	parse_scene(t_data *this, char *file_name);

#endif // PARSER_H