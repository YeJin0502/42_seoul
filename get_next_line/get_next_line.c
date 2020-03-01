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

char	*ft_strjoin(char const *s1, char const *s2, int read_len)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2, read_len));
	len = ft_strlen(s1) + read_len;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	i = 0;
	j = 0;
	while(i < ft_strlen(s1))
		ret[i++] = s1[j++];
	j = 0;
	while (i < len)
		ret[i++] = s2[j++];
	return (ret);
}

char	*ft_strjoin_until_lf(char const *s1, char const *s2)
{
	char	*ret;
	int		s2_len;
	int		len;
	int		i;
	int		j;

	s2_len = 0;
	while (s2[s2_len] != '\n')
		s2_len++;
	if (!s1)
		return (ft_strdup_until_lf(s2));
	len = ft_strlen(s1) + s2_len;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	i = 0;
	j = 0;
	while(i < ft_strlen(s1))
		ret[i++] = s1[j++];
	j = 0;
	while (i < len)
		ret[i++] = s2[j++];
	return (ret);
}

void pull_buf(int *read_len, char *buf)
{
	int jump_len;
	jump_len = 0;
	while (buf[jump_len] != '\n')
		jump_len++;
	while (buf[jump_len] == '\n')
		jump_len++;
	buf = ft_memmove(buf, buf + jump_len, ft_strlen_after_lf(buf, *read_len));
	*read_len = *read_len - jump_len;
	buf[*read_len] = '\0';
}

int	is_make_line(char **line, char *buf, int *read_len)
{
	int is_contain_lf;
	int i;

	is_contain_lf = 0;
	i = -1;
	while (++i < *read_len)
		if (buf[i] == '\n')
		{
			is_contain_lf = 1;
			break;
		}
	if (is_contain_lf == 1)
	{
		*line = ft_strjoin_until_lf(*line, buf);
		pull_buf(read_len, buf);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, buf, *read_len);
		return (0);
	}
}

#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	static char	*buf;
	static int	read_len;

	*line = 0;
	if (!buf)
		buf = (char *)malloc(BUFFER_SIZE);
	if (read_len > 0)
		if (is_make_line(line, buf, &read_len) == 1)
			return 1;
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
		if (is_make_line(line, buf, &read_len) == 1)
			return 1;
	if (read_len == 0)
	{
		*line = ft_strdup(buf, read_len);
		// free(buf);
		return 0;
	}
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

	ret = get_next_line(fd, line);
	printf("[%s] %d\n", *line, ret);
}
