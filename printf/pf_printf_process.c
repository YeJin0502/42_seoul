/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 06:55:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	no_spec_print(const char *format)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format != '%' && *format)
				format++;
		}
		write(1, format, 1);
		ret++;
		format++;
	}
	return (ret);
}

int	print_and_count(const char *format, int count_s, t_info *info, va_list ap)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (*format)
	{
		if (*(format - 1) != '%' && *format == '%' && *(format + 1) != '%' && i < count_s)
			format = meet_specifier(&ret, format, *(info + i++), ap);
		else if (!(*(format - 1) != '%' && *format == '%'))
		{
			write(1, format, 1);
			ret++;
		}
		if (format == 0)
			return (-1);
		format++;
	}
	return (ret);
}

static const char	*skip_flag(const char *format, char *flag)
{
	while (*format == *flag)
	{
		format++;
		flag++;
	}
	return (format);
} // 이건 분리할 필요가 없어보이는데... 아니 합치면 자꾸 에러남. 뭔가 문법을 잘못 쓰는듯.

const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap)
{
	format++;
	format = skip_flag(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + c_process(ap, info);
	else if (info.spec == 's')
		*ret = *ret + s_process(ap, info);
	else if (info.spec == 'p')
		*ret = *ret + p_process(ap, info);
	else if (info.spec == 'd' || info.spec == 'i')
		*ret = *ret + di_process(ap, info);
	else if (info.spec == 'u' || info.spec == 'x' || info.spec == 'X')
		*ret = *ret + uxX_process(ap, info);
	else
		return (0);
	return (format);
}
