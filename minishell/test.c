#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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
//     printf("%d, %d\n", fd[0], fd[1]);
//     pid = fork();
//     if (pid == 0)
//     {
//         write(fd[1], "connect", 20);
//         sleep(2);
//         read(fd[0], buffer, 1024);
//         printf("Output of child process: %s\n", buffer);
//     }
//     else
//     {
//         read(fd[0], buffer, 1024);
//         printf("Output of parent process: %s\n", buffer);
//         write(fd[1], "good job", 20);
//         sleep(2);
//     }
//     return (0);
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
//         write(fd[1], "connected.", 20);
//     }
//     else
//     {
//         read(fd[0], buffer, 1024);
//         printf("%s\n", buffer);
//     }
//     return (0);
// }

// int main()
// {
//     int fd;
//     char buffer[1024];

//     fd = 3;
//     write(fd, "hello", 20);
//     read(fd, buffer, 1024);
//     printf("%s\n", buffer);
// }

// int main(void)
// {
//     char *fname = "result.txt";
//     int fd1, fd2;

//     if ((fd1 = creat(fname, 0666)) < 0)
//     {
//         printf("creat error\n");
//         return (1);
//     }
//     printf("First one is on the screen.\n");
//     fd2 = dup2(fd1, 1);
//     printf("Second one is in this file.\n");
//     printf("fd2:%d\n", fd2);
//     printf("fd1:%d\n", fd1);
//     dprintf(1, "asdf\n");
//     dprintf(fd2, "sadfasdf\n");
//     dprintf(fd1, "test\n");
//     close(fd1);
//     close(1);
//     dprintf(1, "asdf\n");
//     dup2(STDIN_FILENO, 1);
//     dprintf(1, "asdf\n");
//     // close(fd2);
//     // printf("test\n");
//     return 0;
// }

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

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t dst_size;
// 	size_t i;
// 	size_t j;

// 	dst_size = ft_strlen(dst);
// 	if (size <= dst_size)
// 		return (size + ft_strlen(src));
// 	i = dst_size;
// 	j = 0;
// 	while (src[j] && i < size - 1)
// 	{
// 		dst[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = '\0';
// 	return (dst_size + ft_strlen(src));
// }

// int main()
// {
//     char buffer[1024];
//     // char buffer[1024];

//     memset(buffer, 0, 1024);
//     // ft_strlcat(buffer, "hello", 3);
//     ft_strlcat(buffer, "hello", 1024);
//     printf("%s\n", buffer);
// }

// int main()
// {
//     char a;

//     while (scanf("%c", &a) > 0)
//         printf("%c", a);
//     // echo hello | ./a.out
//     // : hello
// }

// int main()
// {
//     int fd[2];
//     char buffer[1024];

//     pipe(fd);
//     write(fd[1], "hello", 20);
//     read(fd[0], buffer, 1024);
//     printf("%d, %d\n", fd[0], fd[1]);
//     printf("%s\n", buffer);
// }

int main(int ac, char **av)
{
    int fds[2];
    pid_t pid;
    char buf[1024];

    pipe(fds);
    pid = fork();
    if (pid == 0)
    {
        // dup2(fds[1], 1);
        write(fds[1], av[1], strlen(av[1]));
    }
    else
    {
        read(fds[0], buf, 1024);
        printf("%s", buf);
        // while (read(fds[0], buf, 1024) > 0)
        // {
        //     // printf("zz\n");
        //     printf("%s", buf);
        // }
    }
}
