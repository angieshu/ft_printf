#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include "../libft/libft.h"
# include <stdio.h>

union		data
{
	intmax_t i;
	uintmax_t u;
	wchar_t *ws;
	wint_t	wi;
	double	d;
	char *s;
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
	int precision;
	int min_width;
	char conv;
	uintmax_t s_size; 
} flags;

typedef struct
{
	int none;
	int hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
} length;

int		ft_printf(const char *restrict format, ...);

/*		Conversions			*/
char	*ft_precision(char *tmp, int n);

char	*ft_pd(va_list ap, flags *f, length *l);
char	*ft_pc(va_list ap, flags *f, length *l);
char	*ft_po(va_list ap, flags *f, length *l);
char	*ft_px(va_list ap, flags *f, length *l);
char	*ft_pu(va_list ap, flags *f, length *l);
char	*ft_ps(va_list ap, flags *f, length *l);
char	*ft_pws(va_list ap, flags *f);
char	*ft_pe(va_list ap, flags *f);
char	*ft_pf(va_list ap, flags *f);
char	*ft_pg(va_list ap, flags *f);
char	*ft_pper(void);

intmax_t	ft_conv_len(va_list ap, length *l);
uintmax_t	ft_conv_unsigned(va_list ap, length *l);

char	*ft_identification(char *p, va_list ap, int precision);

int		ft_count_num(char *p);
int		ft_count_total_num (char *p);
int		ft_count_flags(char *p);

int		ft_check_flag(char **format, flags *f);
char	*ft_flags(char *s, flags *f);
void	ft_reset(flags *f, length *l);

char	*ft_wprint(unsigned warg);
char	*ft_wprint_1(unsigned warg);

int		ft_check_conv_type(char **format, flags *f);
int		ft_check_minwith(char **format, flags *f);
int		ft_check_precision(char **format, flags *f);
void	ft_check_length(char **f, length *l);
char	*ft_check_format(char **format, va_list ap, flags f, length l);

void	ft_zero_fl(char *s, char c, flags *f);
char	*ft_space(char *s, flags *f);

char	*ft_build(va_list ap, flags *f, length *l);
char	*ft_min_width(char *s, flags *f);
char	*ft_extend_s(char *s, int k, char left);

#endif