/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:15:10 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/25 01:54:08 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (f && s)
	{
		if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
