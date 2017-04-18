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
			tmp = ft_check_format(format, ap, f, l);
		else
			tmp = ft_strsub(*format, 0, 1);
		tmp2 = ft_strdup(*s);
		*s = ft_strjoin(tmp2, tmp);
		free(tmp2);
		*format += 1;
	}
	free(tmp);
	return (f.s_size);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char *s;
	int i;

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
	free(s);
	return (i);
}