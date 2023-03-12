/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:53:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/12 01:30:18 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

#ifdef OS_LINUX
	# include "../mlx_linux/mlx.h"
#else
	# include "../mlx_macos/mlx.h"
#endif // OS_LINUX

# include <stddef.h>

// WINDOW DIMENSIONS

# define WIN_WIDTH 1280
# define WIN_HEIGHT 920

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef int t_pixel;

/* img represents a canvas to which we'll draw 
	to then put that canvas(img) to the window */

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_xpm_img
{
	void		*ptr;
	t_pixel		*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_xpm_img;

static inline t_img	init_img(void) {
	return ((t_img) { .ptr = NULL,
					  .addr = NULL,
					  .bits_per_pixel = 0,
					  .line_len = 0,
					  .endian = 0 });
};

static inline t_img	new_img(void *mlx_ptr) {
	t_img	new_img;

	new_img.ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.ptr, &new_img.bits_per_pixel, &new_img.line_len,
								&new_img.endian);
	return (new_img);
};

static inline void	put_pixel_in_canvas(t_img *img, int x, int y, int color) 
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_pixel *get_pixel_array(void *mlx_ptr, t_xpm_img *xpm_img);

#endif // IMG_H
