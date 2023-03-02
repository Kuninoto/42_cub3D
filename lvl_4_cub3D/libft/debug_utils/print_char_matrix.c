/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:11:09 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/25 23:16:13 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		printf("matrix[%ld] = '%s'\n", i, matrix[i]);
		i += 1;
	}
}
