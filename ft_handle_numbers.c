/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 07:54:33 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:14:56 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnum(unsigned long long n, unsigned int b, char *digits)
{
	int res;

	res = 1;
	if (n >= b)
		res += ft_putnum(n / b, b, digits);
	ft_putchar(digits[n % b]);
	return (res);
}

int		ft_print_d(t_params *vr)
{
	int		n;

	n = va_arg(vr->ap, int);
	vr->nbrlen = ft_nbrlen(n, 10);
	if (vr->space && (n >= 0))
	{
		ft_putchar(' ');
		vr->width--;
	}
	if ((n == 0) && (!vr->width && !vr->precision && vr->dot))
	{
		ft_force_plus_sign(vr, n);
		return (vr->len);
	}
	else
		ft_nb_output(vr, n);
	return (vr->len);
}

int		ft_print_exa(t_params *vr)
{
	unsigned long int	n;

	n = (unsigned int)va_arg(vr->ap, unsigned int);
	vr->nbrlen = ft_nbrlen(n, 16);
	if (vr->c == 'x')
		ft_exa_output(vr, n, EX_STRING_LC);
	else if (vr->c == 'X')
		ft_exa_output(vr, n, EX_STRING_UC);
	return (vr->len);
}

int		ft_print_u(t_params *vr)
{
	unsigned int	n;

	n = (unsigned int)va_arg(vr->ap, unsigned int);
	vr->nbrlen = ft_nbrlen(n, 10);
	if ((n == 0) && !vr->precision && !vr->width && vr->dot)
		vr->space0 = 0;
	if (vr->minus)
	{
		ft_nb_prec(vr);
		write_num(vr, n, 10, DIGITS_09);
		ft_set_width(vr, n);
	}
	else
	{
		ft_set_width(vr, n);
		ft_nb_prec(vr);
		write_num(vr, n, 10, DIGITS_09);
	}
	return (vr->len);
}

int		ft_print_p(t_params *vr)
{
	unsigned long int	n;

	n = (unsigned long int)va_arg(vr->ap, unsigned long int);
	if ((n == 0) && (vr->dot))
		vr->nbrlen = 2;
	else
		vr->nbrlen = ft_nbrlen(n, 16) + 2;
	vr->len += 2;
	if (vr->dot && (vr->precision > vr->width))
	{
		ft_hashkey(vr);
		if (n == 0)
			vr->precision += 1;
		else
			vr->precision += 2;
	}
	ft_exa_output(vr, n, EX_STRING_LC);
	return (vr->len);
}
