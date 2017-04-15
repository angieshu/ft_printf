#include "libftprintf.h"

char	*ft_pc(va_list ap)
{
	union data type;
	char *s;

	if (!(type.c = (char)va_arg(ap, int)))
		return (NULL);
	s = (char*)ft_memalloc(2);
	s[1] = 0;
	s[0] = type.c;
		return (s);
}

char	*ft_ps(va_list ap, int precision)
{
	union data type;
	int i;

	if (!(type.s = va_arg(ap, char*)))
		return (NULL);
	i = ft_strlen(type.s);
	if (precision == -1)
		precision = i;
	if (precision < i)
		return (ft_strsub(type.s, 0, precision));
	return (ft_strdup(type.s));
}

char	*ft_pd(va_list ap, int precision)
{
	union	data type;
	char	*tmp;
	int		i;

	type.i = va_arg(ap, int);
	if (type.i == 0)
	{
		tmp = (char*)ft_memalloc(2);
		tmp[1] = 0;
		tmp[0] = '0';
		return (tmp);
	}
	if (!type.i)
		return (NULL);
	tmp = ft_itoa_base(type.i, 10);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	return (tmp);
}

char	*ft_po(va_list ap, int precision)
{
	union	data type;
	char	*tmp;
	int		i;

	type.l = va_arg(ap, int);
	if (type.l == 0)
	{
		tmp = (char*)ft_memalloc(2);
		tmp[0] = '0';
		tmp[1] = 0;
		return (tmp);
	}
	if (!type.l)
		return (NULL);
	tmp = ft_itoa_base(type.l, 8);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	return (tmp);
}

char	*ft_px(va_list ap, int precision, char x)
{
	union	data type;
	char	*tmp;
	int		i;

	type.l = va_arg(ap, int);
	if (type.l == 0)
	{
		tmp = (char*)ft_memalloc(2);
		tmp[1] = 0;
		tmp[0] = '0';
		return (tmp);
	}
	if (!type.l)
		return (NULL);
	tmp = ft_itoa_base(type.l, 16);
	if (x == 'X')
		ft_toupper_s(tmp);
	i = ft_strlen(tmp);
	if (i < precision)
		return (ft_precision(tmp, precision - i));
	return (tmp);
}
