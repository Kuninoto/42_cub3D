/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:26:22 by roramos           #+#    #+#             */
/*   Updated: 2023/03/13 19:06:17 by roramos          ###   ########.fr       */
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
	size_t	i;
	char	**temp;
	char	**rgb;
	bool	return_value;

	i = 0;
	return_value = true;
	while (i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(identifier, temp[0]))
		{
			if (matrix_len(temp) != 2)
			{
				free_matrix(temp);
				return (parser_panic(INVALID_NBR_OF_ATTRIBUTES));
			}
			rgb = ft_split(temp[1], ',');
			if (!assign_rgb(rgb_arr, rgb))
				return_value = false;
			free_matrix(rgb);
			free_matrix(temp);
			return (return_value);
		}
		i += 1;
		free_matrix(temp);
	}	
	return (false);
}

static bool	parse_coord(char *coord, void *mlx_ptr, t_img *texture , char **map)
{
	size_t		i;
	char		**temp;
	t_img		tex;
	int			size;

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
			tex.ptr = mlx_xpm_file_to_image(mlx_ptr, temp[1], &size, &size);
			free_matrix(temp);
			if (!tex.ptr)
				return (parser_panic(OPEN_TEXTURE_ERR));
			tex.addr = mlx_get_data_addr(tex.ptr, &tex.bpp,
				&tex.line_len, &tex.endian);
			if (!tex.addr)
				return (parser_panic(GET_DATA_ADDR_ERR));
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
	if (!parse_coord("NO", this->mlx_ptr, &this->textures.north, textures_part))
		return (false);
	if (!parse_coord("SO", this->mlx_ptr, &this->textures.south, textures_part))
		return (false);
	if (!parse_coord("EA", this->mlx_ptr, &this->textures.east, textures_part))
		return (false);
	if (!parse_coord("WE", this->mlx_ptr, &this->textures.west, textures_part))
		return (false);
	if (!parse_rgb("C", this->textures.sky_rgb, textures_part))
		return (false);
	if (!parse_rgb("F", this->textures.floor_rgb, textures_part))
		return (false);
	return (true);
}