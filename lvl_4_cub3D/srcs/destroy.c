/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:54:19 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/07 16:35:35 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

void	destroy_textures(void *mlx_ptr, t_textures *textures)
{
	if (textures->north)
		mlx_destroy_image(mlx_ptr, textures->north);
	if (textures->south)
		mlx_destroy_image(mlx_ptr, textures->south);
	if (textures->east)
		mlx_destroy_image(mlx_ptr, textures->east);
	if (textures->west)
		mlx_destroy_image(mlx_ptr, textures->west);
}

void	destroy(t_data *this)
{
	if (!this)
		return ;
	destroy_textures(this->mlx_ptr, &this->textures);
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
