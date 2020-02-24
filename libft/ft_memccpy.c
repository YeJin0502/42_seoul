/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:29:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 01:29:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d = (char *)dest;
	char *s = (char *)src;
	size_t i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == c)
			break;
		i++;
	}
	return dest; // 나는 d를 하려고 했는데... 헷갈린다. d랑 dest랑 차이가 뭐야...
}


#include <stdio.h>
#include <string.h>
int main()
{
	char dest1[50] = "01234567890123456789"; // 포인터로 지정하면 seg 오류
	char src1[10] = "moonguwha";
	char dest2[50] = "01234567890123456789"; // 포인터로 지정하면 seg 오류
	char src2[10] = "moonguwha";
	int c = 'o'; // g가 있어서 moong까지만 복사.
	size_t n = 5; // c 없으면 7글자 복사.

	printf("%s\n", dest1);
	memccpy(dest1, src1, c, n);
	printf("%s\n", dest1);
	printf("=============\n");
	printf("%s\n", dest2);
	ft_memccpy(dest2, src2, c, n);
	printf("%s\n", dest2);
}
