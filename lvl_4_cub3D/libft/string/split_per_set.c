/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_per_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:39:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/28 00:46:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(const char *s, char *delim_set)
{
	size_t	words;
	bool	flag;
	size_t	i;

	words = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (!is_onstr(delim_set, s[i]) && flag == false)
		{
			flag = true;
			words += 1;
		}
		else if (is_onstr(delim_set, s[i]))
			flag = false;
		i += 1;
	}
	return (words);
}

static int	letters_in_word(const char *s, char *delim_set, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && !is_onstr(delim_set, s[i]))
	{
		size += 1;
		i += 1;
	}
	return (size);
}

char	**split_per_set(const char *s, char	*delim_set)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	word = words_counter(s, delim_set);
	str = malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (is_onstr(delim_set, s[i]))
			i += 1;
		str[j] = ft_substr(s, i, letters_in_word(s, delim_set, i));
		if (!str)
			return (NULL);
		i += letters_in_word(s, delim_set, i);
	}
	str[j] = NULL;
	return (str);
}
