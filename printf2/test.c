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

	printf("[%.p]\n", NULL); // 정밀도 있으면 0 옵션 사라짐.
	ft_printf("[%.p]\n", NULL); // 정밀도 있으면 0 옵션 사라짐.

	// printf("<%s>\n", dec_to_hex(0, 'x'));
	// char *a = "hello";
	// ft_printf("%p\n", 'a');
	// printf("%p\n", 'a');

	// ft_printf("hi[%0*.*u]hello[%x]sdaf[%10X]\n", 8, 6, 123, 101723, 77742342);
	// printf("hi[%0*.*u]hello[%x]sdaf[%10X]\n", 8, 6, 123, 101723, 77742342);

	/* s 테스트
	7.0 [       ]
	7.3 [    hel]
	10.6 [     hello]
	6.10 [ hello] // s에는 zero가 안들어감.
	.10 [hello] // 정밀도는 len과 prec중 작은 것.
	.3 [hel]
	4.3 [ hel] // size는 len과 width 중 작은 것.
	3.4 [hell]
	*/
	// ft_printf("[%7.0s]\n", "hello");
	// ft_printf("[%7s]\n", "hello");
	// ft_printf("[%7.3s]\n", "hello");
	// ft_printf("[%6.10s]\n", "hello");
	// ft_printf("%3sM\n", "hello");
	// ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);

	// printf("[%3s]\n", "hello"); // [hello]
	// printf("[%32s]\n", "hello"); // [     ~   hello	printf("[%3s]\n", "hello"); // [hello]
	// ft_printf("[%3s]\n", "hello"); // [     ~   hello	printf("[%3s]\n", "hello"); // [hello]
	// ft_printf("[%32s]\n", "hello"); // [     ~   hello]

	// ft_printf("[%.6i]\n", -2);
	// printf("[%.6i]\n", -2);
	// ft_printf("[%6i]\n", -2);
	// printf("[%6i]\n", -2);
	
	// ft_printf("[%0.6i]\n", 34);
	// printf("[%0.6i]\n", 34);

	// ft_printf("[%-0.6d]\n", 34);
	// printf("[%-0.6d]\n", 34);
}
