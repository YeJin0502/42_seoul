/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:05:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 19:05:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (char *) s;
		s++;
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[30] = "A Garden Diary";
	// char s2[30] = "A Garden Diary";
	int test = 'a';
	char *a = strchr(s1, test); // s1이 이동되는건 아니라 s2가 필요 없다는데? 헷갈림.
	printf("%s\n", s1); // 그 증거가 이거. 함수를 써도 그대로 전체가 프린트됨.
	char *b = ft_strchr(s1, test); // 다른 함수로 넘어갈 때, 독립적으로 주소를 받는거라 그렇다고 함..

	printf("%s\n", a);
	printf("%s\n", b);
}
*/