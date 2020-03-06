/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 19:53:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_flag(char *c_arg, char spec, t_f_info f_info)
{
	char *ret;
	int c_arg_size;
	int ret_size;
	int i;
	int j;

	c_arg_size = ft_strlen(c_arg);
	if (spec == 's')
		f_info.precision = 0;
	if ((int)ft_strlen(c_arg) >= f_info.width && (int)ft_strlen(c_arg) >= f_info.precision)
		return (c_arg);
	ret_size = ft_max(f_info.width, f_info.precision);
	ret = (char *)malloc(ret_size + 1);
	ret[ret_size] = '\0';
	// printf("!%d, %d, %d, %d!\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	i = 0;
	j = 0;
	if (f_info.width <= f_info.precision) // 폭 < 정밀도
	{
		while (i < (ret_size - c_arg_size))
			ret[i++] = '0';
		while (j < c_arg_size)
			ret[i++] = c_arg[j++];
		return (ret);
	}
	else if (f_info.width > f_info.precision && f_info.precision) // 정밀도 있고, 폭>정밀도
	{
		if (f_info.minus == 0)
		{
			while (i < (ret_size - f_info.precision))
				ret[i++] = ' ';
			while (i < (ret_size - c_arg_size))
				ret[i++] = '0';
			while (i < f_info.width)
				ret[i++] = c_arg[j++];
		}
		else if (f_info.minus == 1)
		{
			while (i < f_info.precision - c_arg_size)
				ret[i++] = '0';
			while (j < c_arg_size)
				ret[i++] = c_arg[j++];
			while (i < f_info.width)
				ret[i++] = ' ';
		}
	}
	else if (f_info.width) // 폭이 있을 때
	{
		if (f_info.minus == 1 && f_info.zero == 0) // 수정할수있을수도
		{
			while (i < c_arg_size)
				ret[i++] = c_arg[j++];
			while (i < f_info.width)
				ret[i++] = ' ';
		}
		else if (f_info.minus == 0 && f_info.zero == 1)
		{
			while (i < f_info.width - c_arg_size)
				ret[i++] = '0';
			while (i < f_info.width)
				ret[i++] = c_arg[j++];
		}
		else if (f_info.minus == 0 && f_info.zero == 0)
		{
			while (i < f_info.width - c_arg_size)
				ret[i++] = ' ';
			while (i < f_info.width)
				ret[i++] = c_arg[j++];
		}
	}
	return (ret);	
}
