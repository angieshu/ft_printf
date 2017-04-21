#include "libftprintf.h"

int ft_count_num(char *p)
{
	int i;

	i = 0;
	while (*(p + i) >= '0' && *(p + i) <= '9')
		i++;
	return (i);
}

int ft_count_total_num (char *p)
{
	int i;

	i = ft_count_flags(p);
	i += ft_count_num(p + i);
	if (*(p) == '.')
		return (i + ft_count_num(p + 1) + 1);
	if (*(p + i) == '.')
		return (i + ft_count_num(p + i) + i + 1);
	return (i);
}

int		ft_count_flags(char *p)
{
	int i;

	i = 0;
	while (*(p + i) == '+' || *(p + i) == '-' || *(p + i) == ' '
		|| *(p + i) == '#' || *(p + i) == '0' || *(p + i) == '*')
		i++;
	return (i);
}
