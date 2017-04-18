#include "libftprintf.h"

// char	*ft_pd(va_list ap, flags *f, length *l);
// char	*ft_ps(va_list ap, flags *f, length *l);
// char	*ft_pc(va_list ap, flags *f, length *l);
// char	*ft_po(va_list ap, flags *f, length *l);
// char	*ft_px(va_list ap, flags *f, length *l);
// char	*ft_pu(va_list ap, flags *f, length *l);
// char	*ft_ps(va_list ap, flags *f, length *l);
// char	*ft_pws(va_list ap, flags *f);
// char	*ft_pe(va_list ap, flags *f);
// char	*ft_pf(va_list ap, flags *f);
// char	*ft_pg(va_list ap, flags *f);
// char	*ft_pper(void);

char	*ft_build(va_list ap, flags *f, length *l)
{
	char *s;
	if (f->conv == 's' || f->conv == 'S')
		s = ft_ps(ap, f, l);
	else if (f->conv == 'c' || f->conv == 'C')
		s = ft_pc(ap, f, l);
	else if (f->conv == 'd' || f->conv == 'i' || f->conv == 'D')
		s = ft_pd(ap, f, l);
	else if (f->conv == 'u' || f->conv == 'U')
		s = ft_pu(ap, f, l);
	else if (f->conv == 'o' || f->conv == 'O')
		s = ft_po(ap, f, l);
	else if (f->conv == 'x' || f->conv == 'X')
		s = ft_px(ap, f, l);
	else if (f->conv == '%')
		s = ft_pper();
	else if (f->conv == 'e' || f->conv == 'E')
		s = ft_pe(ap, f);
	else if (f->conv == 'f' || f->conv == 'F')
		s = ft_pf(ap, f);
	else
		s = ft_pg(ap, f);
	s = ft_min_width(s, f);
	s = ft_flags(s, f);
	return (s);
}