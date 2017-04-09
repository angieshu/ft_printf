#include "libftprintf.h"

int		ft_precision(char *tmp, int n)
{
	char *tmp2;
	char *s;
	int len;

	tmp2 = (char*)ft_memalloc(n + 1);
	tmp2[n] = 0;
	while (n-- > 0)
		tmp2[n] = '0';
	s = ft_strjoin(tmp2, tmp);
	ft_putstr(s);
	len = ft_strlen(s);
	free(tmp);
	free(tmp2);
	free(s);
	return (len);
}