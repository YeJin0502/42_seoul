/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 20:24:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>
int ft_printf(const char *format, ...)
{
	int count_a;
	int count_s;
	t_info *info;
	va_list ap;
	int ret;

	count_s = 0;
	if (!(count_a = count_arg(format, &count_s)))
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	va_start(ap, format);
	info = make_info_and_free(format, count_s);
	ret = print_and_count(format, count_s, info, ap);
	free(info);
	return (ret);
}
