/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:00:39 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 00:53:17 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned	char	*d;
	unsigned	char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (NULL != d || NULL != s)
	{
		if (d > s)
		{
			while (n--)
				*(d + n) = *(s + n);
		}
		else
		{
			while (n--)
				*d++ = *s++;
		}
	}
	return (dst);
}
