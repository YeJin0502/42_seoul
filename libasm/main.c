#include "inc/libasm.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int a;

    a = ft_strlen("hello");
    printf("ft_strlen: %d\n", a);

    char *b;
    b = "test\n";
    ft_write(1, b, ft_strlen(b));

    char *c = "hello";
    char d[20] = "hihello";

    ft_strcpy(d, c);
    printf("ft_strcpy: %s\n", d);
}