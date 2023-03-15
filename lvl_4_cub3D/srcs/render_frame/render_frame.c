/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:16:53 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/15 19:35:04 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

#define WHITE 0xFFFAFA
#define BLACK 0x000000
#define YELLOW 0xFFFF00
#define MINIMAP_SQUARES_PADDING 4

static void	draw_square(t_img *canva, int x, int y, int color)
{
	size_t	i;
	size_t	j;

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

static void	draw_minimap(t_data *this)
{
	int	x;
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

static void	draw_vertical_line(t_data *this, t_raycaster *rc, int x)
{
	int	y;

	y = -1;
	while (++y < rc->draw_start)
	{
		put_pixel_in_canvas(&this->canvas, x, y,
			create_trgb(256, this->textures.sky_rgb[0],
				this->textures.sky_rgb[1], this->textures.sky_rgb[2]));
	}
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		rc->tex_y = (int)rc->tex_pos & (TEXTURE_HEIGHT - 1);
		rc->tex_pos += rc->step;
		put_pixel_in_canvas(&this->canvas, x, y, get_color(this, rc));
		y += 1;
	}
	y = rc->draw_end;
	while (y < WIN_HEIGHT)
	{
		put_pixel_in_canvas(&this->canvas, x, y,
			create_trgb(256, this->textures.floor_rgb[0],
				this->textures.sky_rgb[1], this->textures.floor_rgb[2]));
		y += 1;
	}
}

void	render_frame(t_data *this)
{
	int			x;
	t_raycaster	rc;

	this->canvas = new_img(this->mlx_ptr);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_rc(this, &rc, x);
		point_rays(this, &rc);
		find_distance_to_wall(this->map, &rc);
		find_wall_height(&rc);
		find_wall_pixel(this, &rc);
		draw_vertical_line(this, &rc, x);
		x += 1;
	}
	draw_minimap(this);
	mlx_clear_window(this->mlx_ptr, this->win_ptr);
	mlx_put_image_to_window(this->mlx_ptr, this->win_ptr,
		this->canvas.ptr, 0, 0);
}
