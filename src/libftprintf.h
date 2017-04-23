/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 00:44:38 by ashulha           #+#    #+#             */
/*   Updated: 2017/04/23 00:44:40 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include "../libft/libft.h"
# include <stdio.h>

union			data
{
	intmax_t	i;
	uintmax_t	u;
	wchar_t		*ws;
	wint_t		wi;
	double		d;
	long double	ld;
	char		*s;
}				u_data;

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			star;
	int			precision;
	int			min_width;
	char		conv;
	uintmax_t	s_size;
	uintmax_t	total_size;
}				flags;

typedef struct	s_length
{
	int			none;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			lll;
}				length;

int				ft_printf(const char *restrict format, ...);
char			*ft_precision(char *tmp, int n);
char			*ft_pd(va_list *ap, flags *f, length *l);
char			*ft_pc(va_list *ap, flags *f, length *l);
char			*ft_po(va_list *ap, flags *f, length *l);
char			*ft_px(va_list *ap, flags *f, length *l);
char			*ft_pu(va_list *ap, flags *f, length *l);
char			*ft_ps(va_list *ap, flags *f, length *l);
char			*ft_pe(va_list *ap, flags *f, length *l);
char			*ft_pf(va_list *ap, flags *f, length *l);
char			*ft_pg(va_list *ap, flags *f, length *l);
char			*ft_pe_long(va_list *ap, flags *f);
char			*ft_pf_long(va_list *ap, flags *f);
char			*ft_pg_long(va_list *ap, flags *f);
char			*ft_pws(va_list *ap, flags *f);
char			*ft_pp(va_list *ap, flags *f);
char			*ft_pper(void);

intmax_t		ft_conv_len(va_list *ap, length *l);
uintmax_t		ft_conv_unsigned(va_list *ap, length *l);

char			*ft_identification(char *p, va_list ap, int precision);

int				ft_count_num(char *p);
int				ft_count_total_num (char *p);
int				ft_count_flags(char *p);

int				ft_check_flag(char **format, flags *f);
char			*ft_flags(char *s, flags *f);
void			ft_reset(flags *f, length *l);

int				ft_count_wsize(unsigned warg);
char			*ft_wprint(wint_t warg);
char			*ft_wprint_1(wint_t warg);

int				ft_check_conv_type(char **format, flags *f, length *l);
int				ft_check_minwith(char **format, va_list *ap, flags *f);
int				ft_check_precision(va_list *ap, char **format, flags *f);
void			ft_check_length(char **f, length *l);
char			*ft_check_format(char **format, va_list *ap, flags *f,
															length *l);

void			ft_zero_fl(char *s, char c, flags *f);
void			place_zero(char *s, char c, flags *f);
char			*ft_space(char *s, flags *f);
void			ft_star(va_list *ap, flags *f);

char			*ft_build(va_list *ap, flags *f, length *l);
char			*ft_min_width(char *s, flags *f);
char			*ft_extend_s(flags *f, char *s, int k, char left);

int				add_len(flags *f);
char			*ft_invalid(char **format, flags *f);

#endif
