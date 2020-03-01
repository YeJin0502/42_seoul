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

void pull_buf(int *read_len, char *buf)
{
	int jump_len;
	jump_len = 0;
	while (buf[jump_len] != '\n')
		jump_len++;
	while (buf[jump_len] == '\n')
		jump_len++;
	buf = ft_memmove(buf, buf + jump_len, ft_strlen_after_lf(buf));
	*read_len = *read_len - jump_len;
	buf[*read_len] = '\0';
}
