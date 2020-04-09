// #include <stdio.h>
#include "inc/ft_printf.h"

int main()
{
	// s 제외한 테스트.
	// char c = 'm';
	// int d = 12345;
	// // printf("[%10c]\n", c);
	// printf("[%10d]\n", d);
	// printf("[%.10d]\n", d);
	// printf("[%3d]\n", d);
	// printf("[%.3d]\n", d);
	// printf("[%4.3d]\n", d);
	// printf("[%3.4d]\n", d);
	// printf("[%7.3d]\n", d);
	// printf("[%3.7d]\n", d); // prec은 zero=1과 같음.
	// printf("[%-7.3d]\n", d);
	// printf("[%-3.7d]\n", d); // minus는 zero
	// minus가 있으면 0은 무시됨. (아예 validcheck에서 리턴해도 될듯!!!)
	// prec이 있으면 minus=0, zero=1이 됨.
	// 이런 것들은 다 char 길이보다 prec이나 width가 커서 살아남아야.
	// 7.10은 0으로 차는데, 10.7은 0이 두칸!!!

	// char *a = "hello";
	// ft_printf("%p\n", 'a');
	// printf("%p\n", 'a');

	ft_printf("hi[%0*.*u]hello[%x]sdaf[%10X]\n", 8, 6, 123, 101723, 77742342);
	printf("hi[%0*.*u]hello[%x]sdaf[%10X]\n", 8, 6, 123, 101723, 77742342);
}
