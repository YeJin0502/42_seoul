/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 02:02:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int ret;
	int count_s;
	va_list ap;
	char **flags;
	char *specs;
	t_info *info;
	int i;

	ret = 0;
	if (!(count_s = count_spec(format)))
	{
		printf("[ft_strlen:%zu]\n", ft_strlen(format));
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	va_start(ap, format);
	flags = make_flags(format, count_s);
	specs = make_specs(format, count_s);
	info = make_list(specs, flags);
	
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
		{
			format = meet_percent(&ret, format, *(info + i++), ap); // spec 자리로옴.
		}
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++; // 여기서 spec 넘어감.
	}
	while (--i >= 0)
	{
		if (flags[i])
			free(flags[i]);
		free(info[i].flag);
	}
	free(flags);
	free(specs);
	free(info);
	return (ret);
}

// 테스트
int main()
{
	char a[10] = "hello";
	ft_printf("%d\n%u\n%p\n", 2147483648, -1, a); // 이런 값들 고쳐야.

	printf("%p\n", a);
	// char **test = make_flags("moon%-d\n", 1);
	// printf("%s\n", test[0]);
	// free(test[0]);
	// free(test);	

	// make_flags 테스트
	/*
	char **test = make_flags("hi%--dhello%-0dworld%-.s", 3);
	int i;
	i = 0;
	while (i < 3)
	{
		printf("%s\n", test[i]);
		i++;
	}
	while (i > 0)
	{
		free(test[i - 1]);
		i--;
	}
	free(test);
	*/

	// char *a = "hi %s hello%s%s";
	// ft_printf(a, "MOON", "GU", "WHA");

	// ft_printf("hello %d %d %d ", 1, 2, 3);
	// ft_printf("hello%d%d%d", 1, 2, 3);
	// ft_printf("hello %c%c%c%c", 'm', 'o', 'o', 'n');

	// ft_printf("===============\n");
}