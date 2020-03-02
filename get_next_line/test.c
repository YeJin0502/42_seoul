// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	char **line;
// 	char *tmp;
// 	int ret;

// 	line = &tmp;
// 	fd = open("test.txt", O_RDONLY);
	
// 	ret = get_next_line(fd, line);
// 	printf("[%s] %d\n", *line, ret);
// 	free(*line);

// 	ret = get_next_line(fd, line);
// 	printf("[%s] %d\n", *line, ret);
// 	free(*line);

// 	ret = get_next_line(fd, line);
// 	printf("[%s] %d\n", *line, ret);
// 	free(*line);

// 	ret = get_next_line(fd, line);
// 	printf("[%s] %d\n", *line, ret);
// 	free(*line);

// 	ret = get_next_line(fd, line);
// 	printf("[%s] %d\n", *line, ret);
// 	free(*line);
// }

///////////

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	char **line;
	char *tmp;
	int ret;

	line = &tmp;
	fd = open("alphabet", O_RDONLY);
	ret = -1;
	while (1)
	{
		if ((ret = get_next_line(fd, line)) == 0)
			break;
		printf("%s [%d]\n", *line, ret);
		free(*line);
	}
	ret = get_next_line(fd, line);
	printf("%s [%d]\n", *line, ret);
	free(*line);
	ret = get_next_line(fd, line);
	printf("%s [%d]\n", *line, ret);
	free(*line);
}
