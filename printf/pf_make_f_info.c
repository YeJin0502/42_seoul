/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 13:21:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_precision(t_info info, va_list ap)
{
	int	flag_len;
	int	prec_len;
	int	ret;

	if (info.flag == 0 || is_contain(info.flag, '.') == 0)
		return (0);
	flag_len = ft_strlen(info.flag);
	prec_len = 0;
	while (info.flag[flag_len - prec_len - 1] != '.')
		prec_len++;
	if (prec_len == 0)
		return (0);
	else if (prec_len == 1 && info.flag[flag_len - 1] == '*')
		return (va_arg(ap, int));
	ret = 0;
	while (--prec_len >= 0)
		ret = ret * 10 + (info.flag[flag_len - prec_len - 1] - '0');
	return (ret);
}

static int	make_width(t_info info, va_list ap)
{
	int	width_len;
	int	i;
	int	ret;

	if (info.flag == 0)
		return (0);
	width_len = 0;
	while (*info.flag == '0' || *info.flag == '-')
		info.flag++;
	while (*(info.flag + width_len) != '.' && *(info.flag + width_len))
		width_len++;
	if (width_len == 0)
		return (0);
	else if (width_len == 1 && info.flag[0] == '*')
		return (va_arg(ap, int));
	i = 0;
	ret = 0;
	while (i < width_len)
		ret = ret * 10 + (info.flag[i++] - '0');
	return (ret);
}

t_f_info	make_f_info(t_info info, va_list ap)
{
	t_f_info	f_info;

	ft_memset(&f_info, 0, sizeof(t_f_info));
	f_info.width = make_width(info, ap);
	f_info.precision = make_precision(info, ap);
	if (f_info.width < 0 && ++f_info.minus)
		f_info.width = f_info.width * -1;
	if (f_info.precision < 0 && ++f_info.minus && ++f_info.prec_nega)
		f_info.precision = 0;
	while (*info.flag == '0' || *info.flag == '-')
	{
		if (*info.flag == '0')
			f_info.zero = 1;
		else if (*info.flag == '-')
			f_info.minus = 1;
		info.flag++;
	}
	f_info.zero = (f_info.precision != 0 || f_info.minus == 1) ? 0 : f_info.zero;
	return (f_info);
}
