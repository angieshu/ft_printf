#include "libftprintf.h"

int		ft_readformat(char **format, char **s, va_list ap)
{
	flags f;
	length l;
	char *tmp;
	char *tmp2;
	f.s_size = 0;
	while (ft_strlen(*format) > 0)
	{
		ft_reset(&f, &l);
		if (**format == '%')
			tmp = ft_check_format(format, (va_list*)ap, &f, &l);
		else
			tmp = ft_strsub(*format, 0, 1);
		tmp2 = *s;
		*s = ft_strjoin(tmp2, tmp);
		*format += 1;
	}
	if (f.precision != -5)
		free(tmp);
	return (f.s_size);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char *s;
	int i;

	if (!format || !*format)
		return (0);
	s = ft_strnew(1);
	if (!format)
		return (-1);
	va_start(ap, format);
	i = ft_readformat((char**)&format, &s, ap);
	va_end(ap);
	if (s == NULL)
		return (-1);
	ft_putstr(s);
	i += ft_strlen(s);
	if (s)
		free(s);
	return (i);
}