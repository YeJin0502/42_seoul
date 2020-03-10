/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 04:16:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void w_exist_sub(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	while (index.i < f_info.width - c_arg_size)
		ret[index.i++] = ' ';
	if (f_info.c_arg_nega == 1 && --index.i)
		ret[index.i++] = '-' ;
	while (index.i < f_info.width)
		ret[index.i++] = c_arg[index.j++];
}

static void w_exist(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	t_index index;

	ft_memset(&index, 0, sizeof(index));
	if (f_info.minus == 1 && f_info.zero == 0)
	{
		if (f_info.c_arg_nega == 1)
			ret[index.i++] = '-';
		while (index.j < c_arg_size)
			ret[index.i++] = c_arg[index.j++];
		while (index.i < f_info.width)
			ret[index.i++] = ' ';
	}
	else if (f_info.minus == 0 && f_info.zero == 1)
	{
		if (f_info.c_arg_nega == 1)
			ret[index.i++] = '-';
		while (index.i < f_info.width - c_arg_size)
			ret[index.i++] = '0';
		while (index.i < f_info.width)
			ret[index.i++] = c_arg[index.j++];
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
		w_exist_sub(ret, c_arg, f_info, c_arg_size);
}

static char	*make_ret(char *c_arg_dup, t_f_info f_info, t_info info, int c_arg_size)
{
	int		ret_size;
	char	*ret;

	if (info.spec != 's')
		ret_size = pf_max(f_info.width, f_info.precision);
	else
		ret_size = pf_max(f_info.width, pf_min(c_arg_size, f_info.precision));
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0);
	ret[ret_size] = '\0';
	if (f_info.width <= f_info.precision && info.spec != 's')
		p_bigger_then_w(ret, c_arg_dup, f_info, c_arg_size);
	else if (f_info.width <= f_info.precision && info.spec == 's')
		p_bigger_then_w_s(ret, c_arg_dup, f_info, c_arg_size);
	else if (f_info.width > f_info.precision && f_info.precision && info.spec != 's')
		w_bigger_then_p(ret, c_arg_dup, f_info, c_arg_size);
	else if (f_info.width > f_info.precision && f_info.precision && info.spec == 's')
		w_bigger_then_p_s(ret, c_arg_dup, f_info, c_arg_size);
	else if (f_info.width)
		w_exist(ret, c_arg_dup, f_info, c_arg_size);
	return (ret);
}

char	*apply_flag(char *c_arg, t_f_info f_info, t_info info)
{
	char	*c_arg_dup;
	char	*ret;
	int		c_arg_size;

	if (ft_strncmp(c_arg, "0", sizeof(c_arg)) != 0 &&
		(int)ft_strlen(c_arg) >= pf_max(f_info.width, f_info.precision))
		return (ft_strdup(c_arg));
	else if (ft_strncmp(c_arg, "0", sizeof(c_arg)) == 0 && !f_info.precision &&
		is_contain(info.flag, '.') == 1) // 224, 231, 285, 286
		c_arg_dup = ft_strdup("");
	else if (c_arg[0] == '-' && ++f_info.c_arg_nega)
		c_arg_dup = ft_substr(c_arg, 1, ft_strlen(c_arg) - 1);
	else
		c_arg_dup = ft_strdup(c_arg);
	if (f_info.width < f_info.precision && f_info.c_arg_nega == 1)
		f_info.precision++;
	c_arg_size = ft_strlen(c_arg_dup);
	f_info.width = (c_arg_size > f_info.width) ? 0 : f_info.width;
	f_info.precision = (c_arg_size > f_info.precision) ? 0 : f_info.precision;
	ret = make_ret(c_arg_dup, f_info, info, c_arg_size);
	free(c_arg_dup);
	return (ret);
}

char	*apply_flag_s(char *c_arg, t_f_info f_info, t_info info)
{
	char	*c_arg_dup;
	char	*ret;
	int		c_arg_size;

	f_info.zero = 0;
	if (ft_strncmp(c_arg, "(null)", sizeof(c_arg)) == 0 && f_info.precision && f_info.precision < 6)
		c_arg_dup = ft_strdup("");
	else if (is_contain(info.flag, '.') == 1 && !f_info.width && f_info.prec_nega == 0)
		return (ft_substr(c_arg, 0, pf_min(f_info.precision, (int)ft_strlen(c_arg))));
	else if (is_contain(info.flag, '.') == 1 && f_info.width && f_info.prec_nega == 0) // 739
		c_arg_dup = ft_substr(c_arg, 0, pf_min(f_info.precision, (int)ft_strlen(c_arg)));
	else if (!f_info.precision && (int)ft_strlen(c_arg) > f_info.width)
		return (ft_strdup(c_arg));
	else
		c_arg_dup = ft_strdup(c_arg);
	c_arg_size = ft_strlen(c_arg_dup);
	ret = make_ret(c_arg_dup, f_info, info, c_arg_size);
	free(c_arg_dup);
	return (ret);
}
