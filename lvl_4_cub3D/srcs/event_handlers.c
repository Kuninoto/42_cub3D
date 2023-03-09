/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/09 12:46:43 by nnuno-ca         ###   ########.fr       */
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
	double	movespeed = 1.5f;
	double	rotspeed = 2.0f;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = this->camera.direction_x;
	old_plane_x = this->camera.camera_plane_x;

	printf("keypress code = %d\n", key);
	if (key == ESC)
		quit_cub3d(this);
	else if (key == W || key == UP)
	{
		mlx_clear_window(this->mlx_ptr, this->win_ptr);
		if (!this->map[(int)(this->player.y + this->camera.direction_y * movespeed)][(int)(this->player.x)])
			this->player.x += this->camera.direction_x * movespeed;
		if (!this->map[(int)(this->player.y)][(int)(this->player.x + this->camera.direction_x * movespeed)])
			this->player.y += this->camera.direction_y * movespeed;
		a(this);
	}
	else if (key == A || key == LEFT)
	{
		mlx_clear_window(this->mlx_ptr, this->win_ptr);
		this->camera.direction_x = this->camera.direction_x * cos(rotspeed) - this->camera.direction_y * sin(rotspeed);
		this->camera.direction_y = old_dir_x * sin(rotspeed) + this->camera.direction_y * cos(rotspeed);
		this->camera.camera_plane_x = this->camera.camera_plane_x * cos(rotspeed) - this->camera.camera_plane_y * sin(rotspeed);
		this->camera.camera_plane_y = old_plane_x * sin(rotspeed) + this->camera.camera_plane_y * cos(rotspeed);
		a(this);
	}
	else if (key == S || key == DOWN)
	{
		mlx_clear_window(this->mlx_ptr, this->win_ptr);
		if (!this->map[(int)(this->player.y - this->camera.direction_y * movespeed)][(int)(this->player.y)])
			this->player.x -= this->camera.direction_x * movespeed;
		if (!this->map[(int)(this->player.y)][(int)(this->player.x - this->camera.direction_x * movespeed)])
			this->player.y -= this->camera.direction_y * movespeed;
		a(this);
	}
	else if (key == D || key == RIGHT)
	{
		mlx_clear_window(this->mlx_ptr, this->win_ptr);
		this->camera.direction_x = this->camera.direction_x * cos(-rotspeed) - this->camera.direction_y * sin(-rotspeed);
		this->camera.direction_y = old_dir_x * sin(-rotspeed) + this->camera.direction_y * cos(-rotspeed);
		this->camera.camera_plane_x = this->camera.camera_plane_x * cos(-rotspeed) - this->camera.camera_plane_y * sin(-rotspeed);
		this->camera.camera_plane_y = old_plane_x * sin(-rotspeed) + this->camera.camera_plane_y * cos(-rotspeed);
		a(this);
	}
	/* else if (key == R)
		reload(); */
	return (EXIT_SUCCESS);
}

int	on_mouseclick(int button, int x, int y, t_data *this)
{	
	(void)this;
	printf("mousepress code = %d\n", button);
	printf("Mouse Position\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
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

	double oldDirX = this->camera.direction_x;
	
	this->camera.direction_x = this->camera.direction_x * cos(-4) - this->camera.direction_y * sin(-4);
	this->camera.direction_y = oldDirX * sin(-4) + this->camera.direction_y * cos(-4);
	
	double oldPlaneX = this->camera.camera_plane_x;

	this->camera.camera_plane_x = this->camera.camera_plane_x * cos(-4) - this->camera.camera_plane_y * sin(-4);
	this->camera.camera_plane_y = oldPlaneX * sin(-4) + this->camera.camera_plane_y * cos(-4);

// a(this);
	/* if (button == LEFT_CLICK)
		shoot();
	else if (button == WHEEL_CLICK)
		stab();
	else if (button == RIGHT_CLICK)
		idk();
	*/
	return (EXIT_SUCCESS);
}
