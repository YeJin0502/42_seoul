/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 00:50:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *p_bigger_then_w(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;

	i = 0;
	while (i < (f_info.precision - c_arg_size))
		ret[i++] = '0';
	while (i < f_info.precision)
		ret[i++] = *(c_arg++);
	return (ret);
}

static char *w_bigger_then_p(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;

	i = 0;
	if (f_info.minus == 0)
	{
		while (i < (f_info.width - f_info.precision))
			ret[i++] = ' ';
		while (i < (f_info.width - c_arg_size))
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = *(c_arg++);
	}
	else if (f_info.minus == 1)
	{
		while (i < f_info.precision - c_arg_size)
			ret[i++] = '0';
		while (*c_arg)
			ret[i++] = *(c_arg++);
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	return (ret);
}

static char *w_exist(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;

	i = 0;
	if (f_info.minus == 1 && f_info.zero == 0) // 수정할수있을수도
	{
		while (i < c_arg_size)
			ret[i++] = *(c_arg++);
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	else if (f_info.minus == 0 && f_info.zero == 1)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = *(c_arg++);
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		while (i < f_info.width)
			ret[i++] = *(c_arg++);
	}
	return (ret);
}

#include <stdio.h>
char *apply_flag(char *c_arg, char spec, t_f_info f_info)
{
	char *ret;
	int c_arg_size;
	int ret_size;

	c_arg_size = ft_strlen(c_arg);
	if (spec == 's')
		f_info.precision = 0;
	if ((int)ft_strlen(c_arg) >= ft_max(f_info.width, f_info.precision))
		return (c_arg);
	ret_size = ft_max(f_info.width, f_info.precision);
	ret = (char *)malloc(ret_size + 1);
	ret[ret_size] = '\0';
	if (f_info.width <= f_info.precision)
		return (p_bigger_then_w(ret, c_arg, f_info, c_arg_size));
	else if (f_info.width > f_info.precision && f_info.precision)
		return (w_bigger_then_p(ret, c_arg, f_info, c_arg_size));
	else if (f_info.width)
		return (w_exist(ret, c_arg, f_info, c_arg_size));
	return (ret);
}
