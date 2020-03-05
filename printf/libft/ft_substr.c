/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:29:18 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 16:29:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (0);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return 0;
	ret[len] = '\0';

	size_t i;
	i = 0;
	while (i < len && s[start+i])
	{
		ret[i] = s[start+i];
		i++;
	}
	return ret;
}
