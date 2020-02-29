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

// 문제 자체를 잘못 접근. 버퍼사이즈를 3정도로 생각하고 내일 다시!!!

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
	
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	// if (buf[i] == '\n')
	// {
	// 	ret = (char *)malloc(i + 1);
	// 	ft_memcpy(ret, buf, i);
	// 	ret[i] = '\0';
	// 	return (ret);
	// }
	// if (buf[i] == '\0')
	// {
	// 	ret = (char *)malloc(i + 1);
	// 	ft_memcpy(ret, buf, i);
	// 	ret[i] = '\0';
	// 	return (ret);
	// }
	ret = (char *)malloc(i + 1);
	ft_memcpy(ret, buf, i);
	ret[i] = '\0';
	return (ret);
}

// int main()
// {
// 	char *buf1 = "second line\n";
// 	printf("[%s]\n", ft_cut(buf1));
// }

int ft_len(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	return i;
}

int is_meet_n(char *str)
{
	while (1)
	{
		if (*str == '\n')
			return 1;
		if (*str == '\0')
			return 0;
		str++;
	}
}

// int main()
// {
// 	char *a = "aaa";
// 	char *b = "bbb\n";
// 	printf("%d\n", is_meet_n(a));
// 	printf("%d\n", is_meet_n(b));
// }

int line_count 

int get_next_line(int fd, char **line)
{
	char *buf;
	char *tmp;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
	{
		free(buf);
		return 0;
	}

	char *tmp_buf;
	tmp_buf = buf;

	// read(fd, buf, BUFFER_SIZE);
	// //if (is_meet_n(buf) == 0) 이면 브레이크
	// tmp = ft_cut(buf);
	// line[0] = tmp;
	// tmp_buf = tmp_buf + ft_strlen(line[0] - 3);
	// tmp = ft_cut(tmp_buf);
	// line[1] = tmp;

	read(fd, buf, BUFFER_SIZE);
	// printf("%s\n", buf);
	int i = 0;
	while (1)
	{
		tmp = ft_cut(tmp_buf);
		line[i] = tmp;
		if (is_meet_n(tmp_buf) == 0)
			break;
		tmp_buf = tmp_buf + ft_strlen(line[i]) + 1;
		i++;
	}
	line[i+1] = 0;

	i = 0;
	while (line[i])
	{
		printf("%d\n", i);
		printf("%s\n", line[i]);
		i++;
	}


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
	// printf("%s", *line);
	// while ((ret = get_next_line(fd, line)))
	// 	printf("%s\n", *line);
	// printf("%s\n", *line);
	// free(*line);
	close(fd);
	return(0);
}
