/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info_subprocess.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 21:38:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f_info w0_p0(t_f_info ret, char *flag)
{
	while (*flag)
		{
			if (*flag == '-')
				ret.minus = 1;
			if (*flag == '0')
				ret.zero = 1;
			flag++;
		}
	return (ret);
}

t_f_info w0_p1(t_f_info ret, char *flag)
{
	while (*flag != '.')
	{
		if (*flag == '-')
			ret.minus = 1;
		if (*flag == '0')
			ret.zero = 1;
		flag++;
	}
	return (ret);
}

t_f_info w1(t_f_info ret, char *flag)
{
	while (!(('1' <= *flag && *flag <= '9') || *flag == '*'))
	{
		if (*flag == '-')
			ret.minus = 1;
		if (*flag == '0')
			ret.zero = 1;
		flag++;
	}
	return (ret);
}

t_f_info wc_process1(t_f_info *ret, va_list ap, int *is_wc_width)
{
	(*ret).width = va_arg(ap, int);
	*is_wc_width = 1;
	return (*ret);
}

t_f_info wc_process2(t_f_info *ret, va_list ap, int *is_wc_precision)
{
	(*ret).precision = va_arg(ap, int);
	*is_wc_precision = 1;
	return (*ret);
}
