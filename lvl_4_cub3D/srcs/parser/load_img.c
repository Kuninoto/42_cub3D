/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:10:48 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 17:37:16 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

bool	load_img(void *mlx_ptr, t_img *tex, char **coord_line)
{
	int	size;

	tex->ptr = mlx_xpm_file_to_image(mlx_ptr, coord_line[1], &size, &size);
	free_matrix(coord_line);
	if (!tex->ptr)
		return (parser_panic(OPEN_TEXTURE_ERR));
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (parser_panic(GET_DATA_ADDR_ERR));
	return (true);
}
