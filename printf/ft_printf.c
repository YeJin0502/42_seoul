/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 02:45:44 by gmoon            ###   ########.fr       */
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
	if ((info = make_info_and_free(format, count_s)) == 0)
		return (-1);	
	ret = print_and_count(format, count_s, info, ap);
	
	int i;
	i = 0;
	while (i < count_s)
		free(info[i++].flag);
	free(info);
	return (ret);
}
