#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// mem 전까지 테스트
/*
int main()
{
	// char a[20] = "hello world!";
	// printf("%lu\n", ft_strlen(a));

	// char b[20] = "  -123hello";
	// printf("%d\n", ft_atoi(b));

	// char c = 'a';
	// printf("%c\n", ft_tolower(c));
	// printf("%c\n", tolower(c));

	// char dst[20] = "helloworldmoon";
	// char src[10] = "01234567";
	// printf("%ld\n", ft_strlcpy(dst, src, 9));
	// printf("%s\n", dst);

	// char dst1[20] = "hello";
	// char src1[10] = "01234567";
	// int n = 10;
	// printf("%ld\n", ft_strlcat(dst1, src1, n));
	// printf("%s\n", dst1);

	// char a[20] = "hello world";
	// int c = 'l';
	// printf("%s\n", ft_strrchr(a, c));

	// char big[20] = "abc cde efg";
	// char little[10] = "bc";
	// char *test = ft_strnstr(big, little, 7);
	// if (test)
	// 	printf("%s\n", test);
	// else
	// 	printf("null\n");

	// char *s1 = "aaa";
	// char *s2 = "aa";
	// int n = 10;
	// int real = strncmp(s1, s2, n);
	// int my = ft_strncmp(s1, s2, n);
	// printf("%d\n", real);
	// printf("%d\n", my);

	// char a[20] = "hello world";
	// printf("%s\n", ft_strdup(a));
	// free(ft_strdup(a));
}
*/

// ft_strchr 공부
/*
// 테스트할때마다 내가 헷갈리는 내용이 있음.
int main()
{
	char s1[30] = "A Garden Diary";
	// char s2[30] = "A Garden Diary";
	int test = 'a';
	char *a = strchr(s1, test); // s1이 이동되는건 아니라 s2가 필요 없다는데? 헷갈림.
	printf("%s\n", s1); // 그 증거가 이거. 함수를 써도 그대로 전체가 프린트됨.
	char *b = ft_strchr(s1, test); // 다른 함수로 넘어갈 때, 독립적으로 주소를 받는거라 그렇다고 함..

	printf("%s\n", a);
	printf("%s\n", b);
}
*/

// ft_strlcat 공부
/*
#include <stdio.h>
int main()
{
	char dest1[20] = "moon";
	char src1[20] = "hihello";
	// char dest2[20] = "moon";
	// char src2[20] = "hihello";
	int size = 20; // 3까지는 size+src, 4부터는 dest+src (11).

	int a = ft_strlcat(dest1, src1, size);
	printf("%d\n", a);
	printf("%s\n", dest1);

	// int b= ft_strlcat2(dest2, src2, size);
	// printf("%d\n", b);
	// printf("%s\n", dest2);
}
*/

// strnstr 공부
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char big[30] = "Foo Bar Baz";
	char little[10] = "Foo";
	int len = 3;
	char *my = ft_strnstr(big, little, len);
	char *real = strnstr(big, little, len);

	if (my)
		printf("my: %s\n", my);
	else
		printf("null\n");

	if (real)
		printf("real: %s\n", real);
	else
		printf("null\n");
}
*/
/* 포인터가 null 가르킬때 프린트하면 원래 segmentation 뜨는건데...
그걸 몰라서 함수가 잘못된 줄 알았다. TT
따라서 null이 아닐 때만 프린트하도록 조건문을 달아주어야 좋다.

그리고 strnstr 테스트를 위해...
sudo apt install libbsd-dev 해주었고, 헤더에 bsd/를 추가해주고,
컴파일할때 -lbsd 추가. */
