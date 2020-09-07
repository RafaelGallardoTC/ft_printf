/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 01:28:33 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 05:27:11 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*full;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	full = (char*)malloc(sizeof(*full) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (full == NULL)
		return (NULL);
	while (*s1 != '\0')
		full[i++] = *s1++;
	while (*s2 != '\0')
		full[i++] = *s2++;
	full[i] = '\0';
	return (full);
}
