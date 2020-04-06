/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:15:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 06:15:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	pull_buf(char *buf)
{
	gnl_memmove(buf,
				buf + strlen_lf(buf) + 1,
				gnl_strlen(buf) - strlen_lf(buf));
}

static int	is_line_made(char *buf, char **line)
{
	*line = gnl_strjoin(*line, buf);
	if (is_contain_lf(buf) == 1)
	{
		pull_buf(buf);
		return (1);
	}
	return (0);
}

static int	free_and_ret(char **buf, char **line, int ret)
{
	if (ret < 0)
	{
		free(*line);
		*line = 0;
		return (-1);
	}
	free(*buf);
	*buf = 0;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*buf;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	if (buf)
	{
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	else
		if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
			return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	return (free_and_ret(&buf, line, ret));
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	int ret;
// 	char *line;

// 	line = 0;
// 	fd = open("mix_marge1", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");
	
// 	fd = open("empty_lines", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);

// 	printf("=============================\n");

// 	fd = open("empty_file", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	free(line);
// }

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	int ret;
// 	char *line;

// 	fd = open("mix_marge", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("[%s] %d\n", line, ret);
// 		free(line);
// 	}
// 	printf("[%s] %d\n", line, ret);
// 	// free(line);
// }
