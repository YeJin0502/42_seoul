#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int is_zero(int c)
{
	if (c == 0)
		return 1;
	else return 0;
}

int main()
{
	// ft_strlen
	char a[20] = "hello world!";
	if (ft_strlen(a) != strlen(a))
		printf("1. ft_strlen KO\n");

	// ft_atoi
	char b[20] = "  -123hello";
	if (ft_atoi(a) != atoi(a))
		printf("2. ft_atoi KO\n");

	// ft_isalpha ~ ft_tolower
	char c[20] = "aA01~zZ";
	int i = 0;
	while (c[i])
	{
		if (is_zero(ft_isalpha(c[i])) != is_zero(isalpha(c[i])))
			printf("3. ft_isalpha KO\n");
		if (is_zero(ft_isdigit(c[i])) != is_zero(isdigit(c[i])))
			printf("4. ft_isdigit KO\n");
		if (is_zero(ft_isalnum(c[i])) != is_zero(isalnum(c[i])))
			printf("5. ft_isalnum KO\n");
		if (is_zero(ft_isascii(c[i])) != is_zero(isascii(c[i])))
			printf("6. ft_isascii KO\n");
		if (is_zero(ft_isprint(c[i])) != is_zero(isprint(c[i])))
			printf("7. ft_isprint KO\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("8. ft_toupper KO\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("9. ft_tolower KO\n");
		i++;
	}



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


/*
// ft_strchr 공부
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

/*
// ft_strlcat 공부
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

/*
// strnstr 공부
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

/*
// ft_substr 테스트
int main()
{
	char a[20] = "helloworld";
	char *test = ft_substr(a, 3, 4);
	printf("%s\n", test);
	free(test);
}
*/

/*
// ft_substr 테스트
int main()
{
	char a[10] = "hi";
	char b[10] = "hello";
	char *test = ft_strjoin(a, b);
	printf("%s\n", test);
	free(test);
}
*/

/*
// ft_strtrim 테스트
int main()
{
	char a[20] = "  hello world .";
	char b[10] = " .";
	char *test = ft_strtrim(a, b);
	printf("%s\n", test);
	free(test);
}
*/

/*
// ft_split 테스트
int main()
{
	char a[50] = " hello world   moon   ";
	char c = ' ';

	// printf("%d\n", word_count(a, c));
	// printf("%d\n", word_len(a, c));

	char **test = ft_split(a, c);

	int i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
}
*/

/*
// ft_memmove 테스트
int main()
{
	char str1[50] = "1234567890";
	printf("%s\n", str1);
	memmove(str1+2, str1+4, 6);
	printf("%s\n", str1);

	char str2[50] = "1234567890";
	printf("%s\n", str2);
	ft_memmove(str2+2, str2+4, 6);
	printf("%s\n", str2);
}
*/

/*
// ft_memset 테스트
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20] = "helloworld";
	char str2[20] = "helloworld";

	printf("%s\n", str1);
	memset(str1, '.', sizeof(str1) - 1);
	printf("%s\n", str1);	
	printf("-------------------\n");
	printf("%s\n", str2);
	ft_memset(str2, '.', sizeof(str2) - 1);
	printf("%s\n", str2);	
}
*/

/*
// ft_memcpy 테스트... 원래는 위에꺼도 안돼야되는거같은데. 되네..? 환경문제?
int main()
{
	char a[50] = "1234567890";
	memcpy(a+4, a+2, 4);
	printf("%s\n", a);

	char b[50] = "1234567890";
	ft_memcpy(b+4, b+2, 4);
	printf("%s\n", b);
}
*/

/*
// ft_memcmp 테스트
int main()
{
	char s1[20] = "aaaa";
	char s2[20] = "aaa";
	// int a[10] = {1,6,1};
	// int b[10] = {1,1,2,3}; // 이건 왜 다르게해도 0만 나오지.. 뭘까
	size_t n = 8; // 7까지는 1이 나오다가 8부터 갑자기 97이 나온다... 뭐냐
	int real = memcmp(s1, s2, n);
	int my = ft_memcmp(s1, s2, n);
	
	printf("%d\n", real);
	printf("%d\n", my);
}
*/

/*
// ft_memccpy 테스트
int main()
{
	char dest1[50] = "01234567890123456789"; // 포인터로 지정하면 seg 오류
	char src1[10] = "moonguwha";
	char dest2[50] = "01234567890123456789";
	char src2[10] = "moonguwha";
	int c = 'a'; // g가 있어서 moong까지만 복사.
	size_t n = 8; // c 없으면 7글자 복사.

	char *real = memccpy(dest1, src1, c, n);
	char *my = ft_memccpy(dest2, src2, c, n);
	printf("%s\n", dest1);
	if (real)
		printf("%s\n", real);
	else
		printf("null\n");
	printf("=============\n");
	printf("%s\n", dest2);
	if (my)
		printf("%s\n", my);
	else
		printf("null\n");
}
*/

/*
// ft_bzero
int main()
{
	char a[20] = "moonguwha";
	printf("%s\n", a);
	ft_bzero(a, 3);
	int i;
	i = 0;
	while (i < 10)
	{
		printf("%c", a[i]);
		i++;
	}
}
*/

/*
// ft_memchr 테스트
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "hi hello world";
	int c = 'm';
	size_t n = 8;

	char *real = memchr(a, c, n);
	char *my = ft_memchr(a, c, n);
	if (real)
		printf("%s\n", real);
	else
		printf("null\n");
	if (my)
		printf("%s\n", my);
	else
		printf("null\n");
}
*/

/*
// ft_calloc
int main()
{
	char *a;
	a = (char *)ft_calloc(5, 1);
	a[0] = 'm';
	a[1] = 'o';
	a[3] = '0';

	printf("%s\n", a);
}
*/
/* ret의 형식을 처음에 void로 하면 ret이 수정할 수 없는 value라는 에러가 뜸.
char로 해서 1바이트씩 모두 0으로 바꿔주는 식으로 에러 수정...
은 물어봐서 안거지 사실 잘 모르겠다. */

/*
// ft_itoa
#include <stdio.h>
int main()
{
	int n = 6789;
	printf("%d\n", n_size(n));
	char *test = ft_itoa(n);
	printf("%s\n", test);
	free(test);
}
*/