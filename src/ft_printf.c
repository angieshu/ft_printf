#include "libftprintf.h"

int ft_count_precision(char *p)
{
	int precision;
	int i;

	i = 1;
	precision = 0;
	while (*(p + i) >= '0' && *(p + i) <= '9')
	{
		precision = precision * 10 + *(p + i) - '0';
		i++;
	}
	return (precision);
}

int ft_count_num(char *p)
{
	int i;

	i = 0;
	while (*(p + i) >= '0' && *(p + i) <= '9')
		i++;
	return (i);
}

int	ft_identification(char *p, va_list ap, int precision)
{
	if (*p == 'c' || *p == 'C')
		return (ft_pc(ap));
	if (*p == 'd' || *p == 'i')
		return (ft_pd(ap, precision));
	if (*p == 'e' || *p == 'E')
		return (ft_pe(ap, precision, *p));
	if (*p == 'f' || *p == 'F')
		return (ft_pf(ap, precision));
	if (*p == 'g' || *p == 'G')
		return (ft_pg(ap, precision, *p));
	if (*p == 'x' || *p == 'X')
		return (ft_px(ap, precision, *p));
	if (*p == 'o')
		return (ft_po(ap, precision));
	if (*p == 's')
		return (ft_ps(ap, precision));
	if (*p == 'u' || *p == 'U' || *p == 'D')
		return (ft_pu(ap, precision));
	if (*p == '.')
		ft_identification(++p, ap, precision);
	// else if (*p >= '0' && *p <= '9')
	// 	return (ft_count_precision(&p, ap));
	// else if (*p == 'p')
	// 	i = 
	// else if (*p == 'n')
	// 	i = 
	// else if (*p == 'a')
	// else if (*p == 'A')
	if (*p == '%')
		return (ft_pper());
	// else if (*p == '+')
	// 	i = 
	// else if (*p == '-')
	// 	i = 
	// else if (*p == ' ')
	// 	i = 
	// else if (*p == '*')
	//	i = 
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char *p;
	int i;
	int precision;

	i = -1;
	precision = -1;
	if (!format)
		return (-1);
	va_start(ap, format);
	p = (char*)format;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			++p;
			if (*p == '.')
			{
				precision = ft_count_precision(p);
				p += ft_count_num(p) + 2;
			}
			i += ft_identification(p, ap, precision) - 1;
			precision = -1;
		}
		else 
			ft_putchar(*p);
		i++;
		p++;
	}
	printf("i = %d\n",i);
	return (i);
}