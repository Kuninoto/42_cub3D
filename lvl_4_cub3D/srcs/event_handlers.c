/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 18:28:50 by nnuno-ca         ###   ########.fr       */
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

int	on_keyrelease(int key, t_data *this)
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

bool	assert_window_boundaries(t_data *this, int x,
	int y, double *old_x)
{
	if (y != WIN_HEIGHT / 2)
		mlx_mouse_move(this->mlx_ptr, this->win_ptr, x, WIN_HEIGHT / 2);
	if (x <= 50 || x >= WIN_WIDTH - 50)
	{
		*old_x = WIN_WIDTH / 2;
		mlx_mouse_move(this->mlx_ptr, this->win_ptr, WIN_WIDTH / 2, y);
		return (true);
	}
	return (false);
}

int	mouse_handler(int x, int y, t_data *this)
{
	double			old_dir_x;
	double			old_plane_x;
	double			distance;
	static double	old_x = 0;

	old_dir_x = this->camera.dir_x;
	old_plane_x = this->camera.plane_x;
	if (assert_window_boundaries(this, x, y, &old_x))
	return (EXIT_SUCCESS);
	distance = (old_x - x) * 0.002;
	old_x = x;
	this->camera.dir_x = this->camera.dir_x * cos(distance)
		- this->camera.dir_y * sin(distance);
	this->camera.dir_y = old_dir_x * sin(distance)
		+ this->camera.dir_y * cos(distance);
	this->camera.plane_x = this->camera.plane_x * cos(distance)
		- this->camera.plane_y * sin(distance);
	this->camera.plane_y = old_plane_x * sin(distance)
		+ this->camera.plane_y * cos(distance);
	return (EXIT_SUCCESS);
}
