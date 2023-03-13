/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:39 by roramos           #+#    #+#             */
/*   Updated: 2023/03/13 19:18:58 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

static void	draw_square(t_img *canva, int x, int y, int color)
{
	size_t i;
	size_t j;

	i = MINIMAP_SQUARES_PADDING;
	while (i < 4 + MINIMAP_SQUARES_PADDING)
	{
		j = MINIMAP_SQUARES_PADDING;
		while (j < 4 + MINIMAP_SQUARES_PADDING)
		{
			put_pixel_in_canvas(canva, (x * 8 + i), (y * 8 + j), color);
			j += 1;
		}
		i += 1;
	}
	
}

void	draw_minimap(t_data *this)
{
	int x;
	int	y;
	int	map_length;

	y = 0;
	while (y < this->map_height)
	{
		x = 0;
		map_length = ft_strlen(this->map[y]);
		while (x < map_length)
		{
			if (x == (int)this->player.x && y == (int)this->player.y)
				draw_square(&this->canvas, x, y, YELLOW);
			else if (this->map[y][x] == WALL)
				draw_square(&this->canvas, x, y, WHITE);
			x += 1;
		}
		y += 1;
	}
}
