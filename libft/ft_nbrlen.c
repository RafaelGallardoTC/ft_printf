/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 07:05:16 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/09 02:17:00 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the number of digits of a given number.
**	"base" i
*/

size_t		ft_nbrlen(long long int nb, int base)
{
	size_t		res;

	res = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb = nb / base;
		res++;
	}
	return (res);
}
