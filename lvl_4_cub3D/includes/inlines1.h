/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlines1.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:12:41 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 18:58:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INLINES1_H
# define INLINES1_H

static inline bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

static inline int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	return (0);
}

static inline bool	is_digit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	return (false);
}

static inline bool	ft_isalnum(int c)
{
	if (ft_isalpha(c) || is_digit(c))
		return (true);
	return (false);
}

#endif // INLINES_H
