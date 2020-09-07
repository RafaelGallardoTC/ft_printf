/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:10:46 by rgallard          #+#    #+#             */
/*   Updated: 2020/04/15 23:15:28 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define EX_STRING_LC "0123456789abcdef"
# define EX_STRING_UC "0123456789ABCDEF"
# define FLAGS_OPT "0123456789*-+.# "
# define CONV_OPT "dicspuxX%"
# define DIGITS_09 "0123456789"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_params
{
	int			c;
	int			len;
	int			nbrlen;
	char		*str;
	int			minus;
	int			plus;
	int			space;
	int			hash_key;
	int			zero;
	int			precision;
	int			dot;
	int			width;
	int			star;
	int			space0;
	size_t		s_len;
	va_list		ap;
}				t_params;

int				ft_printf(const char *format, ...);
int				ft_print_c(t_params *vr);
int				ft_print_s(t_params *vr);
int				ft_print_d(t_params *vr);
int				ft_print_p(t_params *vr);
int				ft_print_u(t_params *vr);
int				ft_print_exa(t_params *vr);
int				ft_printf_aux(t_params *vr);
int				ft_putnum(unsigned long long n, unsigned int b, char *digits);
int				ft_print_dispatch(t_params *vr);
int				ft_hashkey(t_params *vr);
int				ft_check_flags(t_params *vr, int c);
int				ft_check_width(t_params *vr, char **w_str);
int				ft_nb_output(t_params *vr, int nb);
int				ft_exa_output(t_params *vr, long long int n, char *str_dgs);
int				ft_str_prec(t_params *vr, const char *s);
void			ft_printnb(int nb, int max_digits, int num_len);
int				ft_parse_flags(t_params *vr, char **str);
void			ft_init_flags(t_params *vr);
void			ft_set_width(t_params *vr, int nb);
void			ft_force_plus_sign(t_params *vr, int nb);
void			ft_flag_pref(t_params *vr);
void			ft_spc(t_params *vr);
void			ft_str_width(t_params *vr, const char *s);
void			ft_nb_prec(t_params *vr);
void			ft_ch_width(t_params *vr, int c);
void			write_num(t_params *vr, long long int n, int b, char *n_dgs);
void			simply_put(t_params *vr, char c);
void			ft_putspace0_times(t_params *vr, int times);
void			ft_v_set_width(t_params *vr, int nb);

#endif
