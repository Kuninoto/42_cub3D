/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:26:19 by roramos           #+#    #+#             */
/*   Updated: 2023/03/15 19:32:37 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <math.h>
# include "data.h"

typedef struct s_raycaster
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}				t_raycaster;

static inline void	init_rc(t_data *this, t_raycaster *rc, int x)
{
	rc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	rc->ray_dir_x = this->camera.dir_x + this->camera.plane_x * rc->camera_x;
	rc->ray_dir_y = this->camera.dir_y + this->camera.plane_y * rc->camera_x;
	rc->map_x = (int)this->player.x;
	rc->map_y = (int)this->player.y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	rc->hit = false;
}

void				point_rays(t_data *this, t_raycaster *rc);
void				find_distance_to_wall(char **map, t_raycaster *rc);
void				find_wall_height(t_raycaster *rc);
void				find_wall_pixel(t_data *this, t_raycaster *rc);

static inline uint32_t	get_color(t_data *this, t_raycaster *rc)
{
	if (!rc->side)
	{
		if (this->player.x > rc->map_x)
			return (extract_pixel_from_image(&this->textures.west,
					rc->tex_x, rc->tex_y));
		return (extract_pixel_from_image(&this->textures.east,
				rc->tex_x, rc->tex_y));
	}
	if (this->player.y > rc->map_y)
		return (extract_pixel_from_image(&this->textures.north,
				rc->tex_x, rc->tex_y));
	return (extract_pixel_from_image(&this->textures.south,
			rc->tex_x, rc->tex_y));
}

void				render_frame(t_data *this);

#endif // RAYCASTER_H