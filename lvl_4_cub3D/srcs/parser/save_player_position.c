/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:30:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/09 12:26:56 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

bool	save_player_position(char **map, t_data *this)
{
	bool	player_found;
	int		i;
	int		j;

	player_found = false;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_onstr(POSSIBLE_PLAYER_CHARS, map[i][j]))
			{
				if (player_found == true)
					return (parser_panic(INVALID_NBR_PLAYER_POSITIONS));
				else
				{
					this->player.x = j;
					this->player.y = i;
					this->player.orientation = map[i][j];
					player_found = true;
				}
			}
			j += 1;
		}
		i += 1;
	}
	if (!player_found)
		return (parser_panic(NO_PLAYER_START_POINT));
	return (true);
}
