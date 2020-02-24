/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:37:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/24 17:37:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return i;
}
/* 헤더파일을 부르는게 낫나? 깔끔한건 그게 깔끔한데, 너무 비효율적인가 싶어서..
이대로 하면 충돌일어나나? 아니면 static을 이런 곳에 사용해야하나? */

int ft_strlcat(char *dst, const char *src, int size)
{
	int i;
	int dst_size;
	i = 0;
	while (dst[i])
		i++;
	dst_size = i;
	if (size < dst_size)
		return (size + ft_strlen(src));
	else if (size >= dst_size)
	{
		int j;
		j = 0;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (dst_size + ft_strlen(src));
}

/*
// 테스트용 깃허브 함수 복사.
int	ft_strlcat2(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
		k++;
	if (size <= i) //i = len(dest)
		k += size; //k = len(src)
	else
		k += i; //k = len(src)
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (k);
}
*/

/*
#include <stdio.h>
int main()
{
	char dest1[20] = "moon";
	char src1[20] = "hihello";
	// char dest2[20] = "moon";
	// char src2[20] = "hihello";
	int size = 20; // 3까지는 size+src, 4부터는 dest+src (11).

	int a = ft_strlcat(dest1, src1, size);
	printf("%d\n", a);
	printf("%s\n", dest1);

	// int b= ft_strlcat2(dest2, src2, size);
	// printf("%d\n", b);
	// printf("%s\n", dest2);
}
*/