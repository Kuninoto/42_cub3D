/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:54:19 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 17:38:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

static void	destroy_textures(t_data *this)
{
	if (this->textures.north.ptr)
		mlx_destroy_image(this->mlx_ptr, this->textures.north.ptr);
	if (this->textures.south.ptr)
		mlx_destroy_image(this->mlx_ptr, this->textures.south.ptr);
	if (this->textures.east.ptr)
		mlx_destroy_image(this->mlx_ptr, this->textures.east.ptr);
	if (this->textures.west.ptr)
		mlx_destroy_image(this->mlx_ptr, this->textures.west.ptr);
}

void	destroy(t_data *this)
{
	if (!this)
		return ;
	destroy_textures(this);
	if (this->canvas.ptr)
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
	if (this->win_ptr)
		mlx_destroy_window(this->mlx_ptr, this->win_ptr);
	if (this->mlx_ptr)
	{
		mlx_destroy_display(this->mlx_ptr);
		free(this->mlx_ptr);
	}
	if (this->map)
		free_matrix(this->map);
}
