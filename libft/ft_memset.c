/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:48:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 00:48:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *ret = (char *) s;
	size_t i;
	
	i = 0;
	while (i < n)
	{
		ret[i] = c;
		i++;
	}
	return ret;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20] = "helloworld";
	char str2[20] = "helloworld";

	printf("%s\n", str1);
	memset(str1, '.', sizeof(str1) - 1);
	printf("%s\n", str1);	
	printf("-------------------\n");
	printf("%s\n", str2);
	ft_memset(str2, '.', sizeof(str2) - 1);
	printf("%s\n", str2);	
}
*/