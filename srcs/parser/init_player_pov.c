/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:50:20 by roramos           #+#    #+#             */
/*   Updated: 2023/03/14 21:05:17 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	north_pov(t_data *this)
{
	this->camera.plane_x = 0.66;
	this->camera.plane_y = 0;
	this->camera.dir_x = 0.0f;
	this->camera.dir_y = 1.0f;
}

static void	south_pov(t_data *this)
{
	this->camera.plane_x = -0.66;
	this->camera.plane_y = 0;
	this->camera.dir_x = 0.0f;
	this->camera.dir_y = -1.0f;
}

static void	east_pov(t_data *this)
{
	this->camera.plane_x = 0;
	this->camera.plane_y = -0.66;
	this->camera.dir_x = 1.0f;
	this->camera.dir_y = 0.0f;
}

static void	west_pov(t_data *this)
{
	this->camera.plane_x = 0;
	this->camera.plane_y = 0.66;
	this->camera.dir_x = -1.0f;
	this->camera.dir_y = 0.0f;
}

void	init_player_pov(t_data *this)
{
	if (this->player.orientation == NORTH)
		north_pov(this);
	else if (this->player.orientation == SOUTH)
		south_pov(this);
	else if (this->player.orientation == EAST)
		east_pov(this);
	else if (this->player.orientation == WEST)
		west_pov(this);
}
