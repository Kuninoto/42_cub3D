/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:29:10 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 20:48:45 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3D.h"

static inline int arg_error(char *error_msg) {
	put_error(error_msg);
	return (0);
}

bool	valid_args(int argc, char **argv)
{
	size_t	idx;

	if (argc != 2)
		return (arg_error(INVALID_ARGC));
	idx = ft_strlen(argv[1]) - EXTENSION_LEN;
	if (!streq(&argv[1][idx], ".cub"))
		return (arg_error(INVALID_MAP_EXT));
	return (true);
}
