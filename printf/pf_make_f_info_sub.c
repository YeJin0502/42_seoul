/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 08:22:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_digit_count(char *flag, int *i, int *start)
{
	int	count;
	
	count = 0;
	while (flag[*i] != '.' && flag[*i])
	{
		if (*start == -1 && ('1' <= flag[*i] && flag[*i] <= '9'))
			*start = *i;
		if (*start > -1)
			count++;
		if (flag[*i] == '*')
			return (-1);
		(*i)++;
	}
	(*i) = *start;
	return (count);
}

t_f_info w0_p0(t_f_info ret, char *flag)
{
	while (*flag)
	{
		if (*flag == '-')
			ret.minus = 1;
		if (*flag == '0')
			ret.zero = 1;
		flag++;
	}
	return (ret);
}

t_f_info w0_p1(t_f_info ret, char *flag)
{
	while (*flag != '.')
	{
		if (*flag == '-')
			ret.minus = 1;
		if (*flag == '0')
			ret.zero = 1;
		flag++;
	}
	return (ret);
}

t_f_info w1(t_f_info ret, char *flag)
{
	while (!(('1' <= *flag && *flag <= '9') || *flag == '*'))
	{
		if (*flag == '-')
			ret.minus = 1;
		if (*flag == '0')
			ret.zero = 1;
		flag++;
	}
	return (ret);
}
