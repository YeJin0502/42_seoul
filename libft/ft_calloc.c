/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:03:07 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 02:03:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t num, size_t size)
{
	char *ret;
	ret = (char *)malloc(size * num);

	size_t i;
	i = 0;
	while (i < size * num)
	{
		ret[i] = 0;
		i++;
	}
	return (void *)ret;
}

/* ret의 형식을 처음에 void로 하면 ret이 수정할 수 없는 value라는 에러가 뜸.
char로 해서 1바이트씩 모두 0으로 바꿔주는 식으로 에러 수정...
은 물어봐서 안거지 사실 잘 모르겠다. */

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *a;
	a = (char *)ft_calloc(5, 1);
	a[0] = 'm';
	a[1] = 'o';
	a[3] = '0';

	printf("%s\n", a);
}
*/