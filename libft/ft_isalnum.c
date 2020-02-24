/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:30:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:30:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
		return 8; /* 아니 왜 갑자기 8? 구현은 그냥 1로만 해도 될라나? */
	else if ('a' <= c && c <= 'z')
		return 8;
	else if ('A' <= c && c <= 'Z')
		return 8;
	else
		return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = '0';
	int a = isalnum(test);
	int b = ft_isalnum(test);
	printf("%d %d\n", a, b);
}
*/