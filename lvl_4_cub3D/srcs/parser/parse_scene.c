/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/03 17:46:35 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	get_nbr_lines(char *file_name)
{
	int 	scene_fd;
	size_t	count;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1)
		return (parser_panic(OPEN_SCENE_ERR));
	count = 0;
	line = get_next_line(scene_fd);
	while (line)
	{
		if (!only_spaces(line))
			count += 1;
		free(line);
		line = get_next_line(scene_fd);
	}
	return (count);
}

/* bool	parse_textures(t_cub3d *this, int scene_fd)
{
	
} */

bool	parse_scene(t_cub3d *this, char *file_name)
{
	int 	scene_fd;
	size_t	nbr_lines;
	char 	**map;
	size_t	i;
	char	*line;

	(void)this;

	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1)
		return (parser_panic(OPEN_SCENE_ERR));
	/* if (!parse_textures(this, scene_fd))
		return (false); */

	nbr_lines = get_nbr_lines(file_name);
	if (nbr_lines == 0)
		return (parser_panic(EMPTY_SCENE_ERR));

	map = malloc((nbr_lines + 1) * sizeof(char *));
	i = 0;
	while (i < nbr_lines)
	{
		line = trim_free(get_next_line(scene_fd), "\n");
		if (only_spaces(line))
		{
			free(line);
			/* map[i] = NULL;
			free_matrix(map);
			return (parser_panic(MAP_HAS_EMPTY_LINES)); */
			continue ;
		}
		map[i] = line;
		i += 1;
	}
	map[i] = NULL;

	print_char_matrix(map);
	free_matrix(map);

	return (true);
}
