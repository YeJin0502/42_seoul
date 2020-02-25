/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:38:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 02:38:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	char *ret;
	size_t i;
	
	ret = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ret[i] == c)
			return ((void *)&ret[i]);
		i++;
	}
	return 0;
}
