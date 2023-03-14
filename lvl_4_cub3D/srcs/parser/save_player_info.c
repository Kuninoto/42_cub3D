/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:30:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 17:01:40 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// NORM

static void	set_player_info(t_player *player_info, int player_x, int player_y,
		char orientation)
{
	player_info->x = (double)player_x + 0.5;
	player_info->y = (double)player_y + 0.5;
	player_info->orientation = orientation;
}

static bool	has_valid_player(bool player_found)
{
	if (!player_found)
		return (parser_panic(NO_PLAYER_START_POINT));
	return (true);
}	

bool	save_player_info(char **map, t_data *this)
{
	bool	player_found;
	int		i;
	int		j;

	player_found = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_onstr(POSSIBLE_PLAYER_CHARS, map[i][j]))
			{
				if (player_found == true)
					return (parser_panic(INVALID_NBR_PLAYER_POSITIONS));
				else
				{
					set_player_info(&this->player, j, i, map[i][j]);
					player_found = true;
				}
			}
		}
	}
	return (has_valid_player(player_found));
}
