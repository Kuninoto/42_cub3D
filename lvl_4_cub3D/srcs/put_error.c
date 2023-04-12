/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:43:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/04 19:12:35 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ERROR_MSG_PREFIX "cub3D: error: "

void	put_error(char *error_msg)
{
	if (error_msg)
	{	
		ft_putstr_fd(ERROR_MSG_PREFIX, STDERR_FILENO);
		ft_putendl_fd(error_msg, STDERR_FILENO);
	}
}
