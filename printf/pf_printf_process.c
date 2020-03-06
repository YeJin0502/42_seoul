/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 20:29:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	count_arg(const char *format, int *count_s)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format - 1) != '%')
		{
			count++;
			(*count_s)++;
		}
		else if (*format == '*')
			count++;
		format++;
	}
	return (count);
}

t_info	*make_info_and_free(const char *format, int count_s)
{
	t_info	*ret;
	char	*specs;
	char	**flags;
	if (!(specs = make_specs(format, count_s)))
		return (0);
	if (!(flags = make_flags(format, count_s)))
	{
		free(specs);
		return (0);
	}
	if (!(ret = make_info(specs, flags)))
	{
		free(specs);
		while (*flags)
			free(flags++);
		return (0);
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
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
			format = meet_specifier(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		else
		{
			write(1, format, 1);
			ret++;
		}
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
}

const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap)
{
	format++;
	format = skip_flag(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + c_process(ap, info.flag, info.spec);
	else if (info.spec == 's')
		*ret = *ret + s_process(ap, info.flag, info.spec);
	else if (info.spec == 'p')
		*ret = *ret + p_process(ap, info.flag, info.spec);
	else if (info.spec == 'd' || info.spec == 'i')
		*ret = *ret + di_process(ap, info.flag, info.spec);
	else if (info.spec == 'u' || info.spec == 'x' || info.spec == 'X')
		*ret = *ret + uxX_process(ap, info.flag, info.spec);
	return (format);
}
