/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 01:19:07 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 22:50:34 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(t_params *vr)
{
	const char	*str;

	str = (const char*)va_arg(vr->ap, const char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	vr->s_len = ft_strlen(str);
	if (vr->width)
		ft_str_width(vr, str);
	else if (vr->dot)
		ft_str_prec(vr, str);
	else
	{
		ft_putstr((char*)str);
		vr->len += ft_strlen(str);
	}
	return (vr->len);
}

int		ft_str_prec(t_params *vr, const char *s)
{
	int		i;

	i = 0;
	if (!vr->precision)
		ft_putstr("");
	else if ((vr->precision > 0) && ((size_t)vr->precision <= vr->s_len))
	{
		vr->len += ft_putstr_len(s, vr->precision);
		i++;
	}
	else
	{
		ft_putstr((char*)s);
		vr->len += i = vr->s_len;
	}
	return (i);
}

void	ft_str_width(t_params *vr, const char *s)
{
	size_t		i;

	i = vr->s_len;
	if (vr->dot && (vr->precision < (int)i) && (vr->precision >= 0))
		i = (size_t)vr->precision;
	if ((size_t)vr->width < i)
		vr->len += ft_putstr_len(s, i);
	else if (vr->minus)
	{
		vr->space0 = ' ';
		vr->len += ft_putstr_len(s, i);
		ft_putspace0_times(vr, vr->width - i);
	}
	else
	{
		ft_putspace0_times(vr, vr->width - i);
		vr->len += ft_putstr_len(s, i);
	}
}

void	simply_put(t_params *vr, char c)
{
	if (!vr->minus && vr->width)
	{
		vr->len += vr->width;
		while (--vr->width)
			ft_putchar(vr->space0);
		ft_putchar(c);
	}
	else if (vr->minus && vr->width)
	{
		vr->len += vr->width;
		ft_putchar(c);
		while (--vr->width)
			ft_putchar(vr->space0);
	}
	else
	{
		ft_putchar(c);
		vr->len++;
	}
}
