/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 22:08:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void	parse_parameters(t_cub3d *this, char *file_name)
{
	char	*line;
	int		args;

	args = 0;
	line = get_next_line();
	while (line && line[0] != '1' && line[1] != '0')
	{
		if (!is_spaces(line[i]))
		{
			printf("%s\n", line);
			args += 1;
		}
		free(line);
		line = get_next_line();
	}
	if (!= 6)
		printf("error\n");
} */

size_t	get_nbr_lines_of_map(char *file_name)
{
	int		scene_fd;
	size_t	counter;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	counter = 0;
	line = get_next_line(scene_fd);
	while (line && line[0] != '1' && line[1] != '0')
	{
		free(line);
		line = get_next_line(scene_fd);
	}
	while (line)
	{
		free(line);
		line = get_next_line(scene_fd);
		counter += 1;
	}
	free (line);
	return (counter + 6);
}

char **read_scene(char *file_name)
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