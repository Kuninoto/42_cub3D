/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:54:19 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/12 01:31:23 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

static void	destroy_textures(t_textures *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->east)
		free(textures->east);
	if (textures->west)
		free(textures->west);
}

void	destroy(t_data *this)
{
	if (!this)
		return ;
	destroy_textures(&this->textures);
	if (this->canvas.ptr)
		mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
	if (this->win_ptr)
		mlx_destroy_window(this->mlx_ptr, this->win_ptr);
	if (this->mlx_ptr)
	{
		//mlx_destroy_display(this->mlx_ptr);
		free(this->mlx_ptr);
	}
	if (this->map)
		free_matrix(this->map);
}
