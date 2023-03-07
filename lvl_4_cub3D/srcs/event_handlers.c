/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:16:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/06 16:30:41 by nnuno-ca         ###   ########.fr       */
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

int	on_mouseclick(int button, int x, int y, t_data *this)
{
	(void)this;
	printf("mousepress code = %d\n", button);
	printf("Mouse Position\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	/* if (button == LEFT_CLICK)
		shoot();
	else if (button == WHEEL_CLICK)
		stab();
	else if (button == RIGHT_CLICK)
		idk();
	*/
	return (EXIT_SUCCESS);
}

int	mouse_handler(int x, int y, t_data *this)
{
	(void)this;
	printf("Mouse Position\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	/* if (button == LEFT_CLICK)
		shoot();
	else if (button == WHEEL_CLICK)
		stab();
	else if (button == RIGHT_CLICK)
		idk();
	*/
	return (EXIT_SUCCESS);
}
