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
////////////////

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
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

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ret;
	int		i;

	size = ft_strlen(s);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	i = 0;
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

size_t ft_strlen_until_lf(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_until_lf(const char *s)
{
	int		size;
	char	*ret;
	int		i;

	size = ft_strlen_until_lf(s);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	i = 0;
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

char	*ft_strjoin_until_lf(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen_until_lf(s2);
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


int is_contain_lf(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

int	ft_strlen_after_lf(const char *str)
{
	int count;
	count = 0;
	while (*str != '\n')
		str++;
	while (*str) // 시작 위치가 \n 이라 \n까지 세버리는 듯.
	{
		count++;
		str++;
	}
	return (count - 1);
}

char	*ft_strdup_after_lf(const char *s)
{
	int		size;
	char	*ret;
	int		i;

	size = ft_strlen_after_lf(s);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	i = 0;
	while (i < size)
	{
		ret[i] = s[ft_strlen_until_lf(s) + 1 + i];
		i++;
	}
	return (ret);
}

// #include <stdio.h>
// int main()
// {
// 	char a[20] = "hello\nworld";
// 	char *test = ft_strdup_after_lf(a);
// 	printf("%s\n", test);
// }

// //////////////

#include <stdio.h>
int get_next_line(int fd, char **line)
{
	int ret;
	static char *buf;
	int flag;
	int a;

	ret = 1;
	*line = 0;
	flag = 0;
	// printf("buf:[%s]\n", buf);
	if (!buf)
		buf = (char *)malloc(BUFFER_SIZE);
	if (buf)
	{
		if (is_contain_lf(buf) == 1)
		{
			// printf("[A]:%s\n", buf);
			*line = ft_strdup_after_lf(buf);
		}
		if (is_contain_lf(buf) == 0)
		{
			// printf("[B]:%s\n", buf);
			*line = ft_strdup(buf);
		}
		flag = 1;
	}
	while ((a = read(fd, buf, BUFFER_SIZE)) > 0)
	{

		if (is_contain_lf(buf) == 0 && flag == 1)
		{
			// printf("[a]\n");
			*line = ft_strjoin(*line, buf);
		}

		if (is_contain_lf(buf) == 1 && flag == 1)
		{
			// printf("[b]\n");
			*line = ft_strjoin_until_lf(*line, buf);
			return (ret);
		}

		if (is_contain_lf(buf) == 1 && flag == 0)
		{
			// printf("[c]\n");
			*line = ft_strdup_after_lf(buf);
			return (ret);
		}

		if (is_contain_lf(buf) == 0 && flag == 0)
		{
			// printf("[d]\n");
			*line = ft_strdup(buf);
			flag = 1;
		}
		// if (a < BUFFER_SIZE)
		// 	ret = 0;
		
	}
	return (0);
}

///////////
// 현재 문제. 버퍼사이즈가 1이면 리턴값 제대로 안나옴.
// 버퍼사이즈가 크면 마지막에 개행이 붙음.
// 리턴값에 대한 연구 필요. 다른 테스트 케이스에서도 사이즈 100주면 두번째 줄도 1이 나와버리는데..?
// EOF라는 것이 무엇일까... 연구 필요.

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
	printf("%s\n", *line); // 0123456
	printf("%d\n", ret);

	ret = get_next_line(fd, line);
	printf("%s\n", *line); // secondline
	printf("%d\n", ret);

	ret = get_next_line(fd, line);
	printf("%s\n", *line); // secondline
	printf("%d\n", ret);

	ret = get_next_line(fd, line);
	printf("%s\n", *line); // secondline
	printf("%d\n", ret);
}


// 내 결과
/* BUFFER_SIZE=100
0123456
0
secondline

1
secondline

1
*/

/* BUFFER_SIZE=1
0123456
1
secondline
1

1
*/