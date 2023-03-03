/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:32:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 20:49:11 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

void	panic(char *error_msg, t_cub3d *this)
{
	if (this)
		destroy(this);
	put_error(error_msg);
	exit(EXIT_FAILURE);
}
