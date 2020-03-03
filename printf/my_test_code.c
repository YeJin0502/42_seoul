#include "ft_printf.h"

// ft_printf 테스트
// int main()
// {
// 	ft_printf("aaa\n");
// }

// printf 테스트
#include <stdio.h>
int main()
{
	int i = 2123;
	char *str = "hello";
	printf("%% %d\n", i);
	printf("================\n");

	printf("%-10s\n", str);
	printf("%10s\n", str);
	printf("================\n");

	printf("%.10d\n", i);
	printf("%10d\n", i);
	printf("================\n");
}