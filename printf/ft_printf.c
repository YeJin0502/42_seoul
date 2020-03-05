/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 07:53:58 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int count_s;
	t_info *info;
	va_list ap;
	int ret;

	if (!(count_s = count_spec(format)))
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	info = make_info_and_free(format, count_s);
	va_start(ap, format);
	ret = print_and_count(format, count_s, info, ap);
	free(info);
	return (ret);
}
