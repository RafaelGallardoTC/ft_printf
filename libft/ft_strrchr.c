/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:30:24 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/13 20:41:01 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (*s)
	{
		if (*s == (char)c)
			save = (char *)s;
		s++;
	}
	return (*s == (char)c ? (char *)s : save);
}
