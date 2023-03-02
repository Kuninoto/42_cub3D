/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   represents_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:55:28 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/27 01:49:23 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	represents_float(char *str)
{
	while (*str)
	{
		if (!is_digit(*str) && *str != '.' && *str != '-')
			return (false);
		str += 1;
	}
	return (true);
}
