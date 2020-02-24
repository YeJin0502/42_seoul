/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:28:47 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 02:28:47 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	char *tmp = (char *)s;
	size_t i;

	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "moonguwha";
	printf("%s\n", a);
	ft_bzero(a, 3);
	int i;
	i = 0;
	while (i < 10)
	{
		printf("%c", a[i]);
		i++;
	}
}
*/