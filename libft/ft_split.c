/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 05:38:49 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/25 01:28:14 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	int		pieces(char const *s, char c)
{
	int		count;
	int		valid;

	count = 0;
	valid = 1;
	while (*s)
	{
		if (*s != c && valid == 1)
		{
			count++;
			valid = 0;
		}
		if (*s == c)
			valid = 1;
		(s)++;
	}
	return (count);
}

static	size_t	p_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	if (!(*s))
		return (0);
	while (*s != c && *s)
	{
		size++;
		s++;
	}
	return (size);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_parts;
	char			**splitted;

	i = 0;
	if (!s)
		return (NULL);
	nb_parts = pieces(s, c);
	if (!(splitted = (char**)malloc(sizeof(char*) * (nb_parts + 1))))
		return (NULL);
	while (i < nb_parts)
	{
		while ((*s == c) && s)
			s++;
		if (!(splitted[i] = ft_substr((char*)s, 0, p_size(s, c))))
			return (ft_malloc_error(splitted));
		s += p_size(s, c);
		++i;
	}
	splitted[nb_parts] = NULL;
	return (splitted);
}
