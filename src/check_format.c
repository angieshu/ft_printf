#include "libftprintf.h"

int		ft_check_conv_type(char **format, flags *f)
{
	if (**format != 's' && **format != 'd' && **format != 'i' &&
		**format != 'o' && **format != 'S' && **format != 'p' &&
		**format != 'D' && **format != 'O' && **format != 'u' &&
		**format != 'U' && **format != 'x' && **format != 'X' &&
		**format != 'c' && **format != 'C' && **format != 'g' &&
		**format != 'G' && **format != 'f' && **format != 'F' &&
		**format != 'e' && **format != 'E' && **format != '%' &&
		**format != 'n')
		return (0);
	f->conv = **format;
	return (1);
}

int		ft_check_minwith(char **format, flags *f)
{
	int i;
	i = ft_atoi(*format);
	*format += ft_count_num(*format);
	if (i > 0)
	{
		f->min_width = i;
		return (1);
	}
	return (0);
}

int		ft_check_precision(char **format, flags *f)
{
	if (**format == '.')
	{
		*format += 1;
		f->precision = ft_atoi(*format);
		*format += ft_count_num(*format);
		if (f->precision < 0)
			return (0);
		return (1);
	}
	f->precision = -1;
	return (0);
}

void	ft_check_length(char **f, length *l)
{
	if (**f == 'h' || **f == 'l' || **f == 'j' || **f == 'z')
	{
		if (**f == 'h' && **(f + 1) == 'h')
		{
			l->hh = 1;
			*f += 1;
		}
		else if (**f == 'h')
			l->h = 1;
		else if (**f == 'l' && **(f + 1) == 'l')
		{
			l->ll = 1;
			*f += 1;
		}
		else if (**f == 'l')
			l->l = 1;
		else if (**f == 'j')
			l->j = 1;
		else if (**f == 'z')
			l->z = 1;
		*f += 1;
	}
	else 
		l->none = 1;
}

char	*ft_check_format(char **format, va_list ap, flags f, length l)
{
	*format += 1;
	while (!ft_check_conv_type(format, &f))
	{
		ft_check_length(format, &l);
		if (ft_check_flag(format, &f))
			continue ;
		else if (ft_check_precision(format, &f))
			continue ;
		else if (ft_check_minwith(format, &f))
			continue ;
		else
			break ;
	}
	ft_check_length(format, &l);
	if (!ft_check_conv_type(format, &f))
		return (NULL);
	return (ft_build(ap, &f, &l));
	// if (!ft_check_flag(format, &f))
	// 	return (error());
	// f->min_width = ft_check_minwith(format);
	// if (!ft_check_precision(format, &f))
	// 	return (error());
	// ft_check_length(format, &l)
	// if (!ft_check_conv_type(format, &f))
	// 	return (error());
}
