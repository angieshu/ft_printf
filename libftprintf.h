#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>

union		data
{
	int		i;
	char	c;
	char	*s;
	double	d;
	float	f;
	long	l;
};

int		ft_printf(const char *restrict format, ...);

/*		Conversions			*/
int		ft_precision(char *tmp, int n);
int		ft_pc(va_list ap);
int		ft_ps(va_list ap, int precision);
int		ft_pd(va_list ap, int precision);
int		ft_po(va_list ap, int precision);
int		ft_px(va_list ap, int precision, char x);
int		ft_pe(va_list ap, int precision, char e);
int		ft_pu(va_list ap, int precision);
int		ft_pper(void);
int		ft_pf(va_list ap, int precision);
int		ft_pg(va_list ap, int precision, char g);

int	ft_identification(char *p, va_list ap, int precision);


#endif