/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:37:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 19:37:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t little_size;
	little_size = ft_strlen(little);
	if (little_size > len)
		return 0;
	size_t i;
	size_t j;
	i = 0;
	while (i < len)
	{
		j = 0;
		if (little[j] == big[i])
			while (j < little_size && j + i < len)
			{
				if (little[j] != big[i+j])
					break;
				if (little[j] == big[i+j])
					j++;
				if (j == little_size)
					return (char *) &big[i];
			}
		i++;
	}
	return 0;
}

/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char big[30] = "Foo Bar Baz";
	char little[10] = "Foo";
	int len = 3;
	char *my = ft_strnstr(big, little, len);
	char *real = strnstr(big, little, len);

	if (my)
		printf("my: %s\n", my);
	else
		printf("null\n");

	if (real)
		printf("real: %s\n", real);
	else
		printf("null\n");
}
*/
/* 포인터가 null 가르킬때 프린트하면 원래 segmentation 뜨는건데...
그걸 몰라서 함수가 잘못된 줄 알았다. TT
따라서 null이 아닐 때만 프린트하도록 조건문을 달아주어야 좋다.

그리고 strnstr 테스트를 위해...
sudo apt install libbsd-dev 해주었고, 헤더에 bsd/를 추가해줌.*/
