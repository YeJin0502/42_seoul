/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 03:48:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	p_bigger_then_w(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (f_info.c_arg_nega == 1)
		ret[i++] = '-';
	while (i < (f_info.precision - c_arg_size))
		ret[i++] = '0';
	while (i < f_info.precision)
		ret[i++] = c_arg[j++];
}

static void p_bigger_then_w_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.minus == 0)
	{
		while (i < (f_info.width - c_arg_size))
			ret[i++] = ' ';
		while (j < pf_min(c_arg_size, f_info.precision))
			ret[i++] = c_arg[j++];
	}
	else if (f_info.minus == 1)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		while (j < pf_min(c_arg_size, f_info.precision))
			ret[i++] = c_arg[j++];
	}
}

/*
static void	w_bigger_then_p(char *ret, char *c_arg, t_info info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (info.f_info.minus == 0)
	{
		if (info.spec != 's')
		{
			while (i < (info.f_info.width - info.f_info.precision))
				ret[i++] = ' ';
			if (info.f_info.c_arg_nega == 1 && --i)
				ret[i++] = '-';
			while (i < (info.f_info.width - c_arg_size))
				ret[i++] = '0';
			while (i < info.f_info.width)
				ret[i++] = c_arg[j++];
		}
		else
		{
			while (i < (info.f_info.width - info.f_info.precision))
				ret[i++] = ' ';
			while (i < (info.f_info.width - c_arg_size))
				ret[i++] = ' ';
			while (i < info.f_info.width)
				ret[i++] = c_arg[j++];
		}
	}
	else if (info.f_info.minus == 1)
	{
		if (info.spec != 's')
		{
			if (info.f_info.c_arg_nega == 1)
				ret[i++] = '-';
			while (i < info.f_info.precision - c_arg_size + info.f_info.c_arg_nega)
				ret[i++] = '0';
			while (j < c_arg_size)
				ret[i++] = c_arg[j++];
		}
		else
		{
			while (i < pf_min(c_arg_size, info.f_info.precision))
				ret[i++] = c_arg[j++];
			while (i < info.f_info.width)
				ret[i++] = ' ';
		}
	}
}
*/


static void	w_bigger_then_p(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.minus == 0)
	{
		while (i < (f_info.width - f_info.precision))
			ret[i++] = ' ';
		if (f_info.c_arg_nega == 1 && --i)
			ret[i++] = '-';
		while (i < (f_info.width - c_arg_size))
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = c_arg[j++];
	}
	else if (f_info.minus == 1)
	{
		if (f_info.c_arg_nega == 1)
			ret[i++] = '-';
		while (i < f_info.precision - c_arg_size + f_info.c_arg_nega)
			ret[i++] = '0';
		while (j < c_arg_size)
			ret[i++] = c_arg[j++];
		while (i < f_info.width)
			ret[i++] = ' '; // s경우랑 합치고 minus 두개를 분리하는게 나을것같음.
	}
}

static void w_bigger_then_p_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
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
			ret[i++] = ' ';
		while (i < f_info.width)
			ret[i++] = c_arg[j++];
	}
	else if (f_info.minus == 1)
	{
		while (i < pf_min(c_arg_size, f_info.precision))
			ret[i++] = c_arg[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
}


static void w_exist(char *ret, char *c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.minus == 1 && f_info.zero == 0) // 수정할수있을수도
	{
		if (f_info.c_arg_nega == 1)
			ret[i++] = '-';
		while (j < c_arg_size)
			ret[i++] = c_arg[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	else if (f_info.minus == 0 && f_info.zero == 1)
	{
		if (f_info.c_arg_nega == 1)
			ret[i++] = '-';
		while (i < f_info.width - c_arg_size)
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = c_arg[j++];
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		if (f_info.c_arg_nega == 1 && --i)
			ret[i++] = '-' ;
		while (i < f_info.width)
			ret[i++] = c_arg[j++];
	}
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
	else if (f_info.width > f_info.precision && f_info.precision)
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
	// printf("(%d,%d,%d)", f_info.precision, f_info.c_arg_nega,f_info.width);
	if (f_info.width < f_info.precision && f_info.c_arg_nega == 1)
		f_info.precision++;
	c_arg_size = ft_strlen(c_arg_dup);
	f_info.width = (c_arg_size > f_info.width) ? 0 : f_info.width;
	f_info.precision = (c_arg_size > f_info.precision) ? 0 : f_info.precision;
	ret = make_ret(c_arg_dup, f_info, info, c_arg_size);
	free(c_arg_dup);
	return (ret);
}

char *apply_flag_s(char *c_arg, t_f_info f_info, t_info info)
{
	char *c_arg_dup;
	char *ret;
	int c_arg_size;

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
