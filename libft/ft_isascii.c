/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:33:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:33:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii(int c)
{
	if (0 <= c && c <= 126)
		return 1; /* 이건 또 왜 갑자기 1이냐 */
	else
		return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = ' ';
	int a = isascii(test);
	int b = ft_isascii(test);
	printf("%d %d\n", a, b);
}
*/