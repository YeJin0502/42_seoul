/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:44:36 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 01:44:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *a;
	char *b;
	size_t i;

	a = (char *)s1;
	b = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] > b[i])
			return (sizeof(a[i]));
		if (a[i] < b[i])
			return (sizeof(b[i]));
		i++;
	}
	return 0;
}
