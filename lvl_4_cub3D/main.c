/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/06 16:33:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void verLine(t_data *this, size_t x, size_t drawStart, size_t drawEnd, size_t color)
{
	size_t i;

	i = 0;
	while (drawStart + i < drawEnd)
	{
		mlx_pixel_put(this->mlx_ptr, this->win_ptr, x, drawStart + i, color);
		i += 1;
	}
}

int a(void *param)
{
	t_data *this = param;
	double posX = this->player.x, posY = this->player.y;	  // x and y start position

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		// calculate ray position and direction
		double cameraX = 2 * x / ((double)WIN_WIDTH) - 1; // x-coordinate in camera space
		double rayDirX = this->camera.direction_x + this->camera.camera_plane_x * cameraX;
		double rayDirY = this->camera.direction_y + this->camera.camera_plane_y * cameraX;

		// which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;
		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double perpWallDist;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;	 // was a NS or a EW wall hit?


		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
		if (this->map[mapY][mapX] != '0')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		// Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT/ 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT- 1;

		verLine(this, x, drawStart, drawEnd, create_trgb(100,255,255,255));
	}
	mlx_clear_window(this->mlx_ptr, this->win_ptr);
	return 0;
}

int main(int argc, char **argv)
{
	t_data	this;

	if (!valid_args(argc, argv))
		panic(NULL, NULL);
	init_cub3d(&this);
	if (!parse_scene(&this, argv[1]))
		panic(NULL, &this);
	this.win_ptr = mlx_new_window(this.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!this.win_ptr)
		panic(WIN_INIT_ERR, &this);

	mlx_hook(this.win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, &this);
	mlx_mouse_hook(this.win_ptr, on_mouseclick, &this);
	mlx_hook(this.win_ptr, MOTION_NOTIFY, (1L << 6), mouse_handler, &this);
	mlx_hook(this.win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, &this);
	mlx_loop_hook(this.mlx_ptr, a, &this);

	mlx_loop(this.mlx_ptr);

	destroy(&this);
	return (EXIT_SUCCESS);	
}
