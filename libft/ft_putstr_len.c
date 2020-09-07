/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:58:38 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/13 19:36:11 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_len(const char *str, size_t len)
{
	const	char	*s;
	int				i;

	s = str;
	i = 0;
	if (*s == '\0' || len < 1)
	{
		ft_putstr("");
		return (0);
	}
	while (*s && len--)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}
