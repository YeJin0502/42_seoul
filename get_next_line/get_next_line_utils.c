/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:03:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 19:40:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_until_lf(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_after_lf(char *str, int read_len)
{
	int	i;
	int	count;

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

void	*ft_memmove(void *dest, void *src, int n)
{
	unsigned char	*d; 
	unsigned char	*s;
	int				i;

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

char	*ft_strjoin(char *line, char *buf, int read_len, int is_contain_lf)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (is_contain_lf == 0)
		size = ft_strlen(line) + read_len;
	else
		size = ft_strlen(line) + ft_strlen_until_lf(buf);
	if (!(ret = (char *)malloc(size + 1)))
	{
		free(line);
		line = 0;
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
	line = 0;
	return (ret);
}
