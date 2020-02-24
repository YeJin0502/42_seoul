/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:36:30 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:36:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return 16384; /* 함수마다 값이 다른건가...? */
	else
		return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = '!';
	int a = isprint(test);
	int b = ft_isprint(test);
	printf("%d %d\n", a, b);
}
*/