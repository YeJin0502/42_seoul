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

// ft_printf 테스트
// int main()
// {
// 	// ft_printf("===============\n"); //OK

// 	// char *a = "hihello";
// 	ft_printf("1: [%d]\n", 2147483648); // 오버, 언더플로우 관리해야.
// 	ft_printf("2: [%u]\n", -1);
// 	ft_printf("3: [%c]\n", 'M');
// 	// ft_printf("4: [%p]\n", a);
// 	// printf("4real: [%p]\n", a);
// 	printf("%d\n", ft_printf("5: [%x]\n", 4294967295)); // 일단 이건 맞음.
// }

// printf 테스트
// int main()
// {
// 	printf("[%8c]\n", 'M'); // c: 폭 가능
// 	// printf("%.8c\n", 'M'); // c: 정밀도는 불가능
// 	printf("[%08c]\n", 'M'); // c: 0 불가능
// 	// printf()
// }

// printf 테스트
int main()
{
	// printf("[%-05d]\n", 123);
	// -와 0은 같이 못있음.
	
	// printf("[%5d]\n", 123); // [  123]
	// printf("[%05d]\n", 123); // [00123]
	// printf("[%.5d]\n", 123); // [00123]
	// // d에선 0과 .이 같은 역할?

	// printf("[%5d]\n", 123); // [123  ]
	// printf("[%.5d]\n", 123); // [00123]
	// printf("[%5.5d]\n", 123); // [00123]
	// printf("[%-5.5d]\n", 123); // [00123]
	// printf("[%05.5d]\n", 123); // [00123]
	// // 우선순위: .5 > - > 5 ?

	printf("[%0d]\n", 123); // [123]
	printf("[%-d]\n", 123); // [123]
	// -와 0은 폭이 없으면 무용지물
	printf("[%0.5d]\n", 123); // [123]
	printf("[%-.5d]\n", 123); // [123]
	// -와 0은 폭이 없으면 무용지물. 정밀도는 우선순위가 1위라... 정밀도 있으면 - 소용없음.

	// printf("[%4.5d]\n", 123); // [00123] 중요!
	// printf("[%5.4d]\n", 123); // [ 0123] 중요! 이 두개가 가장 핵심!!
}

/*
#include <stdio.h>
int main()
{
	// char *a = convert_flag("123", "4.6");
	// printf("[%s]\n", a);
	// printf("[%4.6d]\n", 123);

	// char *b = convert_flag("123", "6.4");
	// printf("[%s]\n", b);
	// printf("[%6.4d]\n", 123);

	// char *c = convert_flag("123", "-6.4");
	// printf("[%s]\n", c);
	// printf("[%-6.4d]\n", 123);

	// char *d = convert_flag("123", "06.4");
	// printf("[%s]\n", d);
	// printf("[%06.4d]\n", 123);

	// char *a = convert_flag("123", "-4");
	
	printf("[%-4d]\n", 123); // [123 ]
	printf("[%04d]\n", 123); // [0123]
	printf("[%4d]\n", 123); // [ 123]
	ft_printf("[%4d]\n", 123);

	// printf("[%-10.6d]\n", 123); // [000123   ]
	// printf("[%10.6d]\n", 123); // [   000123]
}
*/