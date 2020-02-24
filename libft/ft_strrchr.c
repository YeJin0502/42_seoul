/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:26:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 19:26:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	int i;
	i = 0;
	char *ret;
	while (s[i])
	{
		if (s[i] == c)
			ret = (char *) &s[i]; /* (char *)랑 &가 헷갈림 */
		i++;
	}
	return ret;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[30] = "A Garden Diary";
	int test = 'r';
	char *a = strrchr(s1, test);
	char *b = ft_strrchr(s1, test);

	printf("%s\n", a);
	printf("%s\n", b);
}
*/