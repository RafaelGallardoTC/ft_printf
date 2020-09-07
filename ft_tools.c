/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:23:10 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:20:11 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the given numbers of digits (max_digits) of a positive number "nb"
** It is nescesary to pass the total length of the given number.
*/

void	ft_printnb(int nb, int max_digits, int num_len)
{
	static int n = 0;

	if (nb >= 10)
		ft_printnb(nb / 10, max_digits, num_len);
	n++;
	if (n <= max_digits)
		ft_putchar(nb % 10 + '0');
	if (n > num_len)
		n = 0;
}

void	ft_force_plus_sign(t_params *vr, int nb)
{
	if (vr->plus)
	{
		nb >= 0 ? ft_putchar('+') : ft_putchar('-');
		vr->len++;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		vr->len++;
	}
}

void	ft_flag_pref(t_params *vr)
{
	if (vr->zero && vr->minus)
	{
		vr->zero = 0;
		vr->space0 = ' ';
	}
	if (vr->space && vr->plus)
		vr->space = 0;
	if (vr->dot)
		vr->zero = 0;
}

int		ft_hashkey(t_params *vr)
{
	int		count;

	count = 0;
	if ((vr->hash_key == 1) && ((vr->c == 'x') || (vr->c == 'X')))
		(vr->c == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	else if (vr->c == 'p')
		write(1, "0x", 2);
	return (count);
}

void	write_num(t_params *vr, long long int n, int b, char *n_dgs)
{
	if ((n == 0) && !vr->precision && vr->dot)
	{
		if (vr->c == 'p')
			;
		else if (vr->width)
		{
			ft_putchar(' ');
			vr->len++;
		}
	}
	else if (((vr->c == 'd') || (vr->c == 'i')) && (n < 0))
		vr->len += ft_putnum(-(unsigned)n, 10, DIGITS_09);
	else
		vr->len += ft_putnum(n, b, n_dgs);
}
