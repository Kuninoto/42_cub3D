/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/16 17:31:54 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

int	window_loop(t_data *this)
{
	move_player(this);
	render_frame(this);
	mlx_destroy_image(this->mlx_ptr, this->canvas.ptr);
	this->canvas.ptr = NULL;
	return (EXIT_SUCCESS);
}

//	mlx_mouse_hide(this->mlx_ptr, this->win_ptr);
void	hook_and_run(t_data *this)
{
	mlx_mouse_move(this->mlx_ptr, this->win_ptr,
		cos(this->camera.dir_x) + cos(this->camera.dir_y), (WIN_HEIGHT / 2));
	mlx_hook(this->win_ptr, KEYPRESS_EVENT, (1L << 0), on_keypress, this);
	mlx_hook(this->win_ptr, KEYRELEASE_EVENT, (1L << 1), on_keyrelease, this);
	mlx_hook(this->win_ptr, MOTION_NOTIFY, (1L << 6), mouse_handler, this);
	mlx_hook(this->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_cub3d, this);
	mlx_loop_hook(this->mlx_ptr, window_loop, this);
	mlx_loop(this->mlx_ptr);
}

int	main(int argc, char **argv)
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
	hook_and_run(&this);
	return (EXIT_SUCCESS);
}
