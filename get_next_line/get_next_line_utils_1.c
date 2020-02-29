/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:50:39 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/28 04:50:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *s)
{
	int		size;
	char	*ret;
	int		i;

	if (s[ft_strlen(s) - 1] == '\n')
	{
		size = ft_strlen(s) - 1;
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
	return 0;
}

// #include <stdio.h>
// int main()
// {
// 	char *a = "hello";
// 	char *test = ft_gnl_strdup(a);
// 	printf("[%s]\n", test);
// }

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_gnl_split(char const *s, char c)
{
	char	**ret;
	int		wc;
	int		wl;
	int		i;
	int		j;

	wc = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ret)
	{
		free(ret);
		return 0;
	}
	ret[wc] = 0;
	i = -1;
	while (++i < wc)
	{
		j = 0;
		while (*s == c)
			s++;
		wl = word_len(s, c);
		ret[i] = (char *)malloc(wl + 1 + 1); // 수정
		if (!ret[i])
		{
			while (i >= 0)
				free(ret[i--]);
			free(ret);
			return (0);
		}
		ret[i][wl] = '\0';
		while (j < wl)
			ret[i][j++] = *(s++);
		ret[i][wl - 1] = '\n'; // 수정
	}
	return (ret);
}
