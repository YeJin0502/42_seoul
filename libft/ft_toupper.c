/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:44:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:44:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	int test = 'm';
	int a = toupper(test);
	int b = ft_toupper(test);

	printf("%c %c\n", a, b);
}
*/