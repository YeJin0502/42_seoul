#include "ft_printf.h"

// va함수 test
/*
#include <stdio.h>
#include <stdarg.h>
int sum(int count, ...)
{
	int res = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++)
	{
		res += va_arg(ap, int);
		printf("res: %d\n", res);
	}
	va_end(ap);
	return (res);
}
int main()
{
	printf("[%d]\n", sum(10, 0,1,2,3,4,5,6,7,8,9));
	return 0;
}
*/

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