/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 07:53:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_spec(const char *format)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format - 1) != '%')
			count++;
		format++;
	}
	return (count);
}

int print_and_count(const char *format, int count_s, t_info *info, va_list ap)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
			format = meet_percent(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++;
	}
	return (ret);
}
