/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:11:13 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/18 00:53:17 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned	char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}
