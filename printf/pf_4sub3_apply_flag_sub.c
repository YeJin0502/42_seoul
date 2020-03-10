/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:15:40 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 04:28:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_bigger_then_w(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	if (f_info.c_arg_nega == 1)
		ret[index.i++] = '-';
	while (index.i < (f_info.precision - c_arg_size))
		ret[index.i++] = '0';
	while (index.i < f_info.precision)
		ret[index.i++] = c_arg[index.j++];
}

void	p_bigger_then_w_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	if (f_info.minus == 0)
	{
		while (index.i < (f_info.width - c_arg_size))
			ret[index.i++] = ' ';
		while (index.j < pf_min(c_arg_size, f_info.precision))
			ret[index.i++] = c_arg[index.j++];
	}
	else if (f_info.minus == 1)
	{
		while (index.i < f_info.width - c_arg_size)
			ret[index.i++] = ' ';
		while (index.j < pf_min(c_arg_size, f_info.precision))
			ret[index.i++] = c_arg[index.j++];
	}
}

void	w_bigger_then_p(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	if (f_info.minus == 0)
	{
		while (index.i < (f_info.width - f_info.precision))
			ret[index.i++] = ' ';
		if (f_info.c_arg_nega == 1 && --index.i)
			ret[index.i++] = '-';
		while (index.i < (f_info.width - c_arg_size))
			ret[index.i++] = '0';
		while (index.i < f_info.width)
			ret[index.i++] = c_arg[index.j++];
	}
	else if (f_info.minus == 1)
	{
		if (f_info.c_arg_nega == 1)
			ret[index.i++] = '-';
		while (index.i < f_info.precision - c_arg_size + f_info.c_arg_nega)
			ret[index.i++] = '0';
		while (index.j < c_arg_size)
			ret[index.i++] = c_arg[index.j++];
		while (index.i < f_info.width)
			ret[index.i++] = ' ';
	}
}

void	w_bigger_then_p_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	if (f_info.minus == 0)
	{
		while (index.i < (f_info.width - f_info.precision))
			ret[index.i++] = ' ';
		while (index.i < (f_info.width - c_arg_size))
			ret[index.i++] = ' ';
		while (index.i < f_info.width)
			ret[index.i++] = c_arg[index.j++];
	}
	else if (f_info.minus == 1)
	{
		while (index.i < pf_min(c_arg_size, f_info.precision))
			ret[index.i++] = c_arg[index.j++];
		while (index.i < f_info.width)
			ret[index.i++] = ' ';
	}
}
