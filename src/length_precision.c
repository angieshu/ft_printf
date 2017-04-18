#include "libftprintf.h"

intmax_t	ft_conv_len(va_list ap, length *l)
{
	if (l->l == 1)
		return ((long)va_arg(ap, intmax_t));
	if (l->hh == 1)
		return ((signed char)va_arg(ap, intmax_t));
	if (l->h == 1)
		return ((short)va_arg(ap, intmax_t));
	if (l->ll == 1)
		return ((long long)va_arg(ap, intmax_t));
	if (l->j == 1)
		return (va_arg(ap, intmax_t));
	if (l->z == 1)
		return ((size_t)va_arg(ap, intmax_t));
	return ((int)va_arg(ap, intmax_t));
}

uintmax_t	ft_conv_unsigned(va_list ap, length *l)
{
	if (l->l == 1)
		return ((unsigned long)va_arg(ap, uintmax_t));
	if (l->hh == 1)
		return ((unsigned char)va_arg(ap, uintmax_t));
	if (l->h == 1)
		return ((unsigned short)va_arg(ap, uintmax_t));
	if (l->ll == 1)
		return ((unsigned long long)va_arg(ap, uintmax_t));
	if (l->j == 1)
		return (va_arg(ap, uintmax_t));
	if (l->z == 1)
		return ((size_t)va_arg(ap, uintmax_t));
	return ((unsigned int)va_arg(ap, uintmax_t));
}

char		*ft_precision(char *tmp, int n)
{
	char *tmp2;
	char *s;
	intmax_t i;

	i = 0;
	tmp2 = ft_strnew(n);
	while (n-- > 0)
		tmp2[n] = '0';
	s = ft_strjoin(tmp2, tmp);
	while (s[i])
	{
		if (s[i] == '-')
		{
			s[i] = '0';
			s[0] = '-';
			break;
		}
		i++;
	}
	free(tmp);
	free(tmp2);
	return (s);
}
