#include <stdio.h>
int main(int argc, char **argv)
{
    printf("argc: %d\n", argc);
    while (*argv)
    {
        printf("%s\n", *argv);
        argv++;
    }
}