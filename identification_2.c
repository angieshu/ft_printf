#include "libftprintf.h"

int		ft_pe(va_list ap, int precision, char e)
{
	union data type;
	char *s;
	int i;

	type.d = va_arg(ap, double);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_exp(type.d, precision);
	if (e == 'E')
		ft_toupper_s(s);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int		ft_pu(va_list ap, int precision)
{
	union data type;
	char *tmp;
	int i;

	type.l = va_arg(ap, int);
	if (precision == 0 && type.l == 0)
		return (0);
	if (type.l < 0)
		tmp = ft_itoa_negative(type.l, 10);
	else
		tmp = ft_itoa_base(type.l, 10);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	ft_putstr(tmp);
	if (type.l != 0)
		free(tmp);
	return (i);
}

int		ft_pper(void)
{
	ft_putchar('%');
	return (1);
}

int		ft_pf(va_list ap, int precision)
{
	union	data type;
	char	*s;
	int		i;

	type.d = va_arg(ap, double);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_double(type.d, precision);
	i = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (i);
}

int		ft_pg(va_list ap, int precision, char g)
{
	union data type;
	char *s;
	int i;

	type.d = va_arg(ap, double);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_double_g(type.d, precision);
	i = ft_strlen(s);
	if (g == 'G')
		ft_toupper_s(s);
	ft_putstr(s);
	if (type.d != 0)
		free(s);
	return (i);
}