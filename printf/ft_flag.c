/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:27:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 05:10:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int make_precision(char *flag)
{
	char *tmp;
	int flag_len;
	int i;
	int ret_size;
	int ret;
	
	if (flag == NULL || ft_strchr(flag, '.') == NULL)
		return 0;
	flag_len = ft_strlen(flag);
	i = 0;
	while (flag[flag_len - i - 1] != '.' && flag[flag_len - i - 1])
		i++;
	if (i == 0)
		return (0);
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	ret_size = i;
	while (--i >= 0)
		tmp[ret_size - i - 1] = flag[flag_len - i - 1];
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

int make_width(char *flag)
{
	int start;
	int i;
	int count;
	char *tmp;
	int ret;

	start = -1;
	i = 0;
	count = 0;
	if (flag == NULL) // 아마 여기 수정해야 오류가 덜날듯?
		return 0;
	while (flag[i] != '.' && flag[i])
	{
		if (start == -1 && ('1' <= flag[i] && flag[i] <= '9'))
			start = i;
		if (start > -1)
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	tmp = (char *)malloc(count + 1);
	tmp[count] = '\0';
	i = start;
	while (flag[i] != '.' && flag[i])
	{
		tmp[i - start] = flag[i];
		i++;
	}
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

t_f_info make_f_info(char *flag)
{
	t_f_info ret;

	ret.minus = 0;
	ret.zero = 0;
	ret.width = make_width(flag);
	ret.precision = make_precision(flag);
	if (ret.width == 0 && ret.precision == 0) // %-0d 폭x 정밀도x
		while (*flag)
		{
			if (*flag == '-')
				ret.minus = 1;
			if (*flag == '0')
				ret.zero = 1;
			flag++;
		}
	else if (ret.width == 0 && ret.precision != 0) // %-0.5d 폭x 정밀도o
		while (*flag != '.')
		{
			if (*flag == '-')
				ret.minus = 1;
			if (*flag == '0')
				ret.zero = 1;
			flag++;
		}
	else if (ret.width != 0) // %-01d 폭o
		while (!('1' <= *flag && *flag <= '9'))
		{
			if (*flag == '-')
				ret.minus = 1;
			if (*flag == '0')
				ret.zero = 1;
			flag++;
		}
	return (ret);
}

int ft_max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

char *convert_flag(char *c_arg, char *flag, char spec)
{
	char *ret;
	int c_arg_size;
	t_f_info f_info;
	int ret_size;
	int i;
	int j;

	c_arg_size = ft_strlen(c_arg);
	f_info = make_f_info(flag);
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

/*
char *convert_flag_s(char *c_arg, char *flag)
{
	char *ret;
	t_f_info f_info;
	int c_arg_size;

	c_arg_size = ft_strlen(c_arg);
	f_info = make_f_info(flag);
	// printf("!%d, %d, %d, %d!\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	if ((int)ft_strlen(c_arg) >= f_info.width && (int)ft_strlen(c_arg) >= f_info.precision)
		return (c_arg);
	int ret_size;
	ret_size = ft_max(f_info.width, f_info.precision);
	ret = (char *)malloc(ret_size + 1);
	ret[ret_size] = '\0';
	int i;
	i = 0;
	int j;
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
		if (f_info.minus == 1 && f_info.zero == 0)
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
*/