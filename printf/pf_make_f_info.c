/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 09:16:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_precision(t_info info, va_list ap)
{
	int		flag_len;
	int		prec_len;
	int		ret;
	
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
	int		width_len;
	int		i;
	int		ret;

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
	ret = 0;
	i = 0;
	while (i < width_len)
		ret = ret * 10 + (info.flag[i++] - '0');
	return (ret);
}

t_f_info	make_f_info(t_info info, va_list ap)
{
	t_f_info	ret;

	ft_memset(&ret, 0, sizeof(t_f_info));
	ret.width = make_width(info, ap);
	ret.precision = make_precision(info, ap);
	if (ret.width < 0 && ++ret.minus && ++ret.width_nega)
		ret.width = ret.width * -1;
	if (ret.precision < 0 && ++ret.minus && ++ret.prec_nega) // 여기에 minus++은 생각해봐야.
		ret.precision = 0;
	while (*info.flag == '0' || *info.flag == '-')
	{
		if (*info.flag == '0')
			ret.zero = 1;
		else if (*info.flag == '-')
			ret.minus = 1;
		info.flag++;
	}
	ret.zero = (ret.precision != 0 || ret.minus == 1) ? 0 : ret.zero;
	return (ret);
}
