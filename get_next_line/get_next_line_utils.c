/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:03:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/01 06:03:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int ft_strlen_until_lf(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_after_lf(const char *str)
{
	int count;
	count = 0;
	while (*str != '\n')
		str++;
	while (*str)
	{
		count++;
		str++;
	}
	return (count - 1);
}

int is_contain_lf(char *str, int n)
{
	int i;
	i = 0;
	while (i < n)
	{
		if (str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
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

char	*ft_strjoin_until_lf(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	if (s1 == 0)
		return(ft_strdup_until_lf(s2));
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d; 
	unsigned char	*s;
	size_t			i;

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

int ft_jumping_len(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return i;
}
