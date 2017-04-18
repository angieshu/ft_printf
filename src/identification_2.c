#include "libftprintf.h"

char	*ft_pe(va_list ap, flags *f)
{
	union data	type;
	char		*s;

	type.d = va_arg(ap, double);
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_exp(type.d, f->precision);
	if (f->conv == 'E')
		ft_toupper_s(s);
	return (s);
}

char	*ft_pu(va_list ap, flags *f, length *l)
{
	union data	type;
	intmax_t	i;
	char		*s;

	if (f->conv == 'U')
		l->l = 1;
	type.i = ft_conv_unsigned(ap, l);
	if (f->precision == 0 && type.i == 0)
	{
		s = ft_strnew(1);
		return (s);
	}
	if (type.i == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
	}
	else if (type.i < 0)
		s = ft_itoa_negative(type.i, 10);
	else
		s = ft_itoa_base(type.i, 10);
	i = ft_strlen(s);
	if (i < f->precision)
		return (ft_precision(s, f->precision - i));
	return (s);
}

char	*ft_pper(void)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';
	return (s);
}

char	*ft_pf(va_list ap, flags *f)
{
	union data	type;
	char		*s;

	type.d = va_arg(ap, double);
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double(type.d, f->precision);
	return (s);
}

char	*ft_pg(va_list ap, flags *f)
{
	union data	type;
	char		*s;

	type.d = va_arg(ap, double);
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double_g(type.d, f->precision);
	if (f->conv == 'G')
		ft_toupper_s(s);
	return (s);
}