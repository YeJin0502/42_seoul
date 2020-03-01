#include <stdio.h>
#include <fcntl.h> // open, O_RDONLY
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat_eol(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin_eol(char *s1, char *s2);


int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*ret;

	src_len = ft_strlen((char *)src);
	ret = malloc(sizeof(char) * (src_len + 1));
	ft_strlcpy(ret, src, (size_t)(src_len + 1));
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	while (i < dst_size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dst_size != 0)
		dst[dst_size - 1] = '\0';
	return (i);
}

size_t	ft_strlcat_eol(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = (size_t)ft_strlen((char *)src);
	dst_len = (size_t)ft_strlen((char *)dst);
	if (dst_size < dst_len)
		return (dst_size + src_len);
	while (dst_size > dst_len + i + 1 && i < src_len && src[i] != '\n')
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin_eol(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = (size_t)ft_strlen((char *)s1);
	s2_len = (size_t)ft_strlen((char *)s2);
	if (!(ret = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
//	printf("ft_strlcat_eol function start\n");
//	printf("ret: %s\n", ret);
//	printf("s2 : %s\n", s2);
	ft_strlcat_eol(ret, s2, s1_len + s2_len + 1);
//	printf("ft_strlcat_eol function end\n");
	free(s1);
	return (ret);
}

void	*ft_memset(void *arr, int c, size_t len)
{
	unsigned char	*p = arr;

	while (len > 0)
		p[--len] = c;
	return (arr);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	start;
	char		*ret;
	int			i;
	static int	readn;


	if (!(ret = malloc(1)) || fd < 0)
		return (-1);
	i = start;
	if (*buf == 0)
		readn = read(fd, buf, BUFFER_SIZE);
	if (readn < 0)
		return (-1);
	ret[0] = '\0';
	while (buf[i] != '\n' && readn != 0)
	{
		if (i == BUFFER_SIZE)
		{
			ret = ft_strjoin_eol(ret, &buf[start]);
			i = -1;
			start = 0;
			ft_memset((void *)buf, 0, BUFFER_SIZE + 1);
			readn = read(fd, buf, BUFFER_SIZE);
		}
		i++;
	}
	if (readn == 0)
	{
		*line = ret;
		return (0);
	}
	ret = ft_strjoin_eol(ret, &buf[start]);
	*line = ret;
	start = i + 1;
	return (1);
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
