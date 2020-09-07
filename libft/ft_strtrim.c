/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 05:45:18 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 09:41:51 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*clean;
	size_t	len;
	size_t	start;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	len = ft_strlen(s1 + start);
	if (len != 0)
		while (s1[start + len - 1] && ft_strchr(set, s1[start + len - 1]))
			len--;
	if (!(clean = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(clean, s1 + start, len);
	clean[len] = '\0';
	return (clean);
}
