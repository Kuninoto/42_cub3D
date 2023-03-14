/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:12 by roramos           #+#    #+#             */
/*   Updated: 2023/03/14 20:38:20 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITERS_H
# define WRITERS_H

# include <unistd.h>

size_t				ft_strlen(const char *str);

/**
 * @brief Writes a character into fd
 * 
 * @param c  Character to write
 * @param fd File descriptor to write to  
 */
static inline void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/**
 * @brief Writes str into fd
 * 
 * @param str String to write
 * @param fd File descriptor to write to
 */
static inline void	ft_putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	write(fd, str, ft_strlen(str));
}

/**
 * @brief Writes str, followed by a newline, into fd
 * 
 * @param str String to write
 * @param fd  File descriptor to write to
 */
static inline void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

#endif // WRITERS_H
