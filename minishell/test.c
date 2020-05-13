#include <stdio.h>

// int main(int argc, char **argv)
// {
//     printf("argc: %d\n", argc);
//     while (*argv)
//     {
//         printf("%s\n", *argv);
//         argv++;
//     }
// }

// #include <fcntl.h>
// #include <unistd.h>
// int main()
// {
//     int fd = open("test", O_WRONLY |O_CREAT | O_TRUNC, 0744);
//     write(fd, "hello", 5);
// }

#include <unistd.h>
int main()
{
    write(2, "hello", 5);
}