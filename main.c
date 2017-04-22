#include "src/libftprintf.h"
#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	// int i = printf("p :%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// int j = ft_printf("f :%4.15S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// int i = printf("p :{%05.S}\n", L"42 c est cool");
	// int j = ft_printf("f :{%05.S}\n", L"42 c est cool");

	// printf("%d %d\n", i, j);

	printf("%e\n", 9.000000e+00);
	ft_printf("%e\n", 9.000000e+00);
}
