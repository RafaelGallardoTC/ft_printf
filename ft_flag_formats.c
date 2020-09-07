/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_formats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:34:56 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:14:56 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_params *vr)
{
	vr->minus = 0;
	vr->plus = 0;
	vr->hash_key = 0;
	vr->space = 0;
	vr->precision = 0;
	vr->zero = 0;
	vr->width = 0;
	vr->dot = 0;
	vr->space0 = ' ';
}

int		ft_check_flags(t_params *vr, int c)
{
	if (c == '-')
		vr->minus = 1;
	else if (c == '+')
		vr->plus = 1;
	else if (c == ' ')
		vr->space = 1;
	else if (c == '#')
		(!vr->dot && !vr->width) ? vr->hash_key = 1 : vr->hash_key;
	else if (c == '0')
	{
		vr->zero = 1;
		vr->space0 = '0';
	}
	else
		return (0);
	return (1);
}

int		ft_check_width(t_params *vr, char **w_str)
{
	if (**w_str == '*')
	{
		vr->width = va_arg(vr->ap, int);
		if (vr->width < 0)
		{
			vr->minus = 1;
			vr->width *= -1;
		}
		(*w_str)++;
	}
	else if (ft_isdigit(**w_str))
	{
		while (ft_isdigit(**w_str))
		{
			vr->width *= 10;
			vr->width += **w_str - '0';
			(*w_str)++;
		}
	}
	else
		return (0);
	return (1);
}

int		ft_check_precision(t_params *vr, char **p_str)
{
	vr->dot = 1;
	(*p_str)++;
	if (**p_str == '*')
	{
		vr->precision = va_arg(vr->ap, int);
		(*p_str)++;
	}
	else if (ft_isdigit(**p_str))
	{
		while (ft_isdigit(**p_str))
		{
			vr->precision *= 10;
			vr->precision += **p_str - '0';
			(*p_str)++;
		}
	}
	else
		return (0);
	return (1);
}

int		ft_parse_flags(t_params *vr, char **str)
{
	char	*flag_str;

	flag_str = *str;
	ft_init_flags(vr);
	while (ft_strchr(FLAGS_OPT, *flag_str) != 0 && *flag_str != '\0')
	{
		if (ft_check_flags(vr, *flag_str))
			flag_str++;
		else if (*flag_str == '.')
			ft_check_precision(vr, &flag_str);
		else
			ft_check_width(vr, &flag_str);
	}
	ft_flag_pref(vr);
	if ((*flag_str != '\0') && (ft_strchr(CONV_OPT, *flag_str) != 0))
	{
		*str = flag_str;
		return (1);
	}
	(*flag_str != '\0') ? str++ : str;
	return (0);
}
