/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:27:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 08:37:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int make_precision(char *flag) // 없으면 -1 리턴.
{
	char *tmp;
	int flag_len;
	int i;
	int ret_size;
	int ret;

	flag_len = ft_strlen(flag);
	i = 0;
	while (flag[flag_len - i - 1] != '.')
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

int make_width(char *flag) // width 없으면 -1 리턴. 0으로 바꿀까?
{
	int start;
	int i;
	int count;
	char *tmp;
	int ret;

	start = -1;
	i = 0;
	count = 0;
	if (flag == NULL)
		return 0; // 없으면 아예 안보낼거같기도 한데..
	while (flag[i] != '.')
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
	while (flag[i] != '.')
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
} // 될라나.. 테스트 안해봄

int ft_max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

char *convert_flag(char *c_arg, char *flag)
{
	char *ret;
	t_f_info f_info;
	int c_arg_size;

	c_arg_size = ft_strlen(c_arg);
	f_info = make_f_info(flag);
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
	if (f_info.width <= f_info.precision)
	{
		while (i < (ret_size - c_arg_size))
			ret[i++] = '0';
		while (j < c_arg_size)
			ret[i++] = c_arg[j++];
		return (ret);
	}
	// else
	// {
	// 	while (i < (ret_size - f_info.precision))
	// 		ret[i++] = ' ';
	// 	while (i < (ret_size - c_arg_size)) // 맞을까..?
	// 		ret[i++] = '0';
	// 	while (i < f_info.width)
	// 		ret[i++] = c_arg[j++];
	// }
	return (ret);	
} // 경우의수 따져서 내일 해결해보자..

#include <stdio.h>
int main()
{
	char *a = convert_flag("123", "4.6");
	ft_printf("%s\n", a);

	// printf("%d\n", make_width("4.6"));
}



// #include <stdio.h>
// int main()
// {
// 	printf("[%4.2d]\n", 123); // [ 123]
// 	printf("[%5.6d]\n", 123); // [000123]
// }
