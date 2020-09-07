/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 05:11:59 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 22:50:09 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_params *vr)
{
	int	c;

	c = va_arg(vr->ap, int);
	ft_ch_width(vr, c);
	return (1);
}

void	ft_ch_width(t_params *vr, int c)
{
	if ((vr->width > 1) && !vr->minus)
	{
		vr->len += vr->width;
		while (vr->width-- > 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	else if (vr->minus && (vr->width > 1))
	{
		vr->len += vr->width;
		ft_putchar(c);
		while (vr->width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		ft_putchar(c);
		vr->len++;
	}
}
