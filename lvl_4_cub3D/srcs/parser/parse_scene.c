/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/04 00:41:08 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	get_nbr_map_lines(char *file_name)
{
	int 	scene_fd;
	size_t	count;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	count = 0;
	line = get_next_line(scene_fd);
	while (line)
	{
		free(line);
		line = get_next_line(scene_fd);
		if (line == NULL)
			return (0);
		if (line[0] == ' ' || line[0] == '0' || line[0] == '1')
			break ;
	}
	count += 1;
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

static char **get_textures_part(int scene_fd)
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
	printf("nbr lines = %ld\n", nbr_lines);
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

static inline bool	valid_boundaries(char *map_line)
{
	size_t	i;

	i = 0;
	while (is_spaces(map_line[i]))
		i += 1;
	if (map_line[i] != '1')
		return (parser_panic(NOT_SURROUNDED_BY_WALLS));
	i = ft_strlen(map_line) - 1;
	if (map_line[i] != '1')
		return (parser_panic(NOT_SURROUNDED_BY_WALLS));
	return (true);
}

bool	valid_map(char **map_part)
{
	size_t	i;

	i = 0;
	while (map_part[i])
	{
		if (only_spaces(map_part[i]))
			return (parser_panic(MAP_HAS_EMPTY_LINES));
		if (!valid_boundaries(map_part[i]))
			return (false);
		i += 1;	
	}
	return (true);
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
	return (return_value);
}

bool	parse_scene(t_cub3d *this, char *file_name)
{
	int		scene_fd;
	bool	return_value;
	char	**textures_part;
	char 	**map_part;

	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1)
		return (parser_panic(OPEN_SCENE_ERR));
	return_value = true;
	if (is_scene_empty(file_name))
		return (parser_panic(EMPTY_SCENE_ERR));
	textures_part = get_textures_part(scene_fd);
	if (!parse_textures(this, textures_part))
		return_value = false;

	// NOT READING THE MAP CORRECTLY
	map_part = get_map_part(file_name, scene_fd);
	if (!valid_map(map_part))
	{
		print_char_matrix(map_part);
		free_matrix(map_part);
		return_value = false;	
	}

	printf("NO: %p\n", this->textures.north);
	printf("SO: %p\n", this->textures.south);
	printf("WE: %p\n", this->textures.west);
	printf("EA: %p\n", this->textures.east);
	printf("Floor RGB: %d,%d,%d\n", this->textures.floor_rgb[0],this->textures.floor_rgb[1],this->textures.floor_rgb[2]);
	printf("Sky RGB: %d,%d,%d\n", this->textures.sky_rgb[0],this->textures.sky_rgb[1],this->textures.sky_rgb[2]);

	print_char_matrix(textures_part);
	if (return_value == true)
		print_char_matrix(map_part);

	free_matrix(textures_part);

	if (return_value != false)
		this->map = map_part;
	close(scene_fd);
	return (return_value);
}
