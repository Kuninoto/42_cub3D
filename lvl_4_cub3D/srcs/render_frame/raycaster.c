/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:33:11 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/15 19:32:21 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

void	point_rays(t_data *this, t_raycaster *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (this->player.x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0f - this->player.orientation)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y > 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (this->player.y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0f - this->player.y)
			* rc->delta_dist_y;
	}
}

void	find_distance_to_wall(char **map, t_raycaster *rc)
{
	while (!rc->hit)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = false;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = true;
		}
		if (map[rc->map_y][rc->map_x] == WALL)
			rc->hit = true;
	}
}

void	find_wall_height(t_raycaster *rc)
{
	if (!rc->side)
		rc->perp_wall_dist = rc->side_dist_x - rc->delta_dist_x;
	else
		rc->perp_wall_dist = rc->side_dist_y - rc->delta_dist_y;
	rc->line_height = (int)(WIN_HEIGHT / rc->perp_wall_dist);
	rc->draw_start = (-rc->line_height / 2) + (WIN_HEIGHT / 2);
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = (rc->line_height / 2) + (WIN_HEIGHT / 2);
	if (rc->draw_end >= WIN_HEIGHT)
		rc->draw_end = WIN_HEIGHT - 1;
}

void	find_wall_pixel(t_data *this, t_raycaster *rc)
{
	if (!rc->side)
		rc->wall_x = (int)this->player.y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = (int)this->player.x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);
	if (!rc->side && rc->ray_dir_x > 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
	if (rc->side && rc->ray_dir_y < 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
	rc->step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
	rc->tex_pos = (rc->draw_start - (WIN_HEIGHT / 2) + rc->line_height / 2)
		* rc->step;
}
