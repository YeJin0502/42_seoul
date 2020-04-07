#include <stdio.h>

int main()
{
    char *a = "\0";
    char *b = "";
    char *c = 0;

    printf("[%s]\n", a);
    printf("[%s]\n", b);
    printf("[%s]\n", c);
}