/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:31:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/29 18:31:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char *buf;
	static int read_len;
	int jumping_len;

	*line = 0;
	if (!buf)
		buf = (char *)malloc(BUFFER_SIZE);
	if (read_len > 0)
	{
		if (is_contain_lf(buf, read_len) == 1)
		{
			*line = ft_strdup_until_lf(buf);
			jumping_len = ft_jumping_len(buf);
			buf = ft_memmove(buf, buf + jumping_len, ft_strlen_after_lf(buf));
			read_len = read_len - jumping_len;
			buf[read_len] = '\0';
			return (1);
		}
		if (is_contain_lf(buf, read_len) == 0)
			*line = ft_strdup(buf);
	}	
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (*line && (is_contain_lf(buf, read_len) == 1))
		{
			*line = ft_strjoin_until_lf(*line, buf);
			jumping_len = ft_jumping_len(buf);
			buf = ft_memmove(buf, buf + jumping_len, ft_strlen_after_lf(buf));
			read_len = read_len - jumping_len;
			buf[read_len] = '\0';
			return (1);
		}
		else if (!*line && (is_contain_lf(buf, read_len) == 1))
		{
			*line = ft_strdup_until_lf(buf);
			jumping_len = ft_jumping_len(buf);
			buf = ft_memmove(buf, buf + jumping_len, ft_strlen_after_lf(buf));
			read_len = read_len - jumping_len;
			buf[read_len] = '\0';
			return (1);
		}
		else if (*line && (is_contain_lf(buf, read_len) == 0))
			*line =ft_strjoin(*line, buf);
		else if (!*line && (is_contain_lf(buf, read_len) == 0))
			*line = ft_strdup(buf);
	}
	return 0;
}

/////////////////

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

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
}
