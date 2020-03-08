/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 07:43:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>


int ft_printf(const char *format, ...)
{
	t_list *spec_adr;
	int count_s;
	va_list ap;
	t_info *info;
	int ret;
	int i;

	spec_adr = find_spec_adr(format);
	count_s = ft_lstsize(spec_adr);
	if (!count_s)
		return (no_spec_print(format));
	va_start(ap, format);
	if ((info = make_info_and_free(spec_adr, count_s)) == 0)
		return (-1);	
	ret = print_and_count(format, count_s, info, ap);
	i = 0;
	while (i < count_s)
		free(info[i++].flag);
	free(info);
	return (ret);
}
