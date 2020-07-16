/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:49:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/07/16 19:10:42 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int gnl_strlen(char buf[], int byte)
{
	int ret;

	ret = 0;
	while (ret < byte && buf[ret] && buf[ret] != '\n')
		ret++;
	return (ret);
}

void gnl_process(char **line, char buf[], int line_len)
{
	char *ret;
	int prev_len;
	int ret_len;
	int i;
	int j;

	if (*line == 0)
	{
		*line = (char *)malloc(1);
		*line[0] = '\0';
	}
	prev_len = gnl_strlen(*line, 1024); // 되나?
	ret_len = prev_len + line_len;
	ret = (char *)malloc(ret_len + 1); // ?
	ret[ret_len] = '\0';
	i = 0;
	j = 0;
	// printf("prev:%d line:%d\n", prev_len, line_len);
	while (i < prev_len)
	{
		ret[i] = (*line)[i];
		i++;
	}
	while (i < ret_len)
		ret[i++] = buf[j++];
	// printf("<%s>\n", buf);
	// printf("[[%s]]\n", ret);
	// if (*line)
		// free(*line);
	*line = ret;
	return ;
}

static int return_value(char buf[], int byte)
{
	int i;

	i = 0;
	while (i < byte)
	{
		if (buf[i] == '\n')
			return (1); // 개행이 있는 경우
		i++;
	}
	if (i < byte)
		return (0); // 중간까지 찬 경우
	return (2); // 다 찬 경우
}

static void pull_buf(char buf[], int line_len, int byte)
{
	int i;
	int j;

	i = 0;
	j = line_len;
	while (j < byte && buf[j])
	{
		buf[i] = buf[j];
		if (buf[i] == '\0' || buf[i] == '\n')
			return ;
		i++;
		j++;
	}
}

int get_next_line(char **line)
{
	static char buf[3];
	int byte;
	int line_len;
	int ret;

	if (line == 0)
		return (-1);
	*line = 0;
	while ((byte = read(0, buf, sizeof(buf))) > 0)
	{
		line_len = gnl_strlen(buf, byte);
		ret = return_value(buf, byte);
		// printf("!!before: [%s] (line_len: %d)\n", buf, line_len);
		gnl_process(line, buf, line_len);
		pull_buf(buf, line_len, byte);
		// printf("ret:%d\n", ret);
		// printf("!!after: %s\n", buf);
		if (ret == 1 || ret == 0)
		{
			//printf("!!ret: %d\n", ret);	
			return (ret);
		}
	}
	return (-1); // 여긴 어떻게 오게되지?
}
