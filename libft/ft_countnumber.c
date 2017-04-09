#include "libft.h"

int	ft_countnumber(long v, int b)
{
	int		i;

	i = 0;
	if (v < 0)
	{
		i = i + 1;
		v = v * -1;
	}
	while (v > 0)
	{
		i = i + 1;
		v = v / b;
	}
	return (i);
}