#include "libftprintf.h"

int		ft_check_flag(char **format, flags *f)
{
	int i;

	i = ft_count_flags(*format);
	if (i == 0)
		return (0);
	while (i-- > 0)
	{
		if (**format == '+')
			f->plus = 1;
		else if (**format == '-')
			f->minus = 1;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == '#')
			f->hash = 1;
		else if (**format == ' ')
			f->space = 1;
		// else if (**(format + i) == '$')
		// 	f->dollar = 1;
		// else if (**(format + i) == '\'')
		// 	f->apostrophe = 1;
		// else
		// 	return (0);
		*format += 1;
	}
	return (1);
}

char	*ft_flags(char *s, flags *f)
{
	// if (f->hash == 1)
	// 	s = ft_hash(s, f);
	// if (f->plus == 1)
	// 	s = ft_plus(s, f);
	// if (f->minus == 1)
	// 	s = ft_minus(s);
	if (f->space == 1)
		s = ft_space(s, f);
	if (f->zero == 1)
		ft_zero_fl(s, '0', f);
	if (f->dollar == 1)
		ft_zero_fl(s, '$', f);
	if (!s)
		return (NULL);
	return (s);
}

void	ft_reset(flags *f, length *l)
{
	f->plus = 0;
	f->minus = 0;
	f->hash = 0;
	f->space = 0;
	f->zero = 0;
	f->apostrophe = 0;
	f->dollar = 0;
	f->precision = -1;
	f->min_width = 0;
	f->conv = 0; 
	l->none = 0;
	l->hh = 0;
	l->h = 0;
	l->l = 0;
	l->ll = 0;
	l->j = 0;
	l->z = 0;
} 