/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_no_spec_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:36:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 04:36:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_spec_print(const char *format)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%' && ++format)
			while (*format != '%' && *format)
				format++;
		write(1, format, 1);
		ret++;
		format++;
	}
	return (ret);
}
