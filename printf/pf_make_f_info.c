/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 20:50:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int make_precision(char *flag)
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
	if (i == 1 && flag[flag_len - 1] == '*') //
		return (-1);
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	ret_size = i;
	while (--i >= 0)
		tmp[ret_size - i - 1] = flag[flag_len - i - 1];
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

static int width_digit_count(char *flag, int *i, int *start)
{
	int count;
	
	count = 0;
	while (flag[*i] != '.' && flag[*i])
	{
		if (*start == -1 && ('1' <= flag[*i] && flag[*i] <= '9'))
			*start = *i;
		if (*start > -1)
			(count)++;
		if (flag[*i] == '*')
			return (-1);
		(*i)++;
	}
	(*i) = *start;
	return (count);
} // 이렇게 함수 나눠도 되나..? 함수 개수는 많아지지만 줄수는 무조건 줄이는거 가능인데..?

static int make_width(char *flag)
{
	int i;
	int start;
	int count;
	char *tmp;
	int ret;
	if (flag == NULL)
		return (0);
	i = 0;
	start = -1;
	count = width_digit_count(flag, &i, &start);
	if (count == 0 || count == -1)
		return (count);
	if (!(tmp = (char *)malloc(count + 1)))
		return (0);
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

t_f_info make_f_info(char *flag, va_list ap, int *is_wc_width, int *is_wc_precision)
{
	static t_f_info ret;

	ret.minus = 0;
	ret.zero = 0;

	if (*is_wc_width == 0 && *is_wc_precision == 0)
	{
		if ((ret.width = make_width(flag)) == -1)
		{
			ret.width = va_arg(ap, int);
			*is_wc_width = 1;
		}
		if ((ret.precision = make_precision(flag)) == -1)
		{
			ret.precision = va_arg(ap, int);
			*is_wc_precision = 1;
		}
		return (ret);
	}
	// printf("width:%d, precision:%d, wc:%d\n",ret.width, ret.precision, *is_wildcard);
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
	{
		while (!(('1' <= *flag && *flag <= '9') || *flag == '*'))
		{
			if (*flag == '-')
				ret.minus = 1;
			if (*flag == '0')
				ret.zero = 1;
			flag++;
		}
	}
	return (ret);
}