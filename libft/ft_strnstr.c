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

int ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strnstr(const char *big, const char *little, int len)
{
	int little_size;
	little_size = ft_strlen(little);
	if (little_size > len)
		return 0;
	int i;
	int j;
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

#include <stdio.h>
#include <string.h>
int main()
{
	char big[30] = "Foo Bar Baz";
	char little[10] = "Bar";
	int len = 7;
	char *a = ft_strnstr(big, little, len);

	if (a)
		printf("%s\n", a);
	else
		printf("null\n");
}
/* 포인터가 null 가르킬때 프린트하면 원래 segmentation 뜨는건데...
그걸 몰라서 함수가 잘못된 줄 알았다. TT
따라서 null이 아닐 때만 프린트하도록 조건문을 달아주어야 좋다. */