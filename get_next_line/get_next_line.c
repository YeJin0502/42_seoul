/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:48:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/28 04:48:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open, O_RDONLY


int is_line(char *buf)
{
	while (*buf)
		buf++;
	if (*(buf) == '\n')
		return 1;
	return 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}


char *ft_cut(char *buf)
{
	char *ret;
	int i;
	static int flag;


	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
	{
		ret = (char *)malloc(i + 1);
		ft_memcpy(ret, buf, i);
		ret[i] = '\0';
	}
	if (buf[i] == '\0')
	{
		ret = (char *)malloc(i + 1);
		ft_memcpy(ret, buf, i + 1);
		flag = 1;
	}
	return (ret);
}

// int main()
// {
// 	char *buf1 = "moongua test\nhelloworld\n ' ' \nhihi";
// 	printf("[%s]\n", ft_cut(buf1));
// }

int get_next_line(int fd, char **line)
{
	char *buf;
	char *tmp;
	static int flag;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
	{
		free(buf);
		return 0;
	}

	char *tmp_buf;
	tmp_buf = buf;

	read(fd, buf, BUFFER_SIZE);
	// printf("[%s]\n", buf);
	// printf("%s\n", ft_cut(buf));
	tmp = ft_cut(buf);
	line[0] = tmp;
	// printf("%s\n", tmp);
	// printf("%s\n", line[0]);
	// [%s]를 하며 왜 ]moongua test로 나오며, 왜 가끔은 아예 안나오는 것일까!!!
	// 뭔가 메모리에 남아있어야만 가능한... 뭔가 내가 모르는 중요한 내용이 있나본데... ㅠㅠ...
	tmp_buf = tmp_buf + ft_strlen(line[0]) + 1;

	tmp = ft_cut(tmp_buf);
	line[1] = tmp;
	printf("%s\n", line[1]);


	// read(fd, buf, BUFFER_SIZE);
	// int i = 0;
	// while (flag == 0)
	// {
	// 	tmp = ft_cut(tmp_buf);
	// 	line[i] = tmp;
	// 	tmp_buf = tmp_buf + ft_strlen(line[i]) + 1;
	// 	i++;

	// }



	free(buf);
	return (fd);
}

int		main()
{
	int		fd;
	char	**line;
	char	*temp;
	int		ret;
	line = &temp;
	fd = open("test.txt", O_RDONLY);
	ret = get_next_line(fd, line);
	// printf("%s\n", *line);
	// while ((ret = get_next_line(fd, line)))
	// 	printf("%s\n", *line);
	// printf("%s\n", *line);
	// free(*line);
	close(fd);
	return(0);
}
