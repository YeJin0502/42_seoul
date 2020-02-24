/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:52:30 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 16:52:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef int size_t;
/* strlen과 더불어 여기도 size_t. 해결해야됨.
이거 stdio.h에 정의되어 있나본데..?
아오 뭐 충돌 자꾸 일어나서 그냥 int로 할란다. */

int ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return i;
} /* 헤더파일을 부르는게 낫나? 깔끔한건 그게 깔끔한데, 너무 비효율적인가 싶어서.. */

int ft_strlcpy(char *dest, const char *src, int size)
{
	int i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
int main()
{
	char dest[20];
	const char src[20] = "hihello";
	int size = 5;

	int a = ft_strlcpy(dest, src, size);
	printf("%d\n", a);
	printf("%s\n", dest);
}
*/