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

static int	n_size(int n)
{
	int	size;
	
	size = 0;
	if (n < 0)
	{
		size++;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	unsigned int	un;
	int				size;
	char			*ret;

	size = n_size(n);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	un = n;
	if (n < 0)
	{
		ret[0] = '-';
		un = -n;
	}
	while (un % 10 != 0)
	{
		ret[size - 1] = un % 10 + '0';
		un = un / 10;
		size--;
	}
	return (ret);
}
