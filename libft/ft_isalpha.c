/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:28:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 15:28:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return 1024; /* 왜 1024? */
	else if ('A' <= c && c <= 'Z')
		return 1024;
	else
		return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = '0';
	int a = isalpha(test);
	int b = ft_isalpha(test);
	printf("%d %d\n", a, b);
}
*/