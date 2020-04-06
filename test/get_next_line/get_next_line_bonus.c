/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:55:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 04:03:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (-1);
	}
	free(*buf);
	*buf = 0;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*buf[1024];
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)malloc(1);
	**line = '\0';
	if (buf[fd])
	{
		if (is_line_made(buf[fd], line) == 1)
			return (1);
	}
	else
		buf[fd] = (char *)malloc(BUFFER_SIZE + 1);
	while ((ret = read(fd, buf[fd], BUFFER_SIZE)) > 0)
	{
		buf[fd][ret] = '\0';
		if (is_line_made(buf[fd], line) == 1)
			return (1);
	}
	return (free_and_ret(&buf[fd], line, ret));
}
