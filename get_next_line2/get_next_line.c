/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:15:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/06 09:06:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int gnl_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_contain_lf(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int strlen_lf(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char *gnl_strjoin(char *s1, char *s2) // 줄바꿈이나 널문자까지?
{
	int s1_size;
	int s2_size;
	int size;
	char *ret;
	int i;

	s1_size = (s1) ? gnl_strlen(s1) : 0;
	s2_size = (s2) ? strlen_lf(s2) : 0;
	size = s1_size + s2_size;
	if (!(ret = (char *)malloc(size + 1)))
		return (0);
	ret[size] = '\0';
	i = -1;
	// while (*s1) // 이건 왜 안되는지 잘 모르겠음.
	while (++i < s1_size)
		*(ret + i) = *(s1 + i);
	while (i - s1_size < s2_size)
		*(ret + i++) = *(s2++);
	if (s1) // s1_size로 하면 널문자 있는 문자열을 free 못함.
		free(s1);
	return (ret);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest <= src)
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	return (dest);
}

void pull_buf(char *buf) // 참조 의한 호출, 값 의한 호출 헷갈린다.
{
	gnl_memmove(buf,
				buf + strlen_lf(buf) + 1,
				gnl_strlen(buf) - strlen_lf(buf));
	// +1인가? 헷갈리네.
	// 포인터를 당길 필요가 있나? 그냥 포인터 옮기면 free를 못해줘서 그런가?
}

int is_line_made(char *buf, char **line)
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

	*line = 0;
	if (buf)
	{
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	else
		buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((ret = read(fd, buf, BUFFER_SIZE))) // 형변환 안해줘도 되나?
	{
		buf[ret] = '\0';
		if (is_line_made(buf, line) == 1)
			return (1);
	}
	if (ret < BUFFER_SIZE)
		return (0);
	return (-1);
}

// int main()
// {
// 	// printf("%s\n", gnl_strjoin("hello", "world")); //buffer_size = 5 라고 가정.
// 	// printf("%s\n", gnl_strjoin("hello", "wo\nrl"));

// 	int fd;
// 	char *line;

// 	fd = open("test", O_RDONLY);
// 	printf("%d [%s]\n", get_next_line(fd, &line), line);
// 	free(line);
// 	printf("%d [%s]\n", get_next_line(fd, &line), line);
// 	free(line);
// 	printf("%d [%s]\n", get_next_line(fd, &line), line);
// 	free(line);
// 	printf("===\n");
// }
