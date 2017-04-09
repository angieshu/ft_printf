#include "libft.h"

char	*ft_itoa_double_g(double nbr, int k)
{
	int count;
	char *s;
	char *tmp;
	long n;

	if (nbr == 0)
		return ("0");
	n = (long)nbr;
	count = ft_countnumber(n, 10);
	if (count >= k)
		return (ft_itoa_double(nbr, 0));
	tmp = ft_itoa_double(nbr, k - count);
	count = ft_strlen(tmp);
	while (count-- > 0)
	{
		if (tmp[count] != '0' && tmp[count] != '.')
			break ;
	}
	s = ft_strsub(tmp, 0, ++count);
	free(tmp);
	return (s);
}