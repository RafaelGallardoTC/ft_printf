/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:45:24 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 00:53:17 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const	char	*s;
	size_t			n;

	s = src;
	n = size;
	if (!(dst && src))
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dst++ = *s++) == 0)
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
