/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 18:37:56 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int	quit_cub3d(t_data *this)
{
	destroy(this);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int on_keypress(int key, t_data *this)
{
	if (key == ESC)
		quit_cub3d(this);
	if (key == W || key == UP)
		this->wasd_movement[0] = true;
	if (key == A || key == LEFT)
		this->wasd_movement[1] = true;
	if (key == S || key == DOWN)
		this->wasd_movement[2] = true;
	if (key == D || key == RIGHT)
		this->wasd_movement[3] = true;
	return (EXIT_SUCCESS);
}

int on_keyrelease(int key, t_data *this)
{
	if (key == W || key == UP)
		this->wasd_movement[0] = false;
	if (key == A || key == LEFT)
		this->wasd_movement[1] = false;
	if (key == S || key == DOWN)
		this->wasd_movement[2] = false;
	if (key == D || key == RIGHT)
		this->wasd_movement[3] = false;
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
	(void)y;

	static double old_x = 0;

	double old_dir_x;
	double old_plane_x;

	if (x <= 25 || x >= WIN_WIDTH - 25)
	{
		mlx_mouse_move(this->mlx_ptr, this->win_ptr, WIN_WIDTH / 2, y);
		old_x = WIN_WIDTH / 2;
	}

	old_dir_x = this->camera.dir_x;
	old_plane_x = this->camera.plane_x;

	double distance = (old_x - x) * 0.003;
	old_x = x;

	this->camera.dir_x = this->camera.dir_x * cos(distance) - this->camera.dir_y * sin(distance);
	this->camera.dir_y = old_dir_x * sin(distance) + this->camera.dir_y * cos(distance);
	this->camera.plane_x = this->camera.plane_x * cos(distance) - this->camera.plane_y * sin(distance);
	this->camera.plane_y = old_plane_x * sin(distance) + this->camera.plane_y * cos(distance);

	return (EXIT_SUCCESS);
}
