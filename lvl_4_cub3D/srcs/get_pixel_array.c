/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:01:40 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/13 14:28:14 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include <stdlib.h>

t_pixel *get_pixel_array(void *mlx_ptr, t_xpm_img *xpm_img)
{
	t_pixel *texture;
	int		y;
	int		x;

	xpm_img->data = (t_pixel *)mlx_get_data_addr(xpm_img->ptr, &xpm_img->bpp, 
		&xpm_img->size_l, &xpm_img->endian);
	texture = malloc(((xpm_img->height * xpm_img->width)) * sizeof(t_pixel));
	y = 0;
	while (y < xpm_img->height)
	{
		x = 0;
		while (x < xpm_img->width)
		{
			texture[(xpm_img->width * y) + x] = xpm_img->data[(xpm_img->width * y) + x];
			x += 1;
		}
		y += 1;
	}
	mlx_destroy_image(mlx_ptr, xpm_img->ptr);
	return (texture);
}
