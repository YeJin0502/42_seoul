/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 09:59:42 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else if (!(*(format - 1) != '%' && *format == '%')) // && ++ret)
		{
			write(1, format, 1);
			ret++;
		}
		if (format == 0)
			return (-1);
		format++;
	}
	while (--i >= 0)
		free(info[i].flag);
	free(info);
	return (ret);
}

const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap)
{
	int i;

	i = 0;
	format++;
	while (*(format + i) == *(info.flag + i))
		i++;
	if (is_spec(info.spec) == 1)
		*ret = *ret + get_va_arg(ap, info);
	else
		return (0);
	return (format + i);
}

int	get_va_arg(va_list ap, t_info info)
{
	char	*c_arg;
	char	*c_arg_ret;
	int		ret_size;

	info.f_info = make_f_info(info, ap);
	if (info.spec == 'c')
		c_arg = get_va_arg_c(ap);
	else if (info.spec =='s')
		c_arg = get_va_arg_s(ap);
	else if (info.spec == 'p')
		c_arg = get_va_arg_p(ap, info.spec);
	else if (info.spec == 'd' || info.spec =='i')
		c_arg = get_va_arg_di(ap);
	else
		c_arg = get_va_arg_uxX(ap, info.spec);
	if (*(info.flag) != '\0' && info.spec != 's')
		c_arg_ret = apply_flag(c_arg, info.f_info, info);
	else if (*(info.flag) != '\0' && info.spec == 's')
		c_arg_ret = apply_flag_s(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}
