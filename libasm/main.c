#include "inc/libasm.h"

int main()
{
    printf("\n");
    printf("START=================\n");
    char *a = "test";

    printf("ft_strlen: %ld\n", ft_strlen(a));
    printf("strlen: %ld\n", strlen(a));

    printf("======================\n");
    int fd;
    char buf;
    fd = open("test", O_RDONLY);
    while (ft_read(fd, &buf, 1))
        ft_write(1, &buf, 1);

    printf("======================\n");
    printf("ft_read error test: %ld\n", ft_read(80, &buf, 1));
    printf("read error test: %ld\n", ft_read(80, &buf, 1));
    char test = -1;
    printf("ft_write error test: [%ld]\n", ft_write(1, &test, 1));
    printf("write error test: [%ld]\n", ft_write(1, &test, 1));

    printf("======================\n");
    char c[20] = "hihello";
    char *d = "ft_strcpy test.";

    ft_strcpy(c, d);
    printf("%s\n", c);

    printf("======================\n");
    char *e = "hello";
    char *f = "helloworld";

    printf("ft_strcmp: %d\n", ft_strcmp(e, f));
    printf("strcmp: %d\n", strcmp(e, f));

    printf("======================\n");
    char *g = "ft_strdup test.";

    printf("%s\n", ft_strdup(g));

    printf("===================END\n");
    printf("\n");
}
