/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:12:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 01:12:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	void *ret = dest;
	char *d = (char *)dest;
	char *s = (char *)src;
	size_t i;

	i = 0;
	if (dest <= src || d >= s + n)
		return ret;
	else
	{
		dest = d + n - 1;
		src = s + n - 1;
		while (i < n)
		{
			*(d-i) = *(s-i);
			i++;
		}
	}
	return ret;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[50] = "1234567890";
	printf("%s\n", str1);
	memmove(str1+4, str1+2, 6);
	printf("%s\n", str1);

	char str2[50] = "1234567890";
	printf("%s\n", str2);
	memmove(str2+4, str2+2, 6);
	printf("%s\n", str2);
}
*/