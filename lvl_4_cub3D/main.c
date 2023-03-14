/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 15:58:47 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

void draw_vertical_line(t_data *this, size_t x, size_t drawStart, size_t drawEnd, size_t color)
{
	size_t i;

	i = 0;
	while (i < drawStart)
	{
		put_pixel_in_canvas(&this->canvas, x, i, 
			create_trgb(256, this->textures.sky_rgb[0], this->textures.sky_rgb[1],
			this->textures.sky_rgb[2]));
		i += 1;
	}
	while (i < drawEnd)
	{
		mlx_pixel_put(this->mlx_ptr, this->win_ptr, x, drawStart + i, color);
		i += 1;
	}
	while (i < WIN_HEIGHT)
	{
		put_pixel_in_canvas(&this->canvas, x, i, 
			create_trgb(256, this->textures.floor_rgb[0], this->textures.sky_rgb[1],
			this->textures.floor_rgb[2]));
		i += 1;
	}
}

void a(t_data *this)
{
	this->canvas = new_img(this->mlx_ptr);

	for (int x = 0; x < WIN_WIDTH; x += 1)
	{
		double 	cameraX = 2 * x / (double)WIN_WIDTH - 1;
		double 	rayDirX = this->camera.dir_x + this->camera.plane_x * cameraX;
		double 	rayDirY = this->camera.dir_y + this->camera.plane_y * cameraX;

		double	posX = this->player.x;
		double	posY = this->player.y;

		int 	mapX = (int)posX;
		int 	mapY = (int)posY;

		double 	sideDistX;
		double 	sideDistY;

		double	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      	double	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double 	perpWallDist;

		int 	stepX;
		int 	stepY;

		bool	hit = false;
		bool 	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0f - posX) * deltaDistX;
		}
		if (rayDirY > 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0f - posY) * deltaDistY;
		}

		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = false;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = true;
			}
			if (this->map[mapY][mapX] == WALL)
				hit = true;
		}

		if (!side)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;

		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		double	step;
		double	wallx;
		int		texx;
		double	texpos;

		if (!side)
			wallx = (int)posY + perpWallDist * rayDirY;
		else
			wallx = (int)posX + perpWallDist * rayDirX;
		wallx -= floor(wallx);

		texx = (int)(wallx * (double)TEXTURE_WIDTH);
		if (!side && rayDirX > 0)
			texx = TEXTURE_WIDTH - texx - 1;
		if (side && rayDirY < 0)
			texx = TEXTURE_WIDTH - texx - 1;

		step = 1.0 * TEXTURE_HEIGHT / lineHeight;
		texpos = (drawStart - (WIN_HEIGHT / 2) + lineHeight / 2) * step;
		
		int h2 = 0;
		while (h2 < drawStart)
		{
			put_pixel_in_canvas(&this->canvas, x, h2, 
				create_trgb(256, this->textures.sky_rgb[0], this->textures.sky_rgb[1],
				this->textures.sky_rgb[2]));
			h2 += 1;
		}
		uint32_t color;
		for (int y = drawStart; y < drawEnd; y += 1)
      	{
			int texy = (int)texpos & (TEXTURE_HEIGHT - 1);

    	    texpos += step;
			if (!side)
			{
				if (posX > mapX)
					color = extract_pixel_from_image(&this->textures.north, texx, texy);
				else
					color = extract_pixel_from_image(&this->textures.south, texx, texy);
			}
			else
			{
				if (posY > mapY)
					color = extract_pixel_from_image(&this->textures.west, texx, texy);
				else
					color = extract_pixel_from_image(&this->textures.east, texx, texy);
			}
			put_pixel_in_canvas(&this->canvas, x, y, color);
		}
		h2 = drawEnd;
		while (h2 < WIN_HEIGHT)
		{
			put_pixel_in_canvas(&this->canvas, x, h2, 
				create_trgb(256, this->textures.floor_rgb[0], this->textures.sky_rgb[1],
				this->textures.floor_rgb[2]));
			h2 += 1;
		}
	}
	draw_minimap(this);
	mlx_clear_window(this->mlx_ptr, this->win_ptr);
	mlx_put_image_to_window(this->mlx_ptr, this->win_ptr, this->canvas.ptr, 0, 0);
}

int loop_hooks(t_data *this)
{
	move_player(this);
	a(this);
	mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
	return (EXIT_SUCCESS);
}

void	hooks(t_data *this)
{
	mlx_mouse_move(this->mlx_ptr, this->win_ptr, 
		(this->camera.dir_x) + sin(this->camera.dir_y), WIN_HEIGHT / 2);
	mlx_mouse_hide(this->mlx_ptr, this->win_ptr);
	mlx_hook(this->win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, this);
	mlx_hook(this->win_ptr, KEYRELEASE_EVENT, (1L << 1), on_keyrelease, this);
	mlx_mouse_hook(this->win_ptr, on_mouseclick, this);
	mlx_hook(this->win_ptr, MOTION_NOTIFY, (1L << 6), mouse_handler, this);
	mlx_hook(this->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, this);
	mlx_loop_hook(this->mlx_ptr, loop_hooks, this);
	mlx_loop(this->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_data	this;

	if (!valid_args(argc, argv))
		panic(NULL, NULL);
	init_cub3d(&this);
	if (!parse_scene(&this, argv[1]))
		panic(NULL, &this);
	this.win_ptr = mlx_new_window(this.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D - macaquinho sem calcinhas");
	if (!this.win_ptr)
		panic(WIN_INIT_ERR, &this);
	hooks(&this);
	return (EXIT_SUCCESS);	
}
