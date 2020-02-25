/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:32:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/25 17:32:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int word_count(char const *s, char c)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i+1] == c) || (s[i] != c && !s[i+1]))
			count++;
		i++;
	}
	return count;
}

static int word_len(char const *s, char c)
{
	int i;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return i;
}

#include <stdio.h>
char **ft_split(char const *s, char c)
{
	char **ret;
	int wc;
	int wl;
	int i;
	int j;

	wc = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ret)
		return 0;
	ret[wc] = 0;
	i = 0;
	while (i < wc)
	{
		j = 0;
		while (*s == c)
			s++;
		wl = word_len(s, c);
		ret[i] = (char *)malloc(wl + 1);
		if (!ret[i])
			return 0;
		ret[wl] = '\0';
printf("wc:%d, wl:%d\n", wc, wl);
		while (j < wl)
		{
			ret[i][j] = *s;
printf("ret[%d][%d]: %c\n", i, j, ret[i][j]);
			j++;
			s++;
		}
		i++;
	}
	return ret;	
}

// #include <stdio.h>
int main()
{
	char a[50] = "aa bb cc";
	char c = ' ';

	// printf("%d\n", word_count(a, c));
	// printf("%d\n", word_len(a, c));

	char **test = ft_split(a, c);
	
	int i;
	i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	free(test);
}