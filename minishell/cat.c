#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char a;

    while (scanf("%c", &a) > 0)
        printf("%c", a);
    // echo hello | ./a.out
    // : hello
}