/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_spec_adr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:47:47 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 13:29:14 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(const char c, t_check *check)
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
	return (1); // 이거보다 더 많을거같은데... 경우의 수... 나중에 정리하자
}

t_list	*find_spec_adr(const char *fmt)
{
	t_list	*spec_adr;
	t_check	check;

	spec_adr = 0;
	ft_memset(&check, 0, sizeof(t_check));
	while (*fmt)
	{
		if (*(fmt - 1) != '%' && *fmt == '%' && *(fmt + 1) != '%' && *(fmt + 1) && ++fmt)
		{
			while (*fmt && (is_spec(*fmt) == 0))
			{
				if (is_valid(*fmt, &check) == 0)
					break;
				fmt++;
			}
			if (is_spec(*fmt) == 1 && check.wrong == 0)
				ft_lstadd_back(&spec_adr, ft_lstnew((void *)fmt));
			ft_memset(&check, 0, sizeof(t_check));
		}
		fmt++; // 이거도 줄이고 싶었는데... 이건 잘 안되네.
	}
	return (spec_adr);
}
