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

int	ft_strlen_after_lf(const char *str, int read_len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\n')
		i++;
	while (i < read_len)
	{
		count++;
		i++;
	}
	return (count - 1);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char	*d; 
	unsigned char	*s;
	int			i;

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

char	*ft_strdup(const char *s, int read_len)
{
	int		size;
	char	*ret;
	int		i;

	size = read_len;
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

	size = 0;
	while (s[size] != '\n')
		size++;
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
