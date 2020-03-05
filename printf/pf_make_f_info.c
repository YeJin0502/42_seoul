/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 07:59:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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