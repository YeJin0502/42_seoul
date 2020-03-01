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

char	*ft_strjoin(char *line, char *buf, int read_len, int is_contain_lf)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (!line)
		return (ft_strdup(buf, read_len, is_contain_lf));
	if (is_contain_lf == 0)
		size = ft_strlen(line) + read_len;
	else
		size = ft_strlen(line) + ft_strlen_until_lf(buf);
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
	return (ret);
}

void	pull_buf(int *read_len, char *buf)
{
	int		jump_len;

	jump_len = 0;
	while (buf[jump_len] != '\n')
		jump_len++;
	if (buf[jump_len] == '\n')
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
	*line = ft_strjoin(*line, buf, *read_len, is_contain_lf);
	if (is_contain_lf == 1)
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
	while (1)
	{
		if (read_len == 0)
			if ((read_len = read(fd, buf, BUFFER_SIZE)) == 0)
			{
				*line = ft_strdup(buf, read_len, 0);
				free(buf);
				return (0);
			}
		if (is_make_line(line, buf, &read_len) == 1)
			return (1);
	}
	return (-1);
}
