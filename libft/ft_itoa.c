/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:55:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 21:55:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int n_size(int n)
{
	int size;
	size = 1;
	while (1)
	{
		if (n/10 == 0)
			break;
		n = n/10;
		size = size + 1;
	}
	return size;
}

char *ft_itoa(int n)
{
	int size;
	size = n_size(n);

	char *ret;
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	while (size - 1 >= 0)
	{
		ret[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (ret);
}
