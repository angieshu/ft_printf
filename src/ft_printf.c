#include "libftprintf.h"

char *ft_min_width(char *p, va_list ap, int precision, unsigned int i)
{
	int k;
	char *tmp;
	char *tmp2;
	char *s;

	if (!(tmp2 = ft_identification(p, ap, precision)))
		return (NULL);
	if ((unsigned int)ft_strlen(tmp2) < i)
	{	
		k = i - ft_strlen(tmp2);
		if (!(tmp = (char*)ft_memalloc(k + 1)))
			return (NULL);
		tmp[k] = 0;
		while (k-- > 0)
			tmp[k] = ' ';
		s = ft_strjoin(tmp, tmp2);
		free(tmp);
	}
	else
		s = ft_strdup(tmp2);
	if (!(ft_strlen(tmp2) == 1 && tmp2[0] == '0'))
		free(tmp2);
	return (s);
}


char	*ft_identification(char *p, va_list ap, int precision)
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
	if (*p == '+' || *p == '-' || *p == '#' || *p == '0' || *p == ' ')
		return (ft_check_flag(p, ap, precision));
	// else if (*p == '*')
	// else if (*p == 'n')
	// 	i = 
	// else if (*p == 'a')
	// else if (*p == 'A')
	if (*p == '%')
		return (ft_pper());
	return (NULL);
}

char	*ft_ifnumber(char *p, va_list ap, int precision)
{
	unsigned int i;
	char *tmp;
	char *tmp2;

	if ((*p > '0' && *p <= '9') || *p == '.')
	{
		i = ft_atoi(p);
		if (!(tmp = p + ft_count_num(p)))
			return (NULL);
		if (*tmp == '.')
		{
			precision = ft_atoi(tmp + 1);
			if (!(tmp = tmp + ft_count_num(tmp + 1) + 1))
				return (NULL);
		}
		tmp2 = ft_min_width(tmp, ap, precision, i);
		if (!tmp2)
			return(NULL);
	}
	else
		if (!(tmp2 = ft_identification(p, ap, precision)))
			return (NULL);
	return (tmp2);
}

char	*ft_readformat(char *format, va_list ap, int precision)
{
	char *s;
	char *p;
	char *tmp;
	char *tmp2;

	p = format;
	s = ft_strnew(1);
	while (ft_strlen(p) > 0)
	{
		if (*p == '%')
		{
			++p;
			if (!(tmp = ft_ifnumber(p, ap, precision)))
				return (NULL);
			p += (ft_count_total_num(p));
		}
		else
			tmp = ft_strsub(p, 0, 1);
		tmp2 = s;
		s = ft_strjoin(tmp2, tmp);
		free(tmp2);
		p++;
	}
	free(tmp);
	return (s);
}
 
int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char *s;
	int i;

	if (!format)
		return (-1);
	va_start(ap, format);
	s = ft_readformat((char*)format, ap, -1);
	va_end(ap);
	if (s == NULL)
		return (-1);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}