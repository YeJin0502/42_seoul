/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_f_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:55:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 08:37:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>


int	make_precision(t_info *info)
{
	char	*tmp;
	int		flag_len;
	int		i;
	int		ret_size;
	int		ret; // 변수 많을땐 구조체 이용해서 줄수 줄일 수 있을..듯
	
	if ((*info).flag == NULL || ft_strchr((*info).flag, '.') == NULL)
		return (0);
	flag_len = ft_strlen((*info).flag);
	i = 0;
	while ((*info).flag[flag_len - i - 1] != '.' && (*info).flag[flag_len - i - 1])
		i++;
	if (i == 0)
		return (0);
	else if (i == 1 && (*info).flag[flag_len - 1] == '*' && (*info).prec_star++) // 이 조건 약간 수정될수도
		return (0);
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	ret_size = i;
	while (--i >= 0) // 배열 안만들고 바로 숫자로 계산할 수도 있을듯?
		tmp[ret_size - i - 1] = (*info).flag[flag_len - i - 1];
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

int	make_width(t_info *info)
{
	int		i;
	int		start;
	int		count;
	char	*tmp;
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
		return (0); // 더 포함시켜서 함수 줄이면 될듯..
	if (!(tmp = (char *)malloc(count + 1)))
		return (0);
	tmp[count] = '\0';
	i = start - 1;
	while ((*info).flag[++i] != '.' && (*info).flag[i]) // 이거도 배열 안만들고 바로 숫자 셀수있는지 확인
		tmp[i - start] = (*info).flag[i];
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

t_f_info	make_f_info(t_info info, va_list ap) //, int *is_wc_width, int *is_wc_precision)
{
	t_f_info	ret;

	ft_memset(&ret, 0, sizeof(t_f_info)); // 이거 맞나?
	ret.width = make_width(&info);
	ret.precision = make_precision(&info);
	if (info.width_star == 1)
		ret.width = va_arg(ap, int);
	if (info.prec_star == 1)
		ret.precision = va_arg(ap, int);
	if (ret.width < 0 && ++ret.minus && ++ret.width_nega)
		ret.width = ret.width * -1;
	if (ret.precision < 0 && ++ret.minus && ++ret.prec_nega) // 여기에 minus++은 생각해봐야.
		ret.precision = ret.precision * -1;
	if (ret.width == 0 && ret.precision == 0)
		ret = w0_p0(ret, info.flag);
	else if (ret.width == 0 && ret.precision != 0)
		ret= w0_p1(ret, info.flag);
	else if (ret.width != 0)
		ret = w1(ret, info.flag);
	return (ret);
}
