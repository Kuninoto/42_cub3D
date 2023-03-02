/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 19:52:55 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	quit_cub3d(t_cub3d *this)
{
	destroy(this);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_cub3d *this)
{
	/* if (key == W) {
	}
	if (key == A) {
	}
	if (key == S) {
	}
	if (key == D) {
	}
	else */ if (key == ESC)
		quit_cub3d(this);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_cub3d	this;

	if (!valid_args(argc, argv))
		panic(NULL, NULL);


	// init_cub3d(&this);

	this.mlx_ptr = mlx_init();
	if (!this.mlx_ptr)
		panic(MLX_INIT_ERR, &this);

	this.win_ptr = mlx_new_window(this.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	
	mlx_hook(this.win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, &this);
	mlx_hook(this.win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, &this);

	mlx_loop(this.mlx_ptr);

	destroy(&this);
	return (EXIT_SUCCESS);	
}
