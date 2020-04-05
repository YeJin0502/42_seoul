#include "get_next_line.h"

/*
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
*/

/*
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
	printf("%s [%d]\n", *line, ret);
	free(*line);
}
*/

/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("alphabet", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
*/

/*
// 표준입력과 리다이렉션
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
*/

// EOF 도달안했을때 다른 파일 전환 테스트
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("files/alphabet", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);

	fd = open("files/empty_lines", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);

	fd = open("files/alphabet", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
}

/*
// no FD일때 -1 테스트 이렇게 하는게 아닌가? 잘 나오는데 왜 42TESTERS-GNL은 안되지?
// 그 이유는 42TESTERS-GNL에서는 그냥 임의의 존재하지 않는 fd(ex. 180)을 주었기 때문이다.
// ret = get_next_line(180, &line); 과 같은 식.
// 따라서 이 때, ret은 -1을 반환하게 해주어 오류 해결.
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("null", O_RDONLY);
	printf("%d\n", fd);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
}
*/
