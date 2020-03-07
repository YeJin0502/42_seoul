/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 17:36:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *p_bigger_then_w(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (f_info.precision - c_arg_size))
		ret[i++] = '0';
	while (i < f_info.precision)
		ret[i++] = (*c_arg)[j++];
	free(*c_arg);
	return (ret);
}

static char *w_bigger_then_p(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.minus == 0)
	{
		while (i < (f_info.width - f_info.precision))
			ret[i++] = ' ';
		while (i < (f_info.width - c_arg_size))
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 1)
	{
		while (i < f_info.precision - c_arg_size)
			ret[i++] = '0';
		while (j < c_arg_size)
			ret[i++] = (*c_arg)[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	free(*c_arg);
	return (ret);
}

static char *w_exist(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.minus == 1 && f_info.zero == 0) // 수정할수있을수도
	{
		while (i < c_arg_size)
			ret[i++] = (*c_arg)[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	else if (f_info.minus == 0 && f_info.zero == 1)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	free(*c_arg);
	return (ret);
}

#include <stdio.h>
char *apply_flag(char *c_arg, char spec, t_f_info f_info)
{
	char *ret;
	int c_arg_size;
	int ret_size;

	if (spec == 0)
		return (0); // 컴파일용
	// printf("(%d, %d, %d, %d)\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	c_arg_size = ft_strlen(c_arg);
	if ((int)ft_strlen(c_arg) >= ft_max(f_info.width, f_info.precision))
		return (c_arg);
	ret_size = ft_max(f_info.width, f_info.precision);
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0);
	ret[ret_size] = '\0';
	if (f_info.width <= f_info.precision)
		return (p_bigger_then_w(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width > f_info.precision && f_info.precision)
		return (w_bigger_then_p(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width)
		return (w_exist(ret, &c_arg, f_info, c_arg_size));
	free(c_arg);
	return (ret);
}

char *apply_flag_s(char *c_arg, t_f_info f_info) // 따로 만드는게 나을수도
{ // 따로 만들면 spec 필요 없을수도 있겠다. 숫자들도 다 똑같으면... 거기도 spec 뺄수있음.
	char *ret;
	int c_arg_size;
	int ret_size;

	// printf("(%d, %d, %d, %d)\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	c_arg_size = ft_strlen(c_arg);
	if (c_arg_size < f_info.precision)
		return (c_arg);
	else if (c_arg_size > f_info.width)
		return (c_arg);
	if ((int)ft_strlen(c_arg) >= ft_max(f_info.width, f_info.precision)) //이런곳도
		return (c_arg);
	ret_size = ft_max(f_info.width, f_info.precision);
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0);
	ret[ret_size] = '\0';
	if (f_info.width <= f_info.precision)
		return (p_bigger_then_w(ret, &c_arg, f_info, c_arg_size)); // 이런거 다 문자열에 맞게 고쳐야
	else if (f_info.width > f_info.precision && f_info.precision)
		return (w_bigger_then_p(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width)
		return (w_exist(ret, &c_arg, f_info, c_arg_size));
	free(c_arg);
	return (ret);
}
