#include "libftprintf.h"

// char	*null_s(flags *f)
// {
// 	char *s;
// 	int len;

// 	len = 2;
// 	s = (char*)malloc(2);
// 	while (len-- >= 0)
// 		s[len] = '\0';
// 	return (s);
// }

// char	*ft_pc(va_list *ap, flags *f, length *l)
// {

// 	union data type;
// 	char *s;

// 	if ((l->l == 1 && f->conv == 'c') || f->conv == 'C')
// 	{
// 		type.wi = va_arg(*ap, wint_t);
// 				// return(ft_wprint(type.wi));
// 		if (!type.wi)
// 		{
// 			f->precision = -5;
// 			s = "";
// 		}
// 		else
// 			s = ft_wprint(type.wi);
// 		// printf("%s\n", s);
// 		f->min_width -= 1;
// 		// return (s);
// 	}
// 	else
// 	{
// 		type.i = va_arg(*ap, intmax_t);
// 		// if (!type.i)
// 		// {
// 		// 	f->s_size++;
// 		// 	f->min_width -= 1;
// 		// 	s = ft_strnew(0);
// 		// 	// return (ft_strnew(0));
// 		// }
// 		// else
// 		// {
// 			s = ft_strnew(1);
// 			s[0] = type.i;
// 		// }
// 		s = ft_precision(s, f->precision - ft_strlen(s));
// 	}
// 	return (s);
// }

char	*ft_pc(va_list *ap, flags *f, length *l)
{

	union data type;
	char *s;

	if ((l->l == 1 && f->conv == 'c') || f->conv == 'C')
	{
		type.wi = va_arg(*ap, wint_t);
		if (!type.wi)
			return (ft_strnew(1));
		s = ft_wprint(type.wi);
		return (s);
	}
	type.i = va_arg(*ap, intmax_t);
	if (!type.i)
	{
		f->s_size++;
		f->min_width -= 1;
		s = ft_strnew(1);
		return (s);
	}
	s = ft_strnew(1);
	s[0] = type.i;
	return (s);
}

char	*ft_pd(va_list *ap, flags *f, length *l)
{
	union data	type;
	intmax_t	i;
	char		*s;

	if (f->conv == 'D')
		l->l = 1;
	type.i = ft_conv_len(ap, l);
	if (type.i == 0 && f->precision == 0)
		return (ft_strnew(0));
	else if (type.i == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
	}
	else
		s = ft_itoa_signed(type.i);
	i = ft_strlen(s);
	if (i <= f->precision)
	{
		if (type.i < 0)
			f->precision += 1;
		s = ft_precision(s, f->precision - i);
	}
	return (s);
}

char	*ft_po(va_list *ap, flags *f, length *l)
{
	union data	type;
	intmax_t	i;
	char		*s;
	char		*tmp;

	if (f->conv == 'O')
		l->l = 1;
	type.u = ft_conv_unsigned(ap, l);
	if (type.u == 0 && f->precision == 0 && f->hash != 1)
		return (ft_strnew(0));
	else if (type.u == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	s = ft_itoa_unsigned(type.u, 8);
	i = ft_strlen(s);
	if (i < f->precision)
		s = ft_precision(s, f->precision - i);
	if (f->hash == 1)
	{
		tmp = s;
		s = ft_strjoin("0", tmp);
	}
	return (s);
}

char	*ft_px(va_list *ap, flags *f, length *l)
{
	union data	type;
	intmax_t	i;
	char		*s;
	char		*tmp;

	type.u = ft_conv_unsigned(ap, l);
	if (type.u == 0 && f->precision == 0)
		return (ft_strnew(0));
	else if (type.u == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	s = ft_itoa_unsigned(type.u, 16);
	i = ft_strlen(s);
	if (i < f->precision)
		s = ft_precision(s, f->precision - i);
	if (f->hash == 1)
	{
		tmp = s;
		s = ft_strjoin("0x", tmp);
	}
	if (f->conv == 'X')
		ft_toupper_s(s);
	return (s);
}
