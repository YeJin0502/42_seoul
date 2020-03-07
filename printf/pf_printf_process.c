/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/08 05:29:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

t_list	*count_spec(const char *fmt)
{
	t_list *ret;
	t_check check;
	int	count;

	ft_memset(&check, 0, sizeof(t_check));
	count = 0;
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%' && *(fmt + 1))
		{
			fmt++;
			while (*fmt && (is_spec(*fmt) == 0)) // flag 유효성 검사
			{
				if (is_valid(*fmt, &check) == 0)
					break;
				fmt++;
			}
			if (is_spec(*fmt) == 1 && check.wrong == 0)
			{
				ft_lstadd_back(&ret, ft_lstnew((void *)fmt));
				count++;
			}
		ft_memset(&check, 0, sizeof(t_check));
		}
		fmt++;
	}
	return (ret);
}

int is_valid(const char c, t_check *check)
{
	if ('1' <= c && c <= '9' && (*check).num == 0)
		(*check).num = 1;
	else if (c == '*' && (*check).dot == 0 && (*check).w_wc == 0)
		(*check).w_wc = 1;
	else if (c == '.' && (*check).dot == 0)
		(*check).dot = 1;
	else if (c == '*' && (*check).dot == 1 && (*check).p_wc == 0)
		(*check).p_wc = 1;
	else if ('1' <= c && c <= '9' && (*check).w_wc == 1 && (*check).wrong++)
		return (0);
	else if ('1' <= c && c <= '9' && (*check).p_wc == 1 && (*check).wrong++)
		return (0);
	else if (c == '-' && ((*check).num == 1	|| (*check).w_wc == 1 || (*check).dot == 1
			|| (*check).p_wc == 1) && (*check).wrong++)
		return (0);
	else if (c == '.' && (*check).dot == 1 && (*check).wrong++)
		return (0);
	else if (c == '*' && ((*check).num == 1 || (*check).w_wc == 1 || (*check).p_wc == 1)
			&& (*check).wrong++)
		return (0);
	else if (is_flag(c) == 0)
		return (0);
	return (1);
} // 계속 여기에 추가될듯... 길어지면 위에 체크로 바꾸는거 분리하면 될듯.

int	print_and_count(const char *format, int count_s, t_info *info, va_list ap)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s) // 아마 %% 때문에 수정해야 할듯
			format = meet_specifier(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		else
		{
			write(1, format, 1);
			ret++;
		}
		if (format == 0)
			return (-1);
		format++;
	}
	return (ret);
}

static const char	*skip_flag(const char *format, char *flag)
{
	while (*format == *flag)
	{
		format++;
		flag++;
	}
	return (format);
} // 이거 libft에 비슷한 함수 있지 않나?

const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap)
{
	format++;
	format = skip_flag(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + c_process(ap, info);
	else if (info.spec == 's')
		*ret = *ret + s_process(ap, info);
	else if (info.spec == 'p')
		*ret = *ret + p_process(ap, info);
	else if (info.spec == 'd' || info.spec == 'i')
		*ret = *ret + di_process(ap, info);
	else if (info.spec == 'u' || info.spec == 'x' || info.spec == 'X')
		*ret = *ret + uxX_process(ap, info);
	else
		return 0;
	return (format);
}
