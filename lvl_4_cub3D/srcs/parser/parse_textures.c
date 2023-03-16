/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:26:22 by roramos           #+#    #+#             */
/*   Updated: 2023/03/16 17:31:09 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	assign_rgb(int *element_rgb, char **rgb)
{
	size_t	i;

	i = 0;
	if (matrix_len(rgb) != 3)
		return (parser_panic(INVALID_RGB_VALUES));
	while (rgb[i])
	{
		if (!is_all_digits(rgb[i]))
			return (parser_panic(INVALID_RGB_VALUES));
		element_rgb[i] = ft_atoi(rgb[i]);
		if (!fits_in_intrange(element_rgb[i], 0, 255))
			return (parser_panic(RGB_OUT_OF_BOUNDS));
		i += 1;
	}
	return (true);
}

static bool	parse_rgb(char *identifier, int *rgb_arr, char **map)
{
	int		i;
	bool	return_value;
	char	**temp;
	char	**rgb;

	i = -1;
	return_value = true;
	while (++i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(identifier, temp[0]))
		{
			if (matrix_len(temp) != 2)
				return_value = parser_panic(INVALID_NBR_OF_ATTRIBUTES);
			rgb = ft_split(temp[1], ',');
			if (return_value == true && !assign_rgb(rgb_arr, rgb))
				return_value = false;
			free_matrix(rgb);
			free_matrix(temp);
			return (return_value);
		}
		free_matrix(temp);
	}	
	return (parser_panic(MANDATORY_SCENE_ELEMENT_MISSING));
}

static bool	parse_coord(char *coord, void *mlx_ptr, t_img *texture, char **map)
{
	size_t		i;
	char		**temp;
	t_img		tex;

	i = 0;
	while (i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(coord, temp[0]))
		{
			if (matrix_len(temp) != 2)
			{
				free_matrix(temp);
				return (parser_panic(INVALID_NBR_OF_ATTRIBUTES));
			}
			if (!load_img(mlx_ptr, &tex, temp))
				return (false);
			*texture = tex;
			return (true);
		}
		i += 1;
		free_matrix(temp);
	}	
	return (false);
}

bool	parse_textures(t_data *this, char **textures_part)
{
	bool	return_value;

	return_value = false;
	if (parse_coord("NO", this->mlx_ptr,
			&this->textures.north, textures_part)
		&& parse_coord("SO", this->mlx_ptr,
			&this->textures.south, textures_part)
		&& parse_coord("EA", this->mlx_ptr,
			&this->textures.east, textures_part)
		&& parse_coord("WE", this->mlx_ptr,
			&this->textures.west, textures_part)
		&& parse_rgb("C", this->textures.sky_rgb, textures_part)
		&& parse_rgb("F", this->textures.floor_rgb, textures_part))
		return_value = true;
	free_matrix(textures_part);
	return (return_value);
}
