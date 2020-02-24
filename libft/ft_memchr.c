/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:38:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 02:38:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	char *ret = (char *)s;
	size_t i;
	
	i = 0;
	while (i < n)
	{
		if (ret[i] == c)
			return ((void *)&ret[i]);
		i++;
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "hi hello world";
	int c = 'i';
	size_t n = 8;

	printf("%p\n", memchr(a, c, n));
	printf("%p\n", ft_memchr(a, c, n));
}
*/