/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:59:04 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/25 22:23:14 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int_array(int *array, size_t len)
{
	size_t	i;

	printf("array = ");
	i = 0;
	while (i < len)
	{
		printf("'%d' ", array[i]);
		i += 1;
	}
	printf("\n");
}
