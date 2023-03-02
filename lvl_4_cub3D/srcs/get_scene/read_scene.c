/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 22:21:15 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	read_scene(t_cub3d *this, char *file_name)
{
	int 	scene_fd;
	char 	**scene;
	size_t	i;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1)
		return (parser_panic("OPEN_FILE_ERR"));
	scene = malloc((get_nbr_lines_of_map(file_name) + 1) * sizeof(char *));
}
