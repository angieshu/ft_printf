#include "src/libftprintf.h"
#include <stdio.h>
#include <locale.h>

int main ()
{	
	char *str = NULL;
	setlocale(LC_ALL, "en_US.UTF-8");
	// int i = printf("p :%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// int j = ft_printf("f :%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// int i = printf("p :{%05.S}\n", L"42 c est cool");
	// int j = ft_printf("f :{%05.S}\n", L"42 c est cool");

	// printf("%d %d\n", i, j);

	printf("p ::{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_printf("f ::{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// printf("%s\n", ft_itoa_double_g(-342.3, 2));
	// ft_printf("%g\n", -342.3);
}
