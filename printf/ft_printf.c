/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 08:55:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_list *spec_adr;
	int count_s;
	va_list ap;
	t_info *info;
	int ret;

	spec_adr = find_spec_adr(format);
	count_s = ft_lstsize(spec_adr);
	if (!count_s)
		return (no_spec_print(format));
	va_start(ap, format);
	if ((info = make_info_and_free(spec_adr, count_s)) == 0)
		return (-1);	
	ret = print_and_count(format, count_s, info, ap);
	return (ret);
}
