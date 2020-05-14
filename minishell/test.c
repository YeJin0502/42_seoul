#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

// int main(int argc, char **argv)
// {
//     printf("argc: %d\n", argc);
//     while (*argv)
//     {
//         printf("%s\n", *argv);
//         argv++;
//     }
// }

// int main()
// {
//     int fd = open("test", O_WRONLY |O_CREAT | O_TRUNC, 0744);
//     write(fd, "hello", 5);
// }

// int main()
// {
//     int fd[2];
//     char buffer[1024];
//     pid_t pid;
//     int state;

//     pipe(fd);
//     pid = fork();
//     if (pid == 0)
//     {
//         write(fd[1], "connect\n", 20);
//         sleep(2);
//         read(fd[0], buffer, 1024);
//         printf("Output of chile process: %s\n", buffer);
//     }
//     else
//     {
//         read(fd[0], buffer, 1024);
//         printf("Output of parent process: %s\n", buffer);
//         write(fd[1], "good job\n", 20);
//         sleep(2);
//     }
//     return (0);
// }

int main(void)
{
    char *fname = "result.txt";
    int fd1, fd2;

    if ((fd1 = creat(fname, 0666)) < 0)
    {
        printf("creat error\n");
        return (1);
    }
    printf("First one is on the screen.\n");
    fd2 = dup2(fd1, 1);
    printf("Second one is in this file.\n");
    printf("fd2:%d\n", fd2);
    printf("fd1:%d\n", fd1);
    dprintf(1, "asdf\n");
    dprintf(fd2, "sadfasdf\n");
    dprintf(fd1, "test\n");
    close(fd1);
    close(1);
    dprintf(1, "asdf\n");
    dup2(STDIN_FILENO, 1);
    dprintf(1, "asdf\n");
    // close(fd2);
    // printf("test\n");
    return 0;
}

// int main()
// {
//     pid_t pid;

//     pid = fork();
//     if (pid == 0)
//     {
//         printf("child process: %d\n", getpid());
//     }
//     else if (pid > 0)
//     {
//         printf("parent process: %d\n", getpid());
//     }
//     return (0);
// }
