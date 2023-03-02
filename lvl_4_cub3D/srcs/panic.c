/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:32:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 18:43:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	panic(char *error_msg, t_cub3d *this)
{
	if (this)
		destroy(this);
	put_error(error_msg);
	exit(EXIT_FAILURE);
}
