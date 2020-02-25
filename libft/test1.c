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
		printf("ft_strlen ERROR!\n");

	// ft_atoi
	char b[20] = "  -123hello";
	if (ft_atoi(b) != atoi(b))
		printf("ft_atoi test1 ERROR! // ");
	char b_2[20] = "  1-23hello";
	if (ft_atoi(b_2) != atoi(b_2))
		printf("ft_atoi test2 ERROR!\n");

	// ft_isalpha ~ ft_tolower
	char c[20] = "aA01~zZ";
	int i = 0;
	while (c[i])
	{
		if (is_zero(ft_isalpha(c[i])) != is_zero(isalpha(c[i])))
			printf("ft_isalpha ERROR!\n");
		if (is_zero(ft_isdigit(c[i])) != is_zero(isdigit(c[i])))
			printf("ft_isdigit ERROR!\n");
		if (is_zero(ft_isalnum(c[i])) != is_zero(isalnum(c[i])))
			printf("ft_isalnum ERROR!\n");
		if (is_zero(ft_isascii(c[i])) != is_zero(isascii(c[i])))
			printf("ft_isascii ERROR!\n");
		if (is_zero(ft_isprint(c[i])) != is_zero(isprint(c[i])))
			printf("ft_isprint ERROR!\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("ft_toupper ERROR!\n");
		if (ft_toupper(c[i]) != toupper(c[i]))
			printf("ft_tolower ERROR!\n");
		i++;
	}

	// ft_strlcpy
	char dst1[20] = "helloworldmoon";
	char src1_lcpy[10] = "01234567";
	char dst2[20] = "helloworldmoon";
	char src2_lcpy[10] = "01234567";
	int size = 5;
	int my_lcpy = ft_strlcpy(dst1, src1_lcpy, size);
	int real_lcpy = strlcpy(dst2, src2_lcpy, size);
	if (my_lcpy != real_lcpy)
		printf("ft_strlcpy ERROR1!\n");
	if (ft_strncmp(dst1, dst2, 20) != 0)
		printf("ft_strlcpy ERROR2!\n");

	// ft_strlcat
	char dst1_lcat[20] = "hello";
	char src1_lcat[10] = "01234567";
	char dst2_lcat[20] = "hello";
	char src2_lcat[10] = "01234567";
	int size_lcat = 4;
	int my_lcat = ft_strlcat(dst1_lcat, src1_lcat, size_lcat);
	int real_lcat = strlcat(dst2_lcat, src2_lcat, size_lcat);
	if (my_lcat != real_lcat)
		printf("ft_strlcat ERROR1!\n");
	if (ft_strncmp(dst1_lcat, dst2_lcat, 20) != 0)
		printf("ft_strlcat ERROR2!\n");

	char dst3_lcat[20] = "hello";
	char src3_lcat[10] = "01234567";
	char dst4_lcat[20] = "hello";
	char src4_lcat[10] = "01234567";
	size_lcat = 5;
	my_lcat = ft_strlcat(dst3_lcat, src3_lcat, size_lcat);
	real_lcat = strlcat(dst4_lcat, src4_lcat, size_lcat);
	if (my_lcat != real_lcat)
		printf("ft_strlcat ERROR3!\n");
	if (ft_strncmp(dst3_lcat, dst4_lcat, 20) != 0)
		printf("ft_strlcat ERROR4!\n");
	// printf("ft_strlcat: [%ld] [%s] // ", my_lcat, dst3_lcat);
	// printf("strlcat: [%ld] [%s]\n", real_lcat, dst4_lcat);

	// ft_strchr
	char s_chr[20] = "hello world";
	int c_chr = 'l';
	char *my_chr = ft_strchr(s_chr, c_chr);
	char *real_chr = strchr(s_chr, c_chr);
	if (ft_strncmp(my_chr, real_chr, 20) != 0)
		printf("ft_strchr ERROR!\n");
	// printf("ft_strchr: [%s] // ", my_chr);
	// printf("strchr: [%s]\n", real_chr);	

	// ft_strrchr
	char s_rchr[20] = "hello world";
	int c_rchr = 'l';
	char *my_rchr = ft_strrchr(s_rchr, c_rchr);
	char *real_rchr = strrchr(s_rchr, c_rchr);
	if (ft_strncmp(my_rchr, real_rchr, 20) != 0)
		printf("ft_strrchr ERROR!\n");
	// printf("ft_strrchr: [%s] // ", my_rchr);
	// printf("strrchr: [%s]\n", real_rchr);

	// ft_strnstr
	char big[20] = "abc cde efg";
	char little[10] = "cd";
	int n_nstr = 6;
	char *my_nstr = ft_strnstr(big, little, n_nstr);
	char *real_nstr = strnstr(big, little, n_nstr);
	if (ft_strncmp(my_nstr, real_nstr, 20) != 0)
		printf("ft_strnstr ERROR1!\n");
	// if (my_nstr) printf("ft_strnstr: [%s] // ", my_nstr);
	// else printf("ft_strnstr: [null] // ");
	// if (real_nstr) printf("strnstr: [%s]\n", real_nstr);
	// else printf("strnstr: [null]\n");

	char big2[20] = "abc cde efg";
	char little2[10] = "cd";
	n_nstr = 4;
	char *my_nstr2 = ft_strnstr(big2, little2, n_nstr);
	if (my_nstr2)
		printf("ft_strnstr ERROR2!\n");

	// ft_memchr
	char s_mchr[20] = "hi hello world";
	int c_mchr = 'i';
	size_t n_mchr = 8;
	char *my_mchr = ft_memchr(s_mchr, c_mchr, n_mchr);
	char *real_mchr = memchr(s_mchr, c_mchr, n_mchr);
	if (ft_strncmp(my_mchr, real_mchr, 20) != 0)
		printf("ft_memchr ERROR!");
	// if (my) printf("ft_memchr: [%s] // ", my_mchr);
	// else printf("ft_memchr: [null] // ");
	// if (real) printf("memchr: [%s]\n", real_mchr);
	// else printf("memchr: [null]\n");

	// ft_strdup
	char dup[20] = "ft_strdup OK";
	if (ft_strncmp(dup, ft_strdup(dup), 20) != 0)
		printf("ft_strdup ERROR!\n");

	// ft_bzero
	char s1_b[20] = "helloworld";
	char s2_b[20] = "helloworld";
	ft_bzero(s1_b, 6);
	bzero(s2_b, 6);
	if (ft_memcmp(s1_b, s2_b, 11) != 0)
		printf("ft_bzero ERROR!\n");

	// ft_memset
	char s1_set[20] = "moonguwha";
	char s2_set[20] = "moonguwha";
	ft_memset(s1_set, ' ', 6);
	memset(s2_set, ' ', 6);
	if (ft_strncmp(s1_set, s2_set, 20) != 0)
		printf("ft_memset ERROR!\n");

	// ft_memcpy
	char dest_cpy[20] = "1234567890";
	char src_cpy[20] = "moon";
	int n_cpy = 6; // case2. 3
	char *my_cpy = ft_memcpy(dest_cpy, src_cpy, n_cpy);
	char *real_cpy = memcpy(dest_cpy, src_cpy, n_cpy);
	if (ft_memcmp(my_cpy, real_cpy, 11) != 0)
		printf("ft_memcpy ERROR!\n");
	// printf("ft_memcpy: [%s] // ", my_cpy);
	// printf("memcpy: [%s]\n", real_cpy);

	// ft_memccpy
	char dest1_ccpy[30] = "01234567890123456789"; // 포인터로 지정하면 seg error
	char src1_ccpy[10] = "moonguwha";
	char dest2_ccpy[30] = "01234567890123456789";
	char src2_ccpy[10] = "moonguwha";
	int c_ccpy = 'g';
	size_t n_ccpy = 8;
	char *real = memccpy(dest1_ccpy, src1_ccpy, c_ccpy, n_ccpy);
	char *my = ft_memccpy(dest2_ccpy, src2_ccpy, c_ccpy, n_ccpy);
	if (ft_memcmp(dest1_ccpy, dest2_ccpy, 21) != 0)
		printf("ft_memccpy ERROR1!\n");
	if (ft_strncmp(real, my, 20) != 0)
		printf("ft_memccpy ERROR2!\n");
	// if (my)	printf("ft_memccpy: [%s] // ", my);
	// else printf("ft_memccpy: [null] // ");
	// if (real) printf("memccpy: [%s]\n", real);
	// else printf("memccpy: [null]\n");

	// ft_memmove
	char s1_move[50] = "1234567890";
	ft_memmove(s1_move+4, s1_move+2, 4);
	char s2_move[50] = "1234567890";
	memmove(s2_move+4, s2_move+2, 4);
	if (ft_memcmp(s1_move, s2_move, 30) != 0)
		printf("ft_memmove ERROR!\n");
	// printf("ft_memmove: [%s] // ", s1_move);
	// printf("memmove: [%s]\n", s2_move);

	// ft_strncmp & ft_memcmp
	char s1_cmp[20] = "0123456789";
	char s2_cmp[20] = "0123456abc";
	s1_cmp[5] = '\0';
	s2_cmp[5] = '\0';
	if (ft_strncmp(s1_cmp, s2_cmp, 10) != strncmp(s1_cmp, s2_cmp, 10))
		printf("ft_strncmp ERROR1!\n");
	if (ft_memcmp(s1_cmp, s2_cmp, 10) != memcmp(s1_cmp, s2_cmp, 10))
		printf("ft_memcmp ERROR1!\n");
	char s3_cmp[10] = "aaaa";
	char s4_cmp[10] = "aaa";
	if (ft_strncmp(s3_cmp, s4_cmp, 10) != strncmp(s3_cmp, s4_cmp, 10))
		printf("ft_strncmp ERROR2!\n");
	if (ft_memcmp(s3_cmp, s4_cmp, 10) != memcmp(s3_cmp, s4_cmp, 10))
		printf("ft_memcmp ERROR2!\n");
	if (ft_strncmp(s3_cmp, s4_cmp, 3) != strncmp(s3_cmp, s4_cmp, 3))
		printf("ft_strncmp ERROR3!\n");
	if (ft_memcmp(s3_cmp, s4_cmp, 3) != memcmp(s3_cmp, s4_cmp, 3))
		printf("ft_memcmp ERROR3!\n");

	// ft_calloc
	char *cal;
	cal = (char *)ft_calloc(5, 1);
	cal[0] = 'g';
	cal[1] = 'u';
	cal[3] = 'a';
	if (ft_strncmp(cal, "gu", 5) != 0)
		printf("ft_calloc ERROR!\n");

	// ===================================================== PART1 end

	// ft_substr
	char a_sub[20] = "helloworld";
	int start_sub = 5;
	int len_sub = 3;
	char *my_sub = ft_substr(a_sub, start_sub, len_sub);
	if (ft_strncmp(my_sub, "wor", 20) != 0)
		printf("ft_substr ERROR!\n");
	// printf("[%s] <= ft_substr\n", my_sub);
	free(my_sub);

	// ft_strjoin
	char a_join[10] = "hi";
	char b_join[10] = "hello";
	char *my_join = ft_strjoin(a_join, b_join);
	if (ft_strncmp(my_join, "hihello", 10) != 0)
		printf("ft_strjoin ERROR!\n");
	// printf("[%s] <= ft_strjoin\n", my_join);
	free(my_join);

	// ft_strtrim
	char a_trim[20] = "  hello world . ";
	char b_trim[10] = " .";
	char *my_trim = ft_strtrim(a_trim, b_trim);
	if (ft_strncmp(my_trim, "hello world", 20) != 0)
		printf("ft_strtrim ERROR!\n");
	// printf("[%s] <= ft_strtrim\n", my_trim);
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
	if (ft_strncmp(my_itoa, "6789", 10) != 0)
		printf("ft_itoa ERROR!\n");
	// printf("[%s] <= ft_itoa\n", my_itoa);
	free(my_itoa);

	// ft_strmapi

	// ft_putchar_fd

	// ft_putstr_fd

	// ft_putendl_fd

	// ft_putnbr_fd

	printf("test complete.\n");
}
