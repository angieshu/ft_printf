#include "libftprintf.h"

char	*ft_pws(va_list ap, flags *f)
{
	union data	type;
	intmax_t	len;
	char		*tmp;
	char		*tmp2;
	char		*s;

	len = 0;
	s = ft_strnew(1);
	type.ws = va_arg(ap, wchar_t*);
	if (!type.ws)
		return (NULL);
	while (type.ws)
	{
		tmp = ft_wprint(*type.ws);
		if ((len + ft_strlen(tmp)) > f->precision
			&& f->precision > 0)
		// {
		// 	free(tmp);
			break ;
		// }
		tmp2 = s;
		s = ft_strjoin(tmp2, tmp);
	}
	free(tmp);
	return (s);
}

char	*ft_ps(va_list ap, flags *f, length *l)
{
	union data	type;
	intmax_t	i;

	if ((l->l == 1 && f->conv == 's') || f->conv == 'S')
		return (ft_pws(ap, f));
	// {
	// 	type.ws = va_arg(ap, wchar_t*);
	// 	while (ws)
	// 	{
	// 		if (!type.ws)
	// 			return (NULL);
	// 		else
	// 		{

	// 		}
	// 	}
		
	// }
	type.s = va_arg(ap, char*);
	i = ft_strlen(type.s);
	if (f->precision == -1)
		f->precision = i;
	if (f->precision < i)
		return (ft_strsub(type.s, 0, f->precision));
	return (ft_strdup(type.s));
}
