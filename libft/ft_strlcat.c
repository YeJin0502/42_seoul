/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:37:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/07 18:33:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t src_size;
	size_t i;
	size_t j;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	i = 0;
	j = dst_size;
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_size + src_size);
}

// size_t ft_strlcat(char *dest, const char *src, size_t size)
// {
// 	size_t len_d;
// 	size_t len_s;
// 	size_t i;
// 	size_t ret;

// 	i = 0;
// 	len_d = ft_strlen(dest);
// 	len_s = ft_strlen(src);
// 	if (len_d >= size)
// 		ret = len_s + size;
// 	else
// 	{
// 		ret = len_s + len_d;
// 		while ((len_d < size - 1 && src[i]))
// 			dest[len_d++] = src[i++];
// 		dest[len_d] = 0;
// 	}
// 	return (ret);
// }

#include <bsd/string.h>
#include <stdio.h>
int main()
{
	char a[4] = "toto";
	char b[1] = "";
	int size = 0;
	printf("%ld\n", ft_strlcat(a, b, size));
	printf("%s\n", a);

	char aa[4] = "toto";
	char bb[1] = "";
	printf("%ld\n", strlcat(aa, bb, size));
	printf("%s\n", aa);
}