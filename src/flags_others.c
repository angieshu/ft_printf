#include "libftprintf.h"

void	ft_zero_fl(char *s, char c, flags *f)
{
	int i;

	i = 0;
	if ((f->precision >= f->min_width) || f->precision == -1)
	{
		while (!ft_isalnum(s[i]))
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
