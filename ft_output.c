/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:55:23 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:16:35 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_output(t_params *vr, int n)
{
	if ((vr->minus && vr->plus) || vr->minus)
	{
		ft_force_plus_sign(vr, n);
		ft_nb_prec(vr);
		write_num(vr, n, 10, DIGITS_09);
		ft_set_width(vr, n);
	}
	else
	{
		if (vr->zero && !vr->dot)
			ft_force_plus_sign(vr, n);
		ft_set_width(vr, n);
		if (!vr->zero)
			ft_force_plus_sign(vr, n);
		ft_nb_prec(vr);
		write_num(vr, n, 10, DIGITS_09);
	}
	return (vr->len);
}

int		ft_exa_output(t_params *vr, long long int n, char *str_dgs)
{
	if (vr->minus)
	{
		ft_nb_prec(vr);
		ft_hashkey(vr);
		write_num(vr, n, 16, str_dgs);
		ft_set_width(vr, n);
	}
	else
	{
		ft_set_width(vr, n);
		ft_nb_prec(vr);
		if ((vr->c == 'p') && vr->dot && (vr->precision > vr->width))
			;
		else
			ft_hashkey(vr);
		write_num(vr, n, 16, str_dgs);
	}
	return (vr->len);
}

void	ft_putspace0_times(t_params *vr, int times)
{
	while (times)
	{
		ft_putchar(vr->space0);
		vr->width--;
		vr->len++;
		times--;
	}
}
