/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 06:49:14 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>


int make_precision(t_info *info)
{
	char *tmp;
	int flag_len;
	int i;
	int ret_size;
	int ret; // 변수 많을땐 구조체 이용해서 줄수 줄일 수 있을듯.
	
	(*info).prec_star = 0; // 다른데서 해줘도 되고..
	if ((*info).flag == NULL || ft_strchr((*info).flag, '.') == NULL)
		return 0;
	flag_len = ft_strlen((*info).flag);
	i = 0;
	while ((*info).flag[flag_len - i - 1] != '.' && (*info).flag[flag_len - i - 1])
		i++;
	if (i == 0)
		return (0); // 이렇게 하면 되나? 바로 점 만나니까?
	if (i == 1 && (*info).flag[flag_len - 1] == '*') // wc를 -1로 했었네. 내용 없을때를 -2로 해야할듯..?
		{
			(*info).prec_star = 1; // if문에 올려도 되지않나?
			return (0);
		}
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	ret_size = i;
	while (--i >= 0)
		tmp[ret_size - i - 1] = (*info).flag[flag_len - i - 1];
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
}

int make_width(t_info *info)
{
	int i;
	int start;
	int count;
	char *tmp;
	int ret;

	if ((*info).flag == NULL)
	{
		return (0);
	}
	i = 0;
	start = -1;
	count = width_digit_count((*info).flag, &i, &start);
	(*info).width_star = 0;
	if (count == 0) // || count == -1)
		return (0);
	else if (count == -1) // 하... 모르고 이렇게 짜버렸네... 일단 되게하고 나중에 줄이자. 대폭 줄일수 있을듯.
	{
		(*info).width_star = 1;
		return (0);
	}
	if (!(tmp = (char *)malloc(count + 1)))
		return (0);
	tmp[count] = '\0';
	i = start - 1;
	while ((*info).flag[++i] != '.' && (*info).flag[i])
		tmp[i - start] = (*info).flag[i];
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

t_f_info make_f_info(t_info info, va_list ap) //, int *is_wc_width, int *is_wc_precision)
{
	static t_f_info ret;

	ret.minus = 0;
	ret.zero = 0;
	ret.prec_nega = 0;
	ret.width_nega = 0;
	// if (*is_wc_width == 0 && *is_wc_precision == 0)
	// {
	// 	if ((ret.width = make_width(&info)) == -1)
	// 		wc_process1(&ret, ap, &is_wc_width);
	// 	if ((ret.precision = make_precision(&info)) == -1) //
	// 		wc_process2(&ret, ap, &is_wc_precision);
	// 	if (*is_wc_width == 1 || *is_wc_width == 1)
	// 		return (ret);
	// }
	ret.width = make_width(&info);
	ret.precision = make_precision(&info);
	// printf("(%d,%d)", ret.width, ret.precision);
	if (info.width_star == 1)
		ret.width = va_arg(ap, int);
	if (info.prec_star == 1)
		ret.precision = va_arg(ap, int); // 바로 될까?
	if (ret.width < 0)
	{
		ret.minus = 1;
		ret.width_nega = 1; // 이거...있어야하지않을까? 일단 해놓음.
		ret.width = ret.width * -1;
	}
	if (ret.precision < 0)
	{
		ret.minus = 1; // 이거는 확인해봐야
		ret.prec_nega = 1; // 이거...있어야하지않을까? 일단 해놓음.
		ret.precision = ret.precision * -1;
	}
	if (ret.width == 0 && ret.precision == 0) // %-0d 폭x 정밀도x
		ret = w0_p0(ret, info.flag);
	else if (ret.width == 0 && ret.precision != 0) // %-0.5d 폭x 정밀도o
		ret= w0_p1(ret, info.flag);
	else if (ret.width != 0) // %-01d 폭o
		ret = w1(ret, info.flag);
	return (ret);
}
