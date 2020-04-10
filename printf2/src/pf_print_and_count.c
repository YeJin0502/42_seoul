/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:47:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 11:54:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	meet_percent(const char **fmt, int *count, t_info *info)
{
	(*fmt)++;
	while (is_spec(**fmt) == 0)
		(*fmt)++;
	if (**fmt == 'c' || **fmt == '%')
		*count += c_process(info, **fmt);
	else if (**fmt == 's')
		*count += s_process(info);
	else if (**fmt == 'p')
		*count += p_process(info);
	else if (**fmt == 'd' || **fmt == 'i')
		*count += di_process(info);
	else
		*count += uxx_process(info, **fmt);
	info->curr = info->curr->next;
}

int			print_and_count(const char *fmt, t_info *info)
{
	int count;

	count = 0;
	info->curr = info->lst;
	while (*fmt)
	{
		if (*fmt == '%')
			meet_percent(&fmt, &count, info);
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	return (count);
}
