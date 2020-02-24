/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:49:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:49:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = 'C';
	int a = tolower(test);
	int b = ft_tolower(test);

	printf("%c %c\n", a, b);
}
*/