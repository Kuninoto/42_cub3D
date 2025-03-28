/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 21:10:14 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	get_nbr_map_lines(char *file_name)
{
	int		scene_fd;
	size_t	i;
	size_t	count;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	i = 0;
	count = 0;
	line = get_next_line(scene_fd);
	while (i < 6)
	{
		free(line);
		line = get_next_line(scene_fd);
		if (!only_spaces(line))
			i += 1;
	}
	while (line)
	{
		if (!only_spaces(line))
			count += 1;
		free(line);
		line = get_next_line(scene_fd);
	}
	close(scene_fd);
	return (count);
}

static char	**get_textures_part(int scene_fd)
{
	char	**scene;
	size_t	i;
	char	*line;

	scene = malloc((6 + 1) * sizeof(char *));
	i = 0;
	while (i < 6)
	{
		line = trim_free(get_next_line(scene_fd), "\n");
		if (only_spaces(line))
		{
			free(line);
			continue ;
		}
		scene[i] = line;
		i += 1;
	}
	scene[i] = NULL;
	free(get_next_line(scene_fd));
	return (scene);
}

static char	**get_map_part(char *file_name, int scene_fd)
{
	size_t	i;
	size_t	nbr_lines;
	char	**map;
	char	*line;

	nbr_lines = get_nbr_map_lines(file_name);
	map = malloc((nbr_lines + 1) * sizeof(char *));
	i = 0;
	while (i < nbr_lines)
	{
		line = trim_free(get_next_line(scene_fd), "\n");
		map[i] = line;
		i += 1;
	}
	map[i] = NULL;
	return (map);
}

static bool	is_scene_empty(char *file_name)
{
	bool	return_value;
	char	*temp;
	int		scene_fd;

	return_value = false;
	scene_fd = open(file_name, O_RDONLY);
	if (!scene_fd)
		return (parser_panic(OPEN_SCENE_ERR));
	temp = get_next_line(scene_fd);
	if (temp == NULL)
		return_value = true;
	free(temp);
	close(scene_fd);
	return (return_value);
}

bool	parse_scene(t_data *this, char *file_name)
{
	bool	return_value;
	int		scene_fd;
	char	**textures_part;
	char	**map_part;

	return_value = true;
	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1 || is_scene_empty(file_name))
		return (parser_panic(OPEN_SCENE_ERR));
	textures_part = get_textures_part(scene_fd);
	if (!parse_textures(this, textures_part))
		return_value = false;
	if (return_value != false)
	{
		map_part = get_map_part(file_name, scene_fd);
		if (!parse_map(map_part, this))
		{
			free_matrix(map_part);
			return_value = false;
		}
	}
	if (return_value != false)
		this->map = map_part;
	close(scene_fd);
	return (return_value);
}
