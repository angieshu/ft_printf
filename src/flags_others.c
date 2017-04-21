#include "libftprintf.h"

char	*ft_invalid(char **format, flags *f)
{
	char *s;

	s = ft_strnew(1);
	s[0] = **format;
	return (ft_min_width(s, f));
}

void	ft_star(va_list *ap, flags *f)
{
	int width;

	width = va_arg(*ap, intmax_t);
	if (width < 0)
	{
		f->minus = 1;
		f->min_width = width * -1;
	}
	else
		f->min_width = width;
}

void	ft_zero_fl(char *s, char c, flags *f)
{
	int i;

	i = 0;
	if ((f->precision >= f->min_width) || f->precision == -1 || f->conv == 'C')
	{
		while (!ft_isalnum(s[i]) && s[i])
		{
			if (s[i] == '-' || s[i] == '+')
			{
			 	s[0] = s[i];
				if (i > 0)
					s[i] = c;
			}
			else
				s[i] = c;
			i++;
		}
		if ((s[i + 1] == 'x' || s[i + 1] == 'X') && f->hash == 1)
		{
			s[1] = s[i + 1];
			if ((i + 1) != 1)
				s[i + 1] = c;
		}
	}
}

char	*ft_space(char *s, flags *f)
{
	int i;

	if (f->plus == 1)
		return (s); 
	i = 0;
	while (s[i] == ' ')
		i++;
	if (i == 0 && s[i] != '-' && (f->conv == 'a' || f->conv == 'A' ||
		f->conv == 'd' || f->conv == 'e' || f->conv == 'E' ||
		f->conv == 'f' || f->conv == 'F' || f->conv == 'g' ||
		f->conv == 'G' || f-> conv == 'i'))
		return (ft_strjoin(" ", s));
	else 
		return (s);
}
