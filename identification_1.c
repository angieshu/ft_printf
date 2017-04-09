#include "libftprintf.h"

int		ft_pc(va_list ap)
{
	union data type;

	if (!(type.c = (char)va_arg(ap, int)))
		return (-1);
	ft_putchar(type.c);
	return (1);
}

int		ft_ps(va_list ap, int precision)
{
	union data type;
	char *s;
	int i;

	if (!(type.s = va_arg(ap, char*)))
		return (-1);
	i = ft_strlen(type.s);
	if (precision == -1)
		precision = i;
	if (precision < i)
	{
		s = ft_strsub(type.s, 0, precision);
		i = ft_strlen(s);
		ft_putstr(s);
		free(s);
		return (i);
	}
	ft_putstr(type.s);
	return (i);
}

int		ft_pd(va_list ap, int precision)
{
	union	data type;
	char	*tmp;
	int		i;

	type.i = va_arg(ap, int);
	if (precision == 0 && type.i == 0)
		return (0);
	tmp = ft_itoa_base(type.i, 10);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	ft_putstr(tmp);
	if (type.l != 0)
		free(tmp);
	return (i);
}

int		ft_po(va_list ap, int precision)
{
	union	data type;
	char	*tmp;
	int		i;

	type.l = va_arg(ap, int);
	if (precision == 0 && type.l == 0)
		return (0);
	tmp = ft_itoa_base(type.l, 8);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	ft_putstr(tmp);
	if (type.l != 0)
		free(tmp);
	return (i);
}

int		ft_px(va_list ap, int precision, char x)
{
	union	data type;
	char	*tmp;
	int		i;

	type.l = va_arg(ap, int);
	if (precision == 0 && type.l == 0)
		return (0);
	tmp = ft_itoa_base(type.l, 16);
	if (x == 'X')
		ft_toupper_s(tmp);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	ft_putstr(tmp);
	if (type.l != 0)
		free(tmp);
	return (i);
}
