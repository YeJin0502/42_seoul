/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:57:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 23:57:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;
	char *s = (char *)src;
	size_t i;
	
	i = 0;
	while (i < n)
	{
        d[i] = s[i];
		i++;
	}
    return dest;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char dest1[10] = "hihello";
	char src1[20] = "moonguwha wowowo";
	char dest2[10] = "hihello";
	char src2[20] = "moonguwha wowowo";
	int n = 5;

	memcpy(dest1, src1, n);
	printf("%s\n", dest1);
	ft_memcpy(dest2, src2, n);
	printf("%s\n", dest2);
}
*/