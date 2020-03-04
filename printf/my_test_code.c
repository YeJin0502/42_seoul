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
/*
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
*/

/*
// 테스트
int main()
{
	char a[10] = "hello";
	ft_printf("%d\n%u\n%p\n%c\n", 2147483648, -1, a, "Moon"); // 이런 값들 고쳐야.

	printf("%p\n", a);
	// char **test = make_flags("moon%-d\n", 1);
	// printf("%s\n", test[0]);
	// free(test[0]);
	// free(test);	


	// char *a = "hi %s hello%s%s";
	// ft_printf(a, "MOON", "GU", "WHA");

	// ft_printf("hello %d %d %d ", 1, 2, 3);
	// ft_printf("hello%d%d%d", 1, 2, 3);
	// ft_printf("hello %c%c%c%c", 'm', 'o', 'o', 'n');

	// ft_printf("===============\n");
}
*/

// make_flags 테스트
/*
int main()
{
	char **test = make_flags("hi%--dhello%-0dworld%-.s", 3);
	int i;
	i = 0;
	while (i < 3)
	{
		printf("%s\n", test[i]);
		i++;
	}
	while (i > 0)
	{
		free(test[i - 1]);
		i--;
	}
	free(test);
}
*/