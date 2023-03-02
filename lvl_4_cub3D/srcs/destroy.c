/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:54:19 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 18:55:50 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy(t_cub3d *this)
{
	if (!this)
		return ;

	// free_textures
	
	if (this->win_ptr)
		mlx_destroy_window(this->mlx_ptr, this->win_ptr);
	if (this->mlx_ptr)
	{
		mlx_destroy_display(this->mlx_ptr);
		free(this->mlx_ptr);
	}
}