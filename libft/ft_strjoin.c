/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:43:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 16:43:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ret;
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return 0;
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';

	size_t i;
	i = 0;
	size_t j;
	j = 0;
	while(i < ft_strlen(s1))
	{
		ret[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	return ret;	
}
