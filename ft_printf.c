/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:09:17 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:18:32 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flags '-0.*'  cspdiuxX%
*/

int		ft_printf(const char *format, ...)
{
	t_params		s;

	s.len = 0;
	s.str = (char*)format;
	va_start(s.ap, format);
	ft_printf_aux(&s);
	va_end(s.ap);
	return (s.len);
}

int		ft_printf_aux(t_params *vr)
{
	int		i;

	while (*(vr->str))
	{
		vr->c = (unsigned char)*(vr->str)++;
		if (vr->c != '%')
		{
			ft_putchar(vr->c);
			vr->len++;
		}
		else if (*vr->str != '\0')
		{
			if ((i = ft_parse_flags(vr, &vr->str)) == 1)
				vr->c = (unsigned char)*(vr->str++);
			else
				vr->c = (unsigned char)*(vr->str);
			ft_print_dispatch(vr);
		}
	}
	return (vr->len);
}

int		ft_print_dispatch(t_params *vr)
{
	if (vr->c == 'd' || vr->c == 'i')
		ft_print_d(vr);
	else if (vr->c == 'c')
		ft_print_c(vr);
	else if (vr->c == 's')
		ft_print_s(vr);
	else if (vr->c == 'p')
		ft_print_p(vr);
	else if (vr->c == 'u')
		ft_print_u(vr);
	else if (vr->c == 'x' || vr->c == 'X')
		ft_print_exa(vr);
	else if (vr->c == '%')
		simply_put(vr, vr->c);
	else
	{
		ft_putchar(vr->c);
		vr->len++;
	}
	return (vr->len);
}
