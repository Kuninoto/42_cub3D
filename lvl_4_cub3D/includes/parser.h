/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:36:17 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 19:52:33 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

// ERROR MESSAGES -------------------------------------------------

/* PARSER ERRORS */

/* GET_MAP */
size_t				get_nbr_lines(char *file_name);
char				**get_scene(char *file_name);

// n >= lowest && n <= highest
static inline bool	fits_in_intrange(int n, int lowest, int highest) {
	return (n >= lowest && n <= highest);
};


/* PARSER UTILS */

int					parser_panic(char *str);
int					panic_unknown_element(char *unknown_element);

bool				assign_rgb(int *element_rgb, char **rgb);

/* PARSE ELEMENTS */
int					parse(t_scene *scene, char *file_name);

#endif // PARSER_H