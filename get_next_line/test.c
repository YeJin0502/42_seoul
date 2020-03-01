#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	char **line;
	char *tmp;
	int ret;

	line = &tmp;
	fd = open("test.txt", O_RDONLY);
	
	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
	free(*line);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
	free(*line);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
	free(*line);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
	free(*line);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
	free(*line);
}
