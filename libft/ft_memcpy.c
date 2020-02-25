/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:57:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 23:57:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d;
	char *s;
	size_t i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
        d[i] = s[i];
		i++;
	}
    return dest;
}
