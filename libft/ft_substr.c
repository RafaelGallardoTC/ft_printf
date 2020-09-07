/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:28:40 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/23 06:26:15 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*piece;

	if (!s || !(piece = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	ft_memcpy(piece, s + start, len);
	piece[len] = '\0';
	return (piece);
}
