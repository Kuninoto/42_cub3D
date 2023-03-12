/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/12 01:44:14 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int	quit_cub3d(t_data *this)
{
	destroy(this);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_keypress(int key, t_data *this)
{
	double	movespeed = 1.0f;
	double	rotspeed = 2.0f;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = this->camera.dir_x;
	old_plane_x = this->camera.plane_x;

	if (key == ESC)
		quit_cub3d(this);
	else if (key == W || key == UP)
	{
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
		if (this->map[(int)(this->player.y + this->camera.dir_y * movespeed)][(int)(this->player.x)] == OPEN_SPACE)
			this->player.x += this->camera.dir_x * movespeed;
		if (this->map[(int)(this->player.y)][(int)(this->player.x + this->camera.dir_x * movespeed)] == OPEN_SPACE)
			this->player.y += this->camera.dir_y * movespeed;
		a(this);
	}
	else if (key == A || key == LEFT)
	{
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
		this->camera.dir_x = this->camera.dir_x * cos(rotspeed) - this->camera.dir_y * sin(rotspeed);
		this->camera.dir_y = old_dir_x * sin(rotspeed) + this->camera.dir_y * cos(rotspeed);
		this->camera.plane_x = this->camera.plane_x * cos(rotspeed) - this->camera.plane_y * sin(rotspeed);
		this->camera.plane_y = old_plane_x * sin(rotspeed) + this->camera.plane_y * cos(rotspeed);
		a(this);
	}
	else if (key == S || key == DOWN)
	{
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
		if (this->map[(int)(this->player.y - this->camera.dir_y * movespeed)][(int)(this->player.y)] == OPEN_SPACE)
			this->player.x -= this->camera.dir_x * movespeed;
		if (this->map[(int)(this->player.y)][(int)(this->player.x - this->camera.dir_x * movespeed)] == OPEN_SPACE)
			this->player.y -= this->camera.dir_y * movespeed;
		a(this);
	}
	else if (key == D || key == RIGHT)
	{
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
		this->camera.dir_x = this->camera.dir_x * cos(-rotspeed) - this->camera.dir_y * sin(-rotspeed);
		this->camera.dir_y = old_dir_x * sin(-rotspeed) + this->camera.dir_y * cos(-rotspeed);
		this->camera.plane_x = this->camera.plane_x * cos(-rotspeed) - this->camera.plane_y * sin(-rotspeed);
		this->camera.plane_y = old_plane_x * sin(-rotspeed) + this->camera.plane_y * cos(-rotspeed);
		a(this);
	}
	/* else if (key == R)
		reload(); */
	return (EXIT_SUCCESS);
}

int	on_mouseclick(int button, int x, int y, t_data *this)
{	
	(void)x;
	(void)y;
	(void)this;
	printf("mousepress code = %d\n", button);

	/* if (button == LEFT_CLICK)
		shoot();
	else if (button == WHEEL_CLICK)
		stab();
	else if (button == RIGHT_CLICK)
		idk();
	*/
	return (EXIT_SUCCESS);
}

int	mouse_handler(int x, int y, t_data *this)
{
	(void)this;
	printf("Mouse Position\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);

	return (EXIT_SUCCESS);
}
