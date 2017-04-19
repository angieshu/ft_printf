// #include "libftprintf.h"

// char	*ft_build_hash(char *s, int i, flags *f)
// {
// 	char *str;

// 	if (i == ft_strlen(s) - 1 && s[i] == '0')
// 	{
// 		str = ft_strnew(2);
// 		str[0] = ' ';
// 		str[1] = '0';
// 	}
// 	else if (f->conv == 'o' || f->conv == 'O')
// 		str = ft_strjoin("0", s + i);
// 	else if (f->conv == 'x')
// 		str = ft_strjoin("0x", s + i);
// 	else if (f->conv == 'X')
// 		str = ft_strjoin("0X", s + i);
// 	else
// 		return (NULL);
// 	free(s);
// 	return (str);
// }

// char	*ft_hash(char *s, flags *f)
// {
// 	int i;
// 	char *str;
// 	char *tmp;
// 	char *tmp2;

// 	i = 0;
// 	while (s[i] == ' ')
// 		i++;
// 	if (!(tmp2 = ft_build_hash(s, i, f)))
// 		return (s);
// 	if (i > 1)
// 	{
// 		if ((f->conv == 'x' || f->conv == 'X') && !(tmp2[0] == ' '
// 			&& tmp2[1] == '0'))
// 			i--;
// 		tmp = ft_strnew(i - 1);
// 		while (--i >= 0)
// 			tmp[i] = ' ';
// 		str = ft_strjoin(tmp, s);
// 		free(tmp);
// 		free(tmp2);
// 		return (str);
// 	}
// 	return (tmp2);
// }