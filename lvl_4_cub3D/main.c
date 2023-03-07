/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/07 23:57:01 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int main(int argc, char **argv)
{
	t_data	this;

	if (!valid_args(argc, argv))
		panic(NULL, NULL);
	init_cub3d(&this);
	if (!parse_scene(&this, argv[1]))
		panic(NULL, &this);
	this.win_ptr = mlx_new_window(this.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!this.win_ptr)
		panic(WIN_INIT_ERR, &this);

	mlx_hook(this.win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, &this);
	mlx_mouse_hook(this.win_ptr, on_mouseclick, &this);
	mlx_hook(this.win_ptr, MOTION_NOTIFY, (1L << 6), mouse_handler, &this);
	mlx_hook(this.win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, &this);

	mlx_put_image_to_window(this.mlx_ptr, this.win_ptr, this.textures.north, 0, 0);
	
	mlx_loop(this.mlx_ptr);

	destroy(&this);
	return (EXIT_SUCCESS);	
}
