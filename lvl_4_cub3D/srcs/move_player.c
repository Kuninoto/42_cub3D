/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:50:11 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 18:13:40 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <math.h>

#define MOVESPEED 0.02f
#define MARGIN	0.1f

void	move_up(t_data *this)
{
	if (this->map[(int)(this->player.y)]
		[(int)(this->player.x + this->camera.dir_x * MARGIN)] != WALL)
			this->player.x += this->camera.dir_x * MOVESPEED;
	if (this->map[(int)(this->player.y - this->camera.dir_y * MARGIN)]
		[(int)(this->player.x)] != WALL)
			this->player.y -= this->camera.dir_y * MOVESPEED;
}

void	move_left(t_data *this)
{
	if (this->map[(int)(this->player.y)]
		[(int)(this->player.x - this->camera.dir_y * MARGIN)] != WALL)
		this->player.x -= this->camera.dir_y * MOVESPEED;
	if (this->map[(int)(this->player.y - this->camera.dir_x * MARGIN)]
		[(int)(this->player.x)] != WALL)
			this->player.y -= this->camera.dir_x * MOVESPEED;
}

void	move_down(t_data *this)
{
	if (this->map[(int)(this->player.y)]
		[(int)(this->player.x - this->camera.dir_x * MARGIN)] != WALL)
		this->player.x -= this->camera.dir_x * MOVESPEED;
	if (this->map[(int)(this->player.y + this->camera.dir_y * MARGIN)]
		[(int)(this->player.x)] != WALL)
		this->player.y += this->camera.dir_y * MOVESPEED;
}

void	move_right(t_data *this)
{
	if (this->map[(int)(this->player.y)]
		[(int)(this->player.x + this->camera.dir_y * MARGIN)] != WALL)
		this->player.x += this->camera.dir_y * MOVESPEED;
	if (this->map[(int)(this->player.y + this->camera.dir_x * MARGIN)]
		[(int)(this->player.x)] != WALL)
		this->player.y += this->camera.dir_x * MOVESPEED;
}

void	move_player(t_data *this)
{
	if (this->wasd_movement[0])
		move_up(this);
	if (this->wasd_movement[1])
		move_left(this);
	else if (this->wasd_movement[2])
		move_down(this);
	else if (this->wasd_movement[3])
		move_right(this);
}
