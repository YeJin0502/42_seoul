#include "ft_printf.h"
#include <stdio.h>

/*
// va함수 test
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

/*
// make_flags 테스트
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

/*
// make_flags 테스트
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

/*
// convert_flag 테스트
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

int main()
{
	// d 테스트 - 대충 완료
	// ft_printf("1. [%d]\n", 13); // [13]
	// printf("1. [%d]\n", 13); // [13]
	// ft_printf("2. [%5d]\n", 13); // [   13]
	// printf("2. [%5d]\n", 13); // [   13]
	// ft_printf("3. [%05d]\n", 13); // [00013]
	// printf("3. [%05d]\n", 13); // [00013]
	// ft_printf("4. [%-5d]\n", 13); // [13   ]
	// printf("4. [%-5d]\n", 13); // [13   ]
	// ft_printf("5. [%5.3d]\n", 13); // [  013]
	// printf("5. [%5.3d]\n", 13); // [  013]
	// ft_printf("6. [%05.3d]\n", 13); // [  013]
	// printf("6. [%05.3d]\n", 13); // [  013]
	// ft_printf("7. [%-5.3d]\n", 13); // [013  ]
	// printf("7. [%-5.3d]\n", 13); // [013  ]
	// ft_printf("8. [%-5.3d]\n", 2147483648); // 오버플로우되고, 중단은 안되니 ok
	// // printf("8. [%-5.3d]\n", 2147483648); // 에러
	
	// c 테스트 - 대충 완료
	// 에러가 떠도, 중단만 안되면 되는듯? 결과 안보는거같기도..
	// ft_printf("1. [%c]\n", 'a');
	// printf("1. [%c]\n", 'a');
	// ft_printf("2. [%5c]\n", 'a');
	// printf("2. [%5c]\n", 'a');
	// ft_printf("3. [%05c]\n", 'a');
	// // printf("3. [%05c]\n", 'a'); // 에러: c에서는 0 안쓰임.
	// ft_printf("4. [%-5c]\n", 'a');
	// printf("4. [%-5c]\n", 'a');
	// ft_printf("5. [%5.3c]\n", 'a');
	// // printf("5. [%5.3c]\n", 'a'); // 에러: c에서는 정밀도 안쓰임.
	// ft_printf("6. [%05.3c]\n", 'a');
	// // printf("6. [%05.3c]\n", 'a'); // 에러: c에서는 정밀도 안쓰임.

	// s 테스트 - 대충 완료
	// ft_printf("1. [%s]\n", "hello");
	// printf("1. [%s]\n", "hello");
	// ft_printf("2. [%10s]\n", "hello");
	// printf("2. [%10s]\n", "hello");
	// ft_printf("3. [%010s]\n", "hello");
	// // printf("3. [%010s]\n", "hello"); // 에러: s에서는 0 안쓰임.
	// ft_printf("4. [%-10s]\n", "hello");
	// printf("4. [%-10s]\n", "hello");
	// ft_printf("5. [%10.7s]\n", "hello"); // 수정 필요 -> 완료
	// printf("5. [%10.7s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 0 출력 안함.
	// ft_printf("6. [%7.10s]\n", "hello"); // 수정 필요 -> 완료
	// printf("6. [%7.10s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 아예 고려 안하는듯.
	// ft_printf("7. [%.10s]\n", "hello"); // 수정 필요 -> 완료
	// printf("7. [%.10s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 아예 고려 안하는듯.

	// u 테스트 - 대충 완료
	// ft_printf("1. [%u]\n", 13);
	// printf("1. [%u]\n", 13);
	// ft_printf("2. [%5u]\n", 13);
	// printf("2. [%5u]\n", 13);
	// ft_printf("3. [%05u]\n", 13);
	// printf("3. [%05u]\n", 13);
	// ft_printf("4. [%-5u]\n", 13);
	// printf("4. [%-5u]\n", 13);
	// ft_printf("5. [%5.3u]\n", 13);
	// printf("5. [%5.3u]\n", 13);
	// ft_printf("6. [%05.3u]\n", 13);
	// printf("6. [%05.3u]\n", 13);
	// ft_printf("7. [%-5.3u]\n", 13);
	// printf("7. [%-5.3u]\n", 13);
	// ft_printf("8. [%-5.3u]\n", -1);
	// printf("8. [%-5.3u]\n", -1); // 오버플로우되고 에러 안뜸. 결과 일치.
	// ft_printf("8. [%-5.3u]\n", 4294967295);
	// // printf("8. [%-5.3u]\n", 4294967295); // 에러가 뜨네..? u의 용도는 뭐냐..
	
	// x 테스트 - 대충 완료
	// printf("%d\n", ft_printf("1. [%x]\n", 1358));
	// printf("%d\n", printf("1. [%x]\n", 1358));
	// printf("%d\n", ft_printf("2. [%5x]\n", 1358));
	// printf("%d\n", printf("2. [%5x]\n", 1358));
	// printf("%d\n", ft_printf("3. [%05x]\n", 1358));
	// printf("%d\n", printf("3. [%05x]\n", 1358));
	// printf("%d\n", ft_printf("4. [%-5x]\n", 1358));
	// printf("%d\n", printf("4. [%-5x]\n", 1358));
	// printf("%d\n", ft_printf("5. [%5.3x]\n", 1358));
	// printf("%d\n", printf("5. [%5.3x]\n", 1358));
	// printf("%d\n", ft_printf("6. [%05.3x]\n", 1358));
	// printf("%d\n", printf("6. [%05.3x]\n", 1358));
	// printf("%d\n", ft_printf("7. [%-5.3x]\n", 1358));
	// printf("%d\n", printf("7. [%-5.3x]\n", 1358));
	// printf("%d\n", ft_printf("8. [%-5.3x]\n", -1));
	// printf("%d\n", printf("8. [%-5.3x]\n", -1)); // 오버플로우되고 에러 안뜸. 결과 일치.

	// 확인 후, x만 리턴값 확인해봄. 앞은 귀찮아서.. 일단 대충 돌아가니,
	// 메모리 구현 후, 코드 정리 들어가자.

	// p 테스트 - 대충 완료
	char *a = "hello";
	ft_printf("1. [%p]\n", a);
	printf("1. [%p]\n", a);
	ft_printf("2. [%15p]\n", a);
	printf("2. [%15p]\n", a);
	ft_printf("3. [%15.10p]\n", a);
	// printf("3. [%15.10p]\n", a); // p에선 정밀도 에러
	ft_printf("4. [%015p]\n", a);
	// printf("4. [%015p]\n", a); // p에선 0 에러
	ft_printf("5. [%-15p]\n", a);
	printf("5. [%-15p]\n", a);
}