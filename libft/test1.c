#include "libft.h"

#include <stdio.h>
#include <bsd/string.h> // gcc -lbsd 옵션 추가 필요
#include <ctype.h>

static int is_zero(int c)
{
	if (c == 0)
		return 1;
	else return 0;
}

static int ft_sign(int c)
{
	if (c < 0)
		return -1;
	else if (c == 0)
		return 0;
	else
		return 1;
}

int main()
{
	// ft_strlen
	char a[20] = "hello world!";
	if (ft_strlen(a) != strlen(a))
		printf("ft_strlen KO\n");

	// ft_atoi
	char b[20] = "  -123hello";
	if (ft_atoi(a) != atoi(a))
		printf("ft_atoi KO\n");

	// ft_isalpha ~ ft_tolower
	char c[20] = "aA01~zZ";
	int i = 0;
	while (c[i])
	{
		if (is_zero(ft_isalpha(c[i])) != is_zero(isalpha(c[i])))
			printf("ft_isalpha KO\n");
		if (is_zero(ft_isdigit(c[i])) != is_zero(isdigit(c[i])))
			printf("ft_isdigit KO\n");
		if (is_zero(ft_isalnum(c[i])) != is_zero(isalnum(c[i])))
			printf("ft_isalnum KO\n");
		if (is_zero(ft_isascii(c[i])) != is_zero(isascii(c[i])))
			printf("ft_isascii KO\n");
		if (is_zero(ft_isprint(c[i])) != is_zero(isprint(c[i])))
			printf("ft_isprint KO\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("ft_toupper KO\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("ft_tolower KO\n");
		i++;
	}

	// ft_strlcpy
	char dst1[20] = "helloworldmoon";
	char src1_lcpy[10] = "01234567";
	char dst2[20] = "helloworldmoon";
	char src2_lcpy[10] = "01234567";
	int size = 5;
	printf("ft_strlcpy: [%ld] [%s] // ", ft_strlcpy(dst1, src1_lcpy, size), dst1);
	printf("strlcpy: [%ld] [%s]\n", strlcpy(dst2, src2_lcpy, size), dst2);

	// ft_strlcat
	char lcat_dst1[20] = "hello";
	char lcat_src1[10] = "01234567";
	char lcat_dst2[20] = "hello";
	char lcat_src2[10] = "01234567";
	int lcat_size = 3; // case2. 7
	printf("ft_strlcat: [%ld] [%s] // ", ft_strlcat(lcat_dst1, lcat_src1, lcat_size), lcat_dst1);
	printf("strlcat: [%ld] [%s]\n", strlcat(lcat_dst2, lcat_src2, lcat_size), lcat_dst2);

	// ft_strchr
	char chr_s[20] = "hello world";
	int chr_c = 'l';
	printf("ft_strchr: [%s] // ", ft_strchr(chr_s, chr_c));
	printf("strchr: [%s]\n", strchr(chr_s, chr_c));	

	// ft_strrchr
	char rchr_s[20] = "hello world";
	int rchr_c = 'l';
	printf("ft_strrchr: [%s] // ", ft_strrchr(rchr_s, rchr_c));
	printf("strrchr: [%s]\n", strrchr(rchr_s, rchr_c));

	// ft_strnstr
	char big[20] = "abc cde efg";
	char little[10] = "cd";
	int nstr_n = 6; // case2. 4
	char *ft_nstr = ft_strnstr(big, little, nstr_n);
	char *nstr = strnstr(big, little, nstr_n);
	if (ft_nstr) printf("ft_strnstr: [%s] // ", ft_nstr);
	else printf("ft_strnstr: [null] // ");
	if (nstr) printf("strnstr: [%s]\n", nstr);
	else printf("strnstr: [null]\n");

	// ft_strncmp
	char s1_ncmp[20] = "aaaa";
	char s2_ncmp[20] = "aaa";
	int n_ncmp = 4;
	if (ft_sign(ft_strncmp(s1_ncmp, s2_ncmp, n_ncmp)) != ft_sign(strncmp(s1_ncmp, s2_ncmp, n_ncmp)))
		printf("ft_strncmp KO\n");
	n_ncmp = 3;
	if (ft_sign(ft_strncmp(s1_ncmp, s2_ncmp, n_ncmp)) != ft_sign(strncmp(s1_ncmp, s2_ncmp, n_ncmp)))
		printf("ft_strncmp KO\n");

	// ft_strdup
	char dup[25] = "ft_strdup OK";
	printf("%s\n", ft_strdup(dup));
	free(ft_strdup(dup));

	// ft_bzero
	char a_b[20] = "moonguwha";
	ft_bzero(a_b, 6);
	for (int i = 0; i < 9; i++)
		printf("%c", a_b[i]);
	printf(" <= wha? ft_bzero OK\n");

	// ft_memset
	char s_set[20] = "moonguwha";
	ft_memset(s_set, ' ', 6);
	printf("%s <= wha? ft_memset OK\n", s_set);

	// ft_memcpy
	char dest_cpy[20] = "1234567890";
	char src_cpy[20] = "moon";
	int n_cpy = 6; // case2. 3
	char *my_cpy = ft_memcpy(dest_cpy, src_cpy, n_cpy);
	char *real_cpy = memcpy(dest_cpy, src_cpy, n_cpy);
	printf("ft_memcpy: [%s] // ", my_cpy);
	printf("memcpy: [%s]\n", real_cpy);

	// ft_memccpy 테스트
	char dest1_ccpy[30] = "01234567890123456789"; // 포인터로 지정하면 seg 오류
	char src1_ccpy[10] = "moonguwha";
	char dest2_ccpy[30] = "01234567890123456789";
	char src2_ccpy[10] = "moonguwha";
	int c_ccpy = 'g';
	size_t n_ccpy = 8;
	char *real = memccpy(dest1_ccpy, src1_ccpy, c_ccpy, n_ccpy);
	char *my = ft_memccpy(dest2_ccpy, src2_ccpy, c_ccpy, n_ccpy);
	if (my)	printf("ft_memccpy: [%s] // ", my);
	else printf("ft_memccpy: [null] // ");
	if (real) printf("memccpy: [%s]\n", real);
	else printf("memccpy: [null]\n");

	// ft_memmove
	char s1_move[50] = "1234567890";
	ft_memmove(s1_move+4, s1_move+2, 4);
	printf("ft_memmove: [%s] // ", s1_move);
	char s2_move[50] = "1234567890";
	memmove(s2_move+4, s2_move+2, 4);
	printf("memmove: [%s]\n", s2_move);

	// ft_memcmp
	char s1_mcmp[20] = "aaaa";
	char s2_mcmp[20] = "aaa";
	// int a[10] = {1,6,1};
	// int b[10] = {1,1,2,3};
	size_t n_mcmp = 3;
	int real_mcmp = memcmp(s1_mcmp, s2_mcmp, n_mcmp);
	int my_mcmp = ft_memcmp(s1_mcmp, s2_mcmp, n_mcmp);
	if (ft_sign(my_mcmp) != ft_sign(real_mcmp))
		printf("ft_memcmp error!\n");
	n_mcmp = 4;
	real_mcmp = memcmp(s1_mcmp, s2_mcmp, n_mcmp);
	my_mcmp = ft_memcmp(s1_mcmp, s2_mcmp, n_mcmp);
	if (ft_sign(my_mcmp) != ft_sign(real_mcmp))
		printf("ft_memcmp error!\n");

	// ft_calloc
	char *cal;
	cal = (char *)ft_calloc(5, 1);
	cal[0] = 'g';
	cal[1] = 'u';
	cal[3] = 'a';
	printf("[%s] <= gu? ft_calloc OK\n", cal);

	// ft_memchr
	char s_mchr[20] = "hi hello world";
	int c_mchr = 'i';
	size_t n_mchr = 8;
	char *my_mchr = ft_memchr(s_mchr, c_mchr, n_mchr);
	char *real_mchr = memchr(s_mchr, c_mchr, n_mchr);
	if (my) printf("ft_memchr: [%s] // ", my_mchr);
	else printf("ft_memchr: [null] // ");
	if (real) printf("memchr: [%s]\n", real_mchr);
	else printf("memchr: [null]\n");

	// ft_substr
	char a_sub[20] = "helloworld";
	int start_sub = 5;
	int len_sub = 3;
	char *my_sub = ft_substr(a_sub, start_sub, len_sub);
	printf("[%s] <= wor? ft_substr OK\n", my_sub);
	free(my_sub);

	// ft_strjoin
	char a_join[10] = "hi";
	char b_join[10] = "hello";
	char *my_join = ft_strjoin(a_join, b_join);
	printf("[%s] <= hihello? ft_strjoin OK\n", my_join);
	free(my_join);

	// ft_strtrim
	char a_trim[20] = "  hello world . ";
	char b_trim[10] = " .";
	char *my_trim = ft_strtrim(a_trim, b_trim);
	printf("[%s] <= begin, end no space? ft_strtrim OK\n", my_trim);
	free(my_trim);

	// // ft_split
	// char a[50] = " hello world   moon   ";
	// char c = ' ';
	// char **test = ft_split(a, c);
	// int i = 0;
	// while (test[i])
	// {
	// 	printf("%s\n", test[i]);
	// 	i++;
	// }

	// ft_itoa
	int n_itoa = 6789;
	char *my_itoa = ft_itoa(n_itoa);
	printf("[%s] <= 6789? ft_itoa OK\n", my_itoa);
	free(my_itoa);
}
