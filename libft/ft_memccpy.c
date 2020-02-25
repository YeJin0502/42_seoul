/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:29:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 01:29:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d = (char *)dest;
	char *s = (char *)src;
	size_t i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == c)
			break;
		i++;
	}
	if (i == n)
		return 0;
	return ((void *)(d + i + 1));
}
