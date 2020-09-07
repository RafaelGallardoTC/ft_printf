/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:10:03 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 00:53:17 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *p, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen((char*)p);
	if (*p == '\0')
		return ((char*)str);
	while (*str && len-- >= n_len)
	{
		if (0 == ft_strncmp(str, p, n_len))
			return ((char*)str);
		str++;
	}
	return (NULL);
}
