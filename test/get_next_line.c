/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:15:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/06 15:50:58 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void pull_buf(char *buf)
{
	gnl_memmove(buf,
				buf + strlen_lf(buf) + 1,
				gnl_strlen(buf) - strlen_lf(buf)); // 아 이거 헷갈리네
}

static int is_line_made(char *buf, char **line)
{
	*line = gnl_strjoin(*line, buf);
	if (is_contain_lf(buf) == 1)
	{
		pull_buf(buf);
		return (1);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char	*buf;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)malloc(1);
	**line = '\0';
	if (buf)
	{
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	else
		buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	free(buf);
	buf = 0;
	return (0);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	int ret;
	
// 	fd = open("empty_file", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);
// }

// int main()
// {
// 	// printf("%s\n", gnl_strjoin("hello", "world")); //buffer_size = 5 라고 가정.
// 	// printf("%s\n", gnl_strjoin("hello", "wo\nrl"));

// 	int fd;
// 	char *line;
// 	int ret;

// 	fd = open("mix_marge1", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");
	
// 	fd = open("empty_lines", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");

// 	fd = open("empty_file", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);
// }
