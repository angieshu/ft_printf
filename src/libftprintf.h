#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

union		data
{
	int		i;
	char	c;
	char	*s;
	double	d;
	float	f;
	long	l;
	long long ll;
};

typedef	struct
{
	int plus;
	int minus;
	int hash;
	int space;
	int zero;
	int apostrophe;
	int dollar;
	int quantity;
} occurance;

int		ft_printf(const char *restrict format, ...);

/*		Conversions			*/
char	*ft_precision(char *tmp, int n);
char	*ft_pc(va_list ap);
char	*ft_ps(va_list ap, int precision);
char	*ft_pd(va_list ap, int precision);
char	*ft_po(va_list ap, int precision);
char	*ft_px(va_list ap, int precision, char x);
char	*ft_pe(va_list ap, int precision, char e);
char	*ft_pu(va_list ap, int precision);
char	*ft_pper(void);
char	*ft_pf(va_list ap, int precision);
char	*ft_pg(va_list ap, int precision, char g);

char	*ft_identification(char *p, va_list ap, int precision);

int		ft_count_num(char *p);
int		ft_count_total_num (char *p);
int		ft_count_flags(char *p);


char	*ft_ifnumber(char *p, va_list ap, int precision);
char	*ft_flags(char *p, char *s, occurance flag);
char	*ft_check_flag(char *p, va_list ap, int precision);
char	*ft_hash(char *p, char *s);
char	*ft_minus(char *s);
char	*ft_plus(char *s);
void	ft_zero_fl(char *s, char c, occurance *flag);
char	*ft_space(char *s);

#endif