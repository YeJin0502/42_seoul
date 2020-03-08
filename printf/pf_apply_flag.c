/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/08 19:50:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

static char *p_bigger_then_w(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.negative == 1)
		ret[i++] = '-';
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
		// printf("(%d,%d,%d)\n", i, f_info.precision, c_arg_size);
		while (i < (f_info.width - f_info.precision))
			ret[i++] = ' ';
		if (f_info.negative == 1) //
		{
			ret[--i] = '-';
			i++;
		}
		while (i < (f_info.width - c_arg_size))
			ret[i++] = '0'; // 이거 갑자기 왜안되냐?
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 1)
	{
		if (f_info.negative == 1)
			ret[i++] = '-';
		while (i < f_info.precision - c_arg_size + f_info.negative) // 맞나?
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
		if (f_info.negative == 1)
			ret[i++] = '-';
		while (j < c_arg_size)
			ret[i++] = (*c_arg)[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	else if (f_info.minus == 0 && f_info.zero == 1)
	{
		if (f_info.negative == 1)
			ret[i++] = '-';
		while (i < f_info.width - c_arg_size)
			ret[i++] = '0';
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
	{
		// printf("(%d,%d)\n", f_info.width, c_arg_size);
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		if (f_info.negative == 1)
		{
			// --i; // 얘는 왜 안써줘도 되지..? 뭔차이야
			ret[--i] ='-';
			i++; // 아.. s함수에서도 이걸 같이 써서.. 줄이면 오류가 난다.
		}
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	free(*c_arg);
	return (ret);
}

char *apply_flag(char *c_arg, t_f_info f_info)
{
	char *ret;
	int c_arg_size;
	int ret_size; // 와 음수 0옵션 고려하려면 또 고쳐야하네.

	if (f_info.precision > 0)
		f_info.zero = 0;
	// printf("(%d, %d, %d, %d)\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	if (ft_strncmp(c_arg, "0", sizeof(c_arg)) == 0 && f_info.precision == -2)
	{
		// printf("zz\n");
		c_arg = ft_strdup("");
	}
	if ((int)ft_strlen(c_arg) >= pf_max(f_info.width, f_info.precision))
		return (c_arg);
	if (c_arg[0] == '-')
	{
		f_info.negative = 1; // 초기화 안하고 여기서 처음 쓰는건데 잘 될까?
		c_arg = ft_substr(c_arg, 1, ft_strlen(c_arg) - 1); // 맞나?
	}
	else
		f_info.negative = 0; // 안하면 쓰레기값 있나?	
	c_arg_size = ft_strlen(c_arg);
	if (f_info.width < f_info.precision && f_info.negative == 1)
		f_info.precision++;
	ret_size = pf_max(f_info.width, f_info.precision);
	if (c_arg_size > f_info.width)
		f_info.width = 0;
	else if (c_arg_size > f_info.precision)
		f_info.precision = 0;
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0);
	ret[ret_size] = '\0';
	// printf("(%d)\n", ret_size);
	if (f_info.width <= f_info.precision) // && f_info.width)
		return (p_bigger_then_w(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width > f_info.precision && f_info.precision)
		return (w_bigger_then_p(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width)
		return (w_exist(ret, &c_arg, f_info, c_arg_size));
	if (f_info.width == 0 && f_info.precision == 0)
		return (c_arg); //
	free(c_arg);
	return (ret);
}


char *p_bigger_then_w_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
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
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 1)
	{
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		while (j < pf_min(c_arg_size, f_info.precision))
			ret[i++] = (*c_arg)[j++];
	}
	free(*c_arg);
	return (ret);
}

char *w_bigger_then_p_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f_info.precision == -2)
		while(i < f_info.width)
			ret[i++] = ' ';
	else if (f_info.minus == 0)
	{
		while (i < (f_info.width - f_info.precision))
			ret[i++] = ' ';
		while (i < (f_info.width - c_arg_size))
			ret[i++] = ' ';
		while (i < f_info.width)
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 1)
	{
		// printf("w:%d, c:%d\n", f_info.width, pf_min(c_arg_size, f_info.precision));
		while (i < pf_min(c_arg_size, f_info.precision))
			ret[i++] = (*c_arg)[j++];
		while (i < f_info.width)
			ret[i++] = ' ';
	}
	free(*c_arg);
	return (ret);
}

int is_contain(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char *apply_flag_s(char *c_arg, t_f_info f_info, t_info info) // 따로 만드는게 나을수도
{ // 따로 만들면 spec 필요 없을수도 있겠다. 숫자들도 다 똑같으면... 거기도 spec 뺄수있음.
	char *ret;
	int c_arg_size;
	int ret_size;

	// printf("(%d, %d, %d, %d)\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);
	f_info.zero = 0;
	if (c_arg == 0) // 이걸까..?
		c_arg = ft_strdup("");
	if (f_info.width == 0 && f_info.precision == 0)
		return (c_arg); // 이거는 여기 들어오기전에 검사해도 될듯. 그냥 f_info == 0은 안되겠지?
	if (ft_strncmp(c_arg, "(null)", sizeof(c_arg)) == 0 && f_info.precision && f_info.precision < 6)
		c_arg = ft_strdup("");
	if (is_contain(info.flag, '.') == 1 && f_info.width == 0 && f_info.precision == 0)
		return (0);
	if (f_info.precision == -2)
		c_arg = ft_strdup(""); // 아마 메모리 누수 발생할듯..? 문자열 교체하는 함수 없나?
	c_arg_size = ft_strlen(c_arg);
	if (f_info.precision && !f_info.width && c_arg_size <= f_info.precision)
		return (c_arg);
	else if (f_info.precision && !f_info.width && c_arg_size > f_info.precision)
		return (ft_substr(c_arg, 0, f_info.precision));
	else if (f_info.width && !f_info.precision && c_arg_size > f_info.width)
		return (c_arg);
	// else if 
	ret_size = pf_max(f_info.width, f_info.precision);
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0);
	ret[ret_size] = '\0';
	if (f_info.width <= f_info.precision && f_info.width) //
		return (p_bigger_then_w_s(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width > f_info.precision && f_info.precision)
		return (w_bigger_then_p_s(ret, &c_arg, f_info, c_arg_size));
	else if (f_info.width)
		return (w_exist(ret, &c_arg, f_info, c_arg_size));
	free(c_arg);
	return (ret);
}
// 테스트 돌리니까 예외가 자꾸 느네. 또 나중에 한번에 정리해야지..ㅠㅠ

