#include "libftprintf.h"

int		ft_readformat(char **format, char **s, va_list ap)
{
	flags f;
	length l;
	char *tmp;
	// char *tmp2;

s = NULL;
	f.total_size = 0;
	while (ft_strlen(*format) > 0 || **format)
	{
		ft_reset(&f, &l);
		if (**format == '%')
			tmp = ft_check_format(format, (va_list*)ap, &f, &l);
		else
		{
			tmp = ft_strsub(*format, 0, 1);
			f.total_size++;
			write(1, tmp, 1);
		}
		// if (tmp)
		// // {
		// 	tmp2 = *s;
		// 	*s = ft_strjoin(tmp2, tmp);
		// // }
		// if (*s[0] == 0 && !*format)
		// {
		// 	printf("lala\n");
		// 	return (-1);
		// }
		if (*format)
			*format += 1;
		// f.s_size++;
		// printf("s = %s", tmp);
	}
	if (tmp && f.precision != -5)
		free(tmp);
	return (f.total_size);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char *s;
	int i;

	if (!format || !*format)
		return (0);
	s = ft_strnew(0);
	va_start(ap, format);
	i = ft_readformat((char**)&format, &s, ap);
	va_end(ap);
	// if (!s)
	// 	return (0);
	// write(1, s, i);
	if (s)
		free(s);
	return (i);
}