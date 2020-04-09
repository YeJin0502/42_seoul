/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:04:56 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 11:04:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		free_and_ret(t_info *info, int ret)
{
	t_list *curr;
	t_list *next;

	curr = info->lst;
	while (curr)
	{
		next = curr->next;
		free((t_cont *)curr->content);
		free(curr);
		curr = next;
	}
	free(info);
	return (ret);
}

static t_info	*make_info(void)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	ft_memset(info, 0, sizeof(t_info));
	return (info);
}

int				ft_printf(const char *fmt, ...)
{
	t_info	*info;
	int		count;

	info = make_info();
	va_start(info->va, fmt);
	if (check_and_init(fmt, info) != 0)
		return (free_and_ret(info, 0));
	if (info->arg_num == 0)
		while (*fmt)
		{
			ft_putstr_fd((char *)fmt, 1);
			return (ft_strlen(fmt));
		}
	count = print_and_count(fmt, info);
	return (free_and_ret(info, count));
}
