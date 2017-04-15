#include "libftprintf.h"

char	*ft_build_hash(char *s, int i, int k)
{
	char *str;
	char *tmp;
	
	if (i == ft_strlen(s) - 1 && s[i] == '0')
		str = " 0";
	else if (k == 2)
		str = ft_strjoin("0", s + i);
	else if (k == 3)
		str = ft_strjoin("0x", s + i);
	else if (k == 4)
		str = ft_strjoin("0X", s + i);
	else
		return (s);
	s = ft_strdup(str);
	if (k > 2 && str[0] != ' ' && str[1] != '0')
		i--;
	tmp = (char*)ft_memalloc(i);
	tmp[--i] = 0;
	while (i-- > 0)
		tmp[i] = ' ';
	str = ft_strjoin(tmp, s);
	free(tmp);
	free(s);
	return (str);
}

char	*ft_hash(char *p, char *s)
{
	char *tmp;
	int i;
	int k;

	i = 0;
	tmp = p + ft_count_flags(p);
	tmp += ft_count_total_num(tmp);
	if (*tmp != 'o' && *tmp != 'x' && *tmp != 'X' && *tmp != 'a'
		&& *tmp != 'A' && *tmp != 'f' && *tmp != 'F' && *tmp != 'g'
		&& *tmp != 'G' && *tmp != 'e' && *tmp != 'E')
		return (NULL);
	if (*tmp == 'o')
		k = 2;
	else if (*tmp == 'x')
		k = 3;
	else if (*tmp == 'X')
		k = 4;
	else
		k = 1;
	while (s[i] == ' ')
		i++;
	return (ft_build_hash(s, i, k));
}

char	*ft_minus(char *s)
{
	char *tmp;
	char *tmp2;
	char *str;
	int i;

	i = ft_strlen(s);
	while (s[i] != ' ' && i >= 0)
		i--;
	if (i != 0)
	{
		tmp = ft_strsub(s, i + 1, ft_strlen(s) - i);
		tmp2 = ft_strsub(s, 0, i + 1);
		str = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		free(s);
		return (str);
	}
	return (s);
}

char	*ft_plus(char *s)
{
	int i;
	char *str;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[--i] == '-')
			return (s);
		if (s[i] == ' ')
			break ;
	}
	if (i == 0 && s[i] != ' ')
	{
		str = ft_strjoin("+", s);
		free(s);
		return (str);
	}
	s[i] = '+';
	return (s);
}

void	ft_zero_fl(char *s, char c, occurance *flag)
{
	int i;

	i = 0;
	while (s && flag->minus != 1)
	{
		if (s[i] == ' ')
			s[i] = c;
		else if (s[i] == '-')
		{
			s[i] = c;
			s[0] = '-';
		}
		else if (s[i] == '+')
		{
			if (flag->space != 1)
				s[i] = c;
			else
				s[i] = ' ';
			s[0] = '+';
		}
		else
			break ;
		i++;
	}
}

char	*ft_space(char *s)
{
	int i;
	char *str;
	char *tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-' || ft_isdigit(s[i]))
			break ;
		i++;
	}
	if (i == 0 && s[i] != '-')
	{
		if (s[ft_strlen(s) - 1] == ' ')
		{
			tmp = ft_strsub(s, 0, ft_strlen(s) - 1);
			str = ft_strjoin(" ", tmp);
			free(tmp);
		}
		else
			str = ft_strjoin(" ", s);
		free(s);
		return (str);
	}
	else if (s[i] != '-')
		s[i - 1] = ' ';
	return (s);
}
