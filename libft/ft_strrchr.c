/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:26:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/05 11:13:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		tmp;

	if (*s == '\0')
		return (0);
	ret = 0;
	while (*s)
	{
		tmp = *s;
		if (tmp == c)
			ret = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (ret);
}
