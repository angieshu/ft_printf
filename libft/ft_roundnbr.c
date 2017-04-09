#include "libft.h"
#include <stdio.h>
long		ft_roundnbr(long n, int i)
{
	long k;
	int d;

	k = (n / ft_power(10, i) + 1) * ft_power(10, i);
	d = k - n;
	printf("%d\n", d);
	if (d < 6)
		n += d;
	else
		n = n - ft_power(10, i) + d;
	return (n);
}