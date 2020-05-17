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
}

// int main()
// {
//     char a[100];

//     bzero(a, 100);
//     read(0, a, 100);
//     write(1, a, 100);
// }