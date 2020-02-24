/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:35:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 23:35:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char *ret;
	int size;
	size = ft_strlen(s);
	ret = (char *)malloc(size + 1);
	ret[size] = '\0';
	
	int i;
	i = 0;
	while (i < size)
	{
		ret[i] = s[i];
		i++;
	}
	return ret;
}
