/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:09:06 by roramos           #+#    #+#             */
/*   Updated: 2023/03/14 18:29:07 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Returns the last idx of a line (excludes spaces)
static size_t	get_line_last_idx(char *map_line)
{
	size_t	i;

	i = ft_strlen(map_line) - 1;
	while (is_spaces(map_line[i]))
		i -= 1;
	i += 1;
	return (i);
}

static bool	valid_surroundings(char **map_part, size_t i, size_t j)
{
	return (is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i - 1][j - 1])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i - 1][j])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i - 1][j + 1])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i][j - 1])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i][j + 1])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i + 1][j - 1])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i + 1][j])
				&& is_onstr(VALID_ELEMENT_SURROUNDING, map_part[i + 1][j + 1]));
}

static bool	valid_content(char **map_part)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map_part[i + 1])
	{
		j = 1;
		while (map_part[i][j] && j < get_line_last_idx(map_part[i - 1])
			&& j < get_line_last_idx(map_part[i + 1]))
		{
			if (is_onstr(VALID_INSIDE_MAP, map_part[i][j])
				&& !valid_surroundings(map_part, i, j))
				return (parser_panic(INVALID_MAP_COMPOSURE));
			j += 1;
		}
		while (map_part[i][j])
		{
			if (map_part[i][j] != '1')
				return (parser_panic(INVALID_MAP_COMPOSURE));
			j += 1;
		}
		i += 1;
	}
	return (true);
}

static bool	has_walls(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[0][++j])
		if (!is_onstr(" 1", map[0][j]))
			return (parser_panic(NOT_SURROUNDED_BY_WALLS));
	j = -1;
	i = matrix_len(map) - 1;
	while (map[i][++j])
		if (!is_onstr(" 1", map[i][j]))
			return (parser_panic(NOT_SURROUNDED_BY_WALLS));
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (is_spaces(map[i][j]))
			j += 1;
		if (map[i][j] != '1')
			return (parser_panic(NOT_SURROUNDED_BY_WALLS));
		j = get_line_last_idx(map[i]) - 1;
		if (map[i][j] != '1')
			return (parser_panic(NOT_SURROUNDED_BY_WALLS));
	}
	return (true);
}

bool	parse_map(char **map_part, t_data *this)
{
	if (!has_walls(map_part) || !valid_content(map_part)
		|| !save_player_info(map_part, this))
		return (false);
	init_player_pov(this);
	this->map_height = matrix_len(map_part);
	return (true);
}
