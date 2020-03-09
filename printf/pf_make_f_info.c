/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 08:08:21 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_precision(t_info *info)
{
	int		flag_len;
	int		i;
	int		ret;
	
	if ((*info).flag == NULL || ft_strchr((*info).flag, '.') == NULL)
		return (0);
	flag_len = ft_strlen((*info).flag);
	i = 0;
	while ((*info).flag[flag_len - i - 1] != '.' && (*info).flag[flag_len - i - 1])
		i++;
	if (i == 0)
		return (0);
	else if (i == 1 && (*info).flag[flag_len - 1] == '*' && (*info).prec_star++)
		return (0);
	ret = 0;
	while (--i >= 0)
		ret = ret * 10 + ((*info).flag[flag_len - i - 1] - '0');
	return (ret);
}

static int	make_width(t_info *info) // 이것도 위처럼 수정 여지 있지 않나? 대폭 줄일수 있을듯.
{
	int		i;
	int		start;
	int		count;
	int		ret;

	if ((*info).flag == NULL)
		return (0);
	i = 0;
	start = -1;
	count = width_digit_count((*info).flag, &i, &start);
	(*info).width_star = 0;
	if (count == 0)
		return (0);
	else if (count == -1 && (*info).width_star++)
		return (0);
	i = start - 1;
	ret = 0;
	while ((*info).flag[++i] != '.' && (*info).flag[i])
		ret = ret * 10 + ((*info).flag[i] - '0');
	return (ret);
}

t_f_info	make_f_info(t_info info, va_list ap)
{
	t_f_info	ret;

	ft_memset(&ret, 0, sizeof(t_f_info));
	ret.width = make_width(&info);
	ret.precision = make_precision(&info);
	ret.width = (info.width_star == 1) ? va_arg(ap, int) : ret.width;
	ret.precision = (info.prec_star == 1) ? va_arg(ap, int) : ret.precision;
	if (ret.width < 0 && ++ret.minus && ++ret.width_nega)
		ret.width = ret.width * -1;
	if (ret.precision < 0 && ++ret.minus && ++ret.prec_nega) // 여기에 minus++은 생각해봐야.
		ret.precision = 0;
	if (ret.width == 0 && ret.precision == 0)
		ret = w0_p0(ret, info.flag);
	else if (ret.width == 0 && ret.precision != 0)
		ret= w0_p1(ret, info.flag);
	else if (ret.width != 0)
		ret = w1(ret, info.flag);
	ret.zero = (ret.precision != 0 || ret.minus == 1) ? 0 : ret.zero;
	return (ret);
}
