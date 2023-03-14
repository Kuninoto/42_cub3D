/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 21:37:40 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

void	render_frame(t_data *this)
{
	int			x;
	t_raycaster	rc;

	this->canvas = new_img(this->mlx_ptr);
	x = 0;
	while (x < WIN_WIDTH)
	{
		rc.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		rc.ray_dir_x = this->camera.dir_x + this->camera.plane_x * rc.camera_x;
		rc.ray_dir_y = this->camera.dir_y + this->camera.plane_y * rc.camera_x;

		int 	mapX = (int)this->player.x;
		int 	mapY = (int)this->player.y;

		double 	sideDistX;
		double 	sideDistY;

		rc.delta_dist_x = fabs(1 / rc.ray_dir_x);
      	rc.delta_dist_y = fabs(1 / rc.ray_dir_y);

		double 	perpWallDist;

		int 	stepX;
		int 	stepY;

		bool	hit = false;
		bool 	side;

		if (rc.ray_dir_x < 0)
		{
			stepX = -1;
			sideDistX = (this->player.x - mapX) * rc.delta_dist_x;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0f - this->player.x) * rc.delta_dist_x;
		}
		if (rc.ray_dir_y > 0)
		{
			stepY = -1;
			sideDistY = (this->player.y - mapY) * rc.delta_dist_y;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0f - this->player.y) * rc.delta_dist_y;
		}

		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += rc.delta_dist_x;
				mapX += stepX;
				side = false;
			}
			else
			{
				sideDistY += rc.delta_dist_y;
				mapY += stepY;
				side = true;
			}
			if (this->map[mapY][mapX] == WALL)
				hit = true;
		}

		if (!side)
			perpWallDist = sideDistX - rc.delta_dist_x;
		else
			perpWallDist = sideDistY - rc.delta_dist_y;

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
			wallx = (int)this->player.y + perpWallDist * rc.ray_dir_y;
		else
			wallx = (int)this->player.x + perpWallDist * rc.ray_dir_x;
		wallx -= floor(wallx);

		texx = (int)(wallx * (double)TEXTURE_WIDTH);
		if (!side && rc.ray_dir_x > 0)
			texx = TEXTURE_WIDTH - texx - 1;
		if (side && rc.ray_dir_y < 0)
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
				if (this->player.x > mapX)
					color = extract_pixel_from_image(&this->textures.west, texx, texy);
				else
					color = extract_pixel_from_image(&this->textures.east, texx, texy);
			}
			else
			{
				if (this->player.y > mapY)
					color = extract_pixel_from_image(&this->textures.north, texx, texy);
				else
					color = extract_pixel_from_image(&this->textures.south, texx, texy);
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
		x += 1;
	}
	mlx_clear_window(this->mlx_ptr, this->win_ptr);
	mlx_put_image_to_window(this->mlx_ptr, this->win_ptr, this->canvas.ptr, 0, 0);
}

int window_loop(t_data *this)
{
	move_player(this);
	render_frame(this);
	draw_minimap(this);
	mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
	this->canvas.ptr = NULL;
	return (EXIT_SUCCESS);
}

void	hooks(t_data *this)
{
	mlx_mouse_hide(this->mlx_ptr, this->win_ptr);
	mlx_mouse_move(this->mlx_ptr, this->win_ptr, cos(this->camera.dir_x) + cos(this->camera.dir_y), (WIN_HEIGHT / 2));
	mlx_hook(this->win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, this);
	mlx_hook(this->win_ptr, KEYRELEASE_EVENT, (1L << 1), on_keyrelease, this);
	mlx_hook(this->win_ptr, MOTION_NOTIFY, (1L << 6), mouse_handler, this);
	mlx_hook(this->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, this);
	mlx_loop_hook(this->mlx_ptr, window_loop, this);
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
