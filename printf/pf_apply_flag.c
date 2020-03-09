/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 02:17:06 by gmoon            ###   ########.fr       */
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
	if (f_info.c_arg_nega == 1)
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
		if (f_info.c_arg_nega == 1) //
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
		if (f_info.c_arg_nega == 1)
			ret[i++] = '-';
		while (i < f_info.precision - c_arg_size + f_info.c_arg_nega) // 맞나?
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
		if (f_info.c_arg_nega == 1)
			ret[i++] = '-';
		while (j < c_arg_size)
			ret[i++] = (*c_arg)[j++];
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
			ret[i++] = (*c_arg)[j++];
	}
	else if (f_info.minus == 0 && f_info.zero == 0)
	{
		// printf("(%d,%d)\n", f_info.width, c_arg_size);
		while (i < f_info.width - c_arg_size)
			ret[i++] = ' ';
		if (f_info.c_arg_nega == 1)
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

char *apply_flag(char *c_arg, t_f_info f_info, t_info info)
{
	char *ret;
	int c_arg_size;
	int ret_size;

	if (ft_strncmp(c_arg, "0", sizeof(c_arg)) == 0 && f_info.precision == 0 &&
		is_contain(info.flag, '.') == 1 && f_info.prec_nega == 0)
		c_arg = ft_strdup("");
	if ((int)ft_strlen(c_arg) >= pf_max(f_info.width, f_info.precision))
		return (c_arg);
	if (c_arg[0] == '-' && ++f_info.c_arg_nega)
		c_arg = ft_substr(c_arg, 1, ft_strlen(c_arg) - 1); // 맞나?
	c_arg_size = ft_strlen(c_arg);
	if (f_info.width < f_info.precision && f_info.c_arg_nega == 1)
		f_info.precision++;
	ret_size = pf_max(f_info.width, f_info.precision);
	f_info.width = (c_arg_size > f_info.width) ? 0 : f_info.width;
	f_info.precision = (c_arg_size > f_info.precision) ? 0 : f_info.precision;
	if (f_info.width == 0 && f_info.precision == 0)
		return (c_arg);
	if (!(ret = (char *)malloc(ret_size + 1)))
		return (0); // 이런건 삼항으로 못줄이나? else가 없어서?
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


static char *p_bigger_then_w_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
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

static char *w_bigger_then_p_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size)
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

char *apply_flag_s(char *c_arg, t_f_info f_info, t_info info) // 따로 만드는게 나을수도
{
	char *c_arg_dup;
	char *ret;
	int c_arg_size;
	int ret_size;
	// printf("(%d, %d, %d, %d)\n", f_info.minus, f_info.zero, f_info.width, f_info.precision);

	f_info.zero = 0;
	if (c_arg == 0 || c_arg[0] == '\0') // 삼항연산자 쓸수있지만 free해줘야해서...
		c_arg_dup = ft_strdup(""); // 일단 함수포인터 이용한 함수 짜기 전까진 놔둠.
	else if (ft_strncmp(c_arg, "(null)", sizeof(c_arg)) == 0 && 0 < f_info.precision && f_info.precision < 6)
		c_arg_dup = ft_strdup("");
	else if (is_contain(info.flag, '.') == 1 && !f_info.width && f_info.prec_nega == 0)
		return(ft_substr(c_arg, 0, pf_min(f_info.precision, (int)ft_strlen(c_arg))));
	else if (is_contain(info.flag, '.') == 1 && f_info.prec_nega == 0) // 와 지옥이다.. 정리 필요
		c_arg_dup = ft_substr(c_arg, 0, pf_min(f_info.precision, (int)ft_strlen(c_arg)));
	else if (f_info.width == 0 && f_info.precision == 0)
		return (c_arg_dup); // 이거는 여기 들어오기전에 검사해도 될듯. 그냥 f_info == 0은 안되겠지?
	else
		c_arg_dup = ft_strdup(c_arg); // 하... 여긴 구조적으로 다 고쳐봐야...
	c_arg_size = ft_strlen(c_arg_dup);
	if (f_info.precision && !f_info.width && c_arg_size <= f_info.precision)
		return (c_arg);
	else if (f_info.precision && !f_info.width && c_arg_size > f_info.precision)
		return (ft_substr(c_arg, 0, f_info.precision));
	else if (f_info.width && !f_info.precision && c_arg_size > f_info.width)
		return (c_arg);
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
	free(c_arg); // 와 이건 못줄이겠는데.. 분리밖에 답이 없겠다.
	return (ret);
}

