#include "libftprintf.h"

char	*ft_check_flag(char *p, va_list ap, int precision)
{
	occurance flag;
	char *s;
	int i;

	i = ft_count_flags(p);
	flag.quantity = i;
	if (!(s = ft_ifnumber(p + i, ap, precision)))
		return (NULL);
	while (i-- > 0)
	{
		if (*(p + i) == '+')
			flag.plus = 1;
		else if (*(p + i) == '-')
			flag.minus = 1;
		else if (*(p + i) == '0')
			flag.zero = 1;
		else if (*(p + 1) == '#')
			flag.hash = 1;
		else if (*(p + i) == ' ' && flag.space != 1)
			flag.space = 1;
		else if (*(p + i) == '$')
			flag.dollar = 1;
		else if (*(p + i) == '\'')
			flag.apostrophe = 1;
	}
	return (ft_flags(p, s, flag));
}

char	*ft_flags(char *p, char *s, occurance flag)
{
	if (flag.hash == 1)
		s = ft_hash(p, s);
	if (flag.plus == 1)
		s = ft_plus(s);
	if (flag.minus == 1)
		s = ft_minus(s);
	if (flag.space == 1)
		s = ft_space(s);
	if (flag.zero == 1)
		ft_zero_fl(s, '0', &flag);
	if (flag.dollar == 1)
		ft_zero_fl(s, '$', &flag);
	if (!s)
		return (NULL);
	return (s);
}
