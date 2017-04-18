#include "libftprintf.h"

// void	ft_count_wsize(unsigned warg, flags *f)
// {
// 	if (warg < 0x80)
// 		f->s_size++;
// 	else if (warg <= 0x7FF)
// 		f->s_size += 2;
// 	else if (warg <= 0xFFFF)
// 		f->s_size += 3;
// 	else if (warg <= 0x10FFFF)
// 		f->s_size += 4;
// }

char	*ft_wprint(unsigned warg)
{
	char *s;

	if (warg < 0x80)
	{
		s = ft_strnew(1);
		s[0] = warg;
	}
	else if (warg <= 0x7FF)
	{
		s = ft_strnew(2);
		s[0] = (warg >> 6) + 0xC0;
		s[1] = (warg & 0x3F) + 0x80;
	}
	else
		return (ft_wprint_1(warg));
	return(s);
}

char	*ft_wprint_1(unsigned warg)
{
	char *s;

	s = NULL;
	if (warg <= 0xFFFF)
	{
		s = ft_strnew(3);
		s[0] = (warg >> 12) + 0xE0;
		s[1] = ((warg >> 6) & 0x3F) + 0x80;
		s[2] = (warg & 0x3F) + 0x80;
	}
	else if (warg <= 0x10FFFF)
	{
		s = ft_strnew(4);
		s[0] = (warg >> 18) + 0xF0;
		s[1] = ((warg >> 12) & 0x3F) + 0x80;
		s[2] = ((warg >> 6) & 0x3F) + 0x80;
		s[3] = (warg & 0x3F) + 0x80;
	}
	return (s);
}
