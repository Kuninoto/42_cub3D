/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:53:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/11 23:39:54 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

#ifdef OS_LINUX
	# include "../mlx_linux/mlx.h"
#else
	# include "../mlx_macos/mlx.h"
#endif // OS_LINUX

// WINDOW DIMENSIONS

# define WIN_WIDTH 1280
# define WIN_HEIGHT 920

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/* img represents a canvas to which we'll draw 
	to then put that canvas(img) to the window */

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

static inline t_img	init_img(void) {
	return ((t_img) { .img_ptr = NULL,
					  .addr = NULL,
					  .bits_per_pixel = 0,
					  .line_len = 0,
					  .endian = 0 });
};

static inline t_img	new_img(void *mlx_ptr) {
	t_img	new_img;

	new_img.img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img_ptr, &new_img.bits_per_pixel, &new_img.line_len,
								&new_img.endian);
	return (new_img);
};

static inline void	put_pixel_in_canvas(t_img *img, int x, int y, int color) 
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#endif // IMG_H
