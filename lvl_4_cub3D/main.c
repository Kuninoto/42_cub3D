/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 01:39:56 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

# define WHITE 0xFFFAFA
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define RANDOM_ASS_COLOR 0x0000A3
# define PADDING 4

void	b(t_img *canva, int x, int y, int color)
{
	size_t i;
	size_t j;

	i = PADDING;
	while (i < 4 + PADDING)
	{
		j = PADDING;
		while (j < 4 + PADDING)
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
				b(&this->canvas, x, y, YELLOW);
			else if (this->map[y][x] == WALL)
				b(&this->canvas, x, y, WHITE);
			x += 1;
		}
		y += 1;
	}
}

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
		// calculate ray position and direction
		double 	cameraX = 2 * x / (double)WIN_WIDTH - 1; // x-coordinate in camera space
		double 	rayDirX = this->camera.dir_x + this->camera.plane_x * cameraX;
		double 	rayDirY = this->camera.dir_y + this->camera.plane_y * cameraX;

		// x and y start position
		double		posX = this->player.x;
		double		posY = this->player.y;

		// which box of the map we're in
		int 	mapX = (int)posX;
		int 	mapY = (int)posY;

		// length of ray from current position to next x or y-side
		double 	sideDistX;
		double 	sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double 	perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int 	stepX;
		int 	stepY;

		bool	hit = false; // was there a wall hit?
		bool 	side;	 // was a NS or a EW wall hit?

		// calculate step and initial sideDist
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

		// perform DDA
		while (!hit)
		{
			// jump to next map square, either in x-direction, or in y-direction
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
			// Check if ray has hit a wall
			if (this->map[mapY][mapX] == WALL)
				hit = true;
		}

		if (!side)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;

		// Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

	//	double	step;
		double	wallx;
		int		texx;
	//	double	texpos;

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

	//	step = 1.0 * TEXTURE_HEIGHT / lineHeight;
	//	texpos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		
		uint32_t color;
		for (int y = drawStart; y < drawEnd; y += 1)
      	{
			// int texy = (int)texpos & (TEXTURE_HEIGHT - 1);

    	    // texpos += step;
			// if (!side)
			// {
			// 	if (posX > mapX)
			// 		color = this->textures.north[TEXTURE_HEIGHT * texy + texx];
			// 	else
			// 		color = this->textures.south[TEXTURE_HEIGHT * texy + texx];
			// }
			// else
			// {
			// 	if (posY > mapY)
			// 		color = this->textures.west[TEXTURE_HEIGHT * texy + texx];
			// 	else
			// 		color = this->textures.east[TEXTURE_HEIGHT * texy + texx];
			// }
			color = RANDOM_ASS_COLOR; //create_trgb(100, 255, 255, 255);
			put_pixel_in_canvas(&this->canvas, x, y, color);
		}
		//draw_vertical_line(this, x, drawStart, drawEnd, create_trgb(100,150,30,255));
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
	//mlx_mouse_move(this->mlx_ptr, this->win_ptr, 
	//	(this->camera.dir_x) + sin(this->camera.dir_y), WIN_HEIGHT / 2);
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
	destroy(&this);
	return (EXIT_SUCCESS);	
}