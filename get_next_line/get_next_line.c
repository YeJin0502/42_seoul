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

char	*ft_strjoin(char *line, char *buf, int read_len, int is_contain_sep)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (!line)
		return (ft_strdup(buf, read_len, is_contain_sep));
	if (is_contain_sep == 0)
		size = ft_strlen(line) + read_len;
	else
		size = ft_strlen(line) + ft_strlen_until_sep(buf);
	if (!(ret = (char *)malloc(size + 1)))
	{
		free(line);
		return (0);
	}
	ret[size] = '\0';
	i = 0;
	j = 0;
	while (i < ft_strlen(line))
		ret[i++] = line[j++];
	while (i < size)
		ret[i++] = *(buf++);
	free(line);
	line = NULL; // 추가해봤는데... 이게 문제가 아닌 것 같은데. 일단 여기 바뀜.
	return (ret);
}

void	pull_buf(int *read_len, char *buf)
{
	int		jump_len;

	jump_len = 0;
	while (buf[jump_len] != '\n' && buf[jump_len] != 26)
		jump_len++;
	if (buf[jump_len] == '\n' || buf[jump_len] == 26)
		jump_len++;
	buf = ft_memmove(buf, buf + jump_len, ft_strlen_after_lf(buf, *read_len));
	*read_len = *read_len - jump_len;
	buf[*read_len] = '\0';
}

int	is_make_line(char **line, char *buf, int *read_len)
{
	int is_contain_sep;
	int i;

	is_contain_sep = 0;
	i = -1;
	while (++i < *read_len)
	{
		if (buf[i] == '\n')
		{
			is_contain_sep = 1;
			break;
		}
	}
	*line = ft_strjoin(*line, buf, *read_len, is_contain_sep);
	if (is_contain_sep == 1)
	{
		pull_buf(read_len, buf);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	static int	read_len;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!buf)
		if (!(buf = (char *)malloc(BUFFER_SIZE)))
			return (-1);
	*line = 0;
	if (read_len > 0)
		if (is_make_line(line, buf, &read_len) == 1)
			return (1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
		if (is_make_line(line, buf, &read_len) == 1)
			return (1);
	if (read_len == 0)
	{
		*line = ft_strdup(buf, read_len, 0);
		// *line = 0;
		free(buf);
		return (0);
	}
	return (-1);
}

//////////////////

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("test_half_marge_bottom", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%s] [%d]\n", line, ret);
		free(line);
	}
	printf("[%s] [%d]\n", line, ret);
	free(line);
	return (0);
}

/*
<테스트 기록>
test_41_char: (X)
test_42_char: (X)
test_43_char: (X)
test_half_marge_bottom: 마지막 한줄 안나옴
test_half_marge_top: 마지막 한줄(공백)이 안나오는 것 같은데..?
huge 파일들은 넘어갔고,
test_mix_merge1: 마지막 한줄 안나옴
test_mix_merge2: 마지막 한줄 안나옴
*/