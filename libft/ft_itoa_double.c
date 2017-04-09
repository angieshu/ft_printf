#include "libft.h"

static char *zero(int k)
{
	char *s;

	s = (char*)ft_memalloc(k + 3);
	s[k + 2] = '\0';
	while (--k >= 0)
	{
		s[k + 2] = '0';
		if (k == 0)
			s[1] = '.';
	}
	s[0] = '0';
	return (s);
}

static char	*build(long n, int k, int i)
{
	char *n_nbr;

	n_nbr = (char*)ft_memalloc(i + 1);
	n_nbr[i] = '\0';
	while (--k >= 0 || n > 0)
	{	
		n_nbr[--i] = (n % 10) + '0';
		n /= 10;
		if (k == 0)
		{
			n_nbr[--i] = '.';
			if (n == 0)
				n_nbr[--i] = '0';
		}
	}
	if (i > 0)
		n_nbr[0] = '-';
	return (n_nbr);
}

char	*ft_itoa_double(double nbr, int k)
{
	int sign;
	long i;
	long n;
	long nbrcpy;

	i = 1;
	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = 1;
	}
	if (nbr == 0.0)
		return (zero(k));
	if (nbr < 1)
		i++;
	nbr *= ft_power(10, k + 1);
	n = (long)nbr;
	if (((((n / 10) + 1) * 10) - n) < 6)
		n = n + 10;
	nbrcpy = n;
	while ((nbrcpy = nbrcpy / 10) > 1)
		i++;
	if (k == 0)
		i--;
	return (build(n / 10, k, i + sign));
}