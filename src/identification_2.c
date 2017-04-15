#include "libftprintf.h"

char	*ft_pe(va_list ap, int precision, char e)
{
	union data type;
	char *s;

	if (!(type.d = va_arg(ap, double)))
		return (NULL);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_exp(type.d, precision);
	if (e == 'E')
		ft_toupper_s(s);
	return (s);
}

char	*ft_pu(va_list ap, int precision)
{
	union data type;
	char *tmp;
	int i;

	if (!(type.l = va_arg(ap, long)))
		return (NULL);
	if (precision == 0 && type.l == 0)
		return ("");
	if (type.l < 0)
		tmp = ft_itoa_negative(type.l, 10);
	else
		tmp = ft_itoa_base(type.l, 10);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	return (tmp);
}

char	*ft_pper(void)
{
	char *s;

	s = (char*)ft_memalloc(2);
	s[1] = 0;
	s[0] = '%';
	return (s);
}

char	*ft_pf(va_list ap, int precision)
{
	union	data type;
	char	*s;

	if (!(type.d = va_arg(ap, double)))
		return (NULL);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_double(type.d, precision);
	return (s);
}

char	*ft_pg(va_list ap, int precision, char g)
{
	union data type;
	char *s;

	type.d = va_arg(ap, double);
	if (precision == -1)
		precision = 6;
	s = ft_itoa_double_g(type.d, precision);
	if (g == 'G')
		ft_toupper_s(s);
	return (s);
}