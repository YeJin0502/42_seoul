/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:22:04 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:22:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return 2048; /* 2048은 또 뭐야!!!! */
	else
		return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = '1';
	int a = isdigit(test);
	int b = ft_isdigit(test);
	printf("%d %d\n", a, b);
}
*/