/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:44:36 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 01:44:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *a = (char *)s1;
	char *b = (char *)s2;
	size_t i;

	i = 0;
	while (i < n)
	{
		if (a[i] > b[i])
			return (sizeof(a[i]));
		if (a[i] < b[i])
			return (sizeof(b[i]));
		i++;
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[20] = "aaaa";
	char s2[20] = "aaa";
	// int a[10] = {1,6,1};
	// int b[10] = {1,1,2,3}; // 이건 왜 다르게해도 0만 나오지.. 뭘까
	size_t n = 8; // 7까지는 1이 나오다가 8부터 갑자기 97이 나온다... 뭐냐
	int real = memcmp(s1, s2, n);
	int my = ft_memcmp(s1, s2, n);
	
	printf("%d\n", real);
	printf("%d\n", my);
}
*/