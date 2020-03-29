/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:43:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/30 04:56:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
    size_t  s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
    s1_len = (s1) ? ft_strlen(s1) : 0;
    s2_len = (s2) ? ft_strlen(s2) : 0;
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	ret[s1_len + s2_len] = '\0';
	i = 0;
	j = 0;
	while(i < s1_len)
		ret[i++] = s1[j++];
	j = 0;
	while (i < s1_len + s2_len)
		ret[i++] = s2[j++];
	return (ret);
}
