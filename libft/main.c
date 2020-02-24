#include "libft.h"
#include <stdio.h>

int main()
{
	char a[20] = "hello world";
	char *b = ft_strdup(a);
	printf("%s\n", b);
}