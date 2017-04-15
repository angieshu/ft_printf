#include "libftprintf.h"

char	*ft_precision(char *tmp, int n)
{
	char *tmp2;
	char *s;

	tmp2 = (char*)ft_memalloc(n + 1);
	tmp2[n] = 0;
	while (n-- > 0)
		tmp2[n] = '0';
	s = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	return (s);
}