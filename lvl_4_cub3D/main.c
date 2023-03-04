/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/04 19:34:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int	quit_cub3d(t_data *this)
{
	destroy(this);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_keypress(int key, t_data *this)
{
	printf("keypress code = %d\n", key);
	if (key == ESC)
		quit_cub3d(this);
	/* else if (key == W)
		walk_front();
	else if (key == A)
		walk_left();
	else if (key == S)
		walk_back();
	else if (key == D)
		walk_right();
	else if (key == LEFT || key == Q)
		turn_left();
	else if (key == RIGHT || key == E)
		turn_right();
	else if (key == R)
		reload();
	*/
	return (EXIT_SUCCESS);
}

int	on_mousepress(int button, t_data *this)
{
	(void)this;
	printf("mousepress code = %d\n", button);
	/* if (button == LEFT_CLICK)
		shoot();
	else if (button == WHEEL_CLICK)
		stab();
	else if (button == RIGHT_CLICK)
		idk();
	*/
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_data	this;

	if (!valid_args(argc, argv))
		panic(NULL, NULL);
	init_cub3d(&this);
	if (!parse_scene(&this, argv[1]))
		panic(NULL, &this);


	/* this.mlx_ptr = mlx_init();
	if (!this.mlx_ptr)
		panic(MLX_INIT_ERR, &this);

	this.win_ptr = mlx_new_window(this.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");

	mlx_hook(this.win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, &this);
	mlx_hook(this.win_ptr, BUTTONPRESS_EVENT, (1L << 2), on_mousepress, &this);
	mlx_hook(this.win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, &this);

	mlx_loop(this.mlx_ptr); */

	destroy(&this);
	return (EXIT_SUCCESS);	
}
