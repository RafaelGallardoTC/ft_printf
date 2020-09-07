/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 07:22:56 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 22:51:23 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_width(t_params *vr, int nb)
{
	ft_v_set_width(vr, nb);
	if ((vr->dot && vr->zero) && (vr->plus || (nb < 0)))
	{
		nb >= 0 ? ft_putchar('+') : ft_putchar('-');
		vr->len++;
	}
}

void	ft_v_set_width(t_params *vr, int nb)
{
	int		w;

	w = vr->width;
	nb < 0 || vr->plus ? w-- : w;
	if (vr->precision)
	{
		while (w > (vr->precision > vr->nbrlen ? vr->precision : vr->nbrlen))
		{
			vr->plus && vr->zero ? ft_putchar('0') : ft_putchar(' ');
			vr->len++;
			w--;
		}
	}
	else
	{
		while (w-- > (vr->nbrlen + vr->precision))
		{
			vr->zero && !vr->dot ? ft_putchar('0') : ft_putchar(' ');
			vr->len++;
		}
	}
}

void	ft_nb_prec(t_params *vr)
{
	int		i;
	int		tmp;

	i = vr->nbrlen;
	tmp = vr->precision;
	if (vr->precision > 0)
	{
		while ((tmp - i) > 0)
		{
			ft_putchar('0');
			tmp--;
			vr->len++;
		}
	}
}
