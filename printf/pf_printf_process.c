/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:53:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 14:06:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

t_list	*count_spec(const char *fmt) // 이거 대폭 수정 필요!
{
	t_list *ret;
	t_check check;
	int	count;

	ret = ft_lstnew(0);
	ft_memset(&check, 0, sizeof(t_check)); // 맞나?
	count = 0;
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
			if (is_spec(*fmt) == 1 && check.wrong == 0 && count++)
				ft_lstadd_back(&ret, ft_lstnew((void *)fmt)); // 와 이게 한번에 된다고?
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
	else if (c == '*' && (*check).wc == 0)
		(*check).wc = 1;
	else if (c == '.' && (*check).dot == 0)
		(*check).dot = 1;
	else if (c == '-' && ((*check).num == 1	|| (*check).wc == 1 || (*check).dot == 1)
			&& (*check).wrong++)
		return (0);
	else if (c == '.' && (*check).dot == 1 && (*check).wrong++)
		return (0);
	else if (c == '*' && (*check).dot == 0 && (*check).wc == 1 && (*check).wrong++)
		return (0);
	else if (is_flag(c) == 0)
		return (0);
	return (1);
}

t_info	*make_info_and_free(const char *format, int count_s)
{
	t_info	*ret;
	char	*specs;
	char	**flags;
	if (!(specs = make_specs(format, count_s)))
		return (0);
	if (!(flags = make_flags(format, count_s)))
	{
		free(specs);
		return (0);
	}
	if (!(ret = make_info(specs, flags)))
	{
		free(specs);
		while (*flags)
			free(*(flags++));
		return (0);
	}
	free(specs);
	int i;
	i = 0;
	while (i < count_s)
	{
		free(flags[i]);
		i++;
	}
	free(flags);
	return (ret);
}

int	print_and_count(const char *format, int count_s, t_info *info, va_list ap)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
		{
			format = meet_specifier(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		}
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
}

const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap)
{
	format++;
	format = skip_flag(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + c_process(ap, info.flag, info.spec);
	else if (info.spec == 's')
		*ret = *ret + s_process(ap, info.flag, info.spec);
	else if (info.spec == 'p')
		*ret = *ret + p_process(ap, info.flag, info.spec);
	else if (info.spec == 'd' || info.spec == 'i')
		*ret = *ret + di_process(ap, info.flag, info.spec);
	else if (info.spec == 'u' || info.spec == 'x' || info.spec == 'X')
		*ret = *ret + uxX_process(ap, info.flag, info.spec);
	else
		return 0;
	return (format);
}
