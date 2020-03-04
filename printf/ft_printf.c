/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 07:27:40 by gmoon            ###   ########.fr       */
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
	} // 이런거도 함수 빼버릴 수도 있겠다.
	va_start(ap, format);
	flags = make_flags(format, count_s);
	specs = make_specs(format, count_s);
	info = make_list(specs, flags); // 이런건 하나의 함수로 묶을수도 있겠다. free도 마찬가지.
	
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
			format = meet_percent(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		else
		{
			write(1, format, 1);
			ret++; // 아니면 한글자씩 출력
		}
		format++; // 여기서 spec 넘어감.
	}
	while (--i >= 0) // free
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

