/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:47:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 17:02:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	spec_switch(const char fmt, t_info *info)
{
	if (fmt == 'c' || fmt == '%')
		return (c_process(info, fmt));
	else if (fmt == 's')
		return (s_process(info));
	else if (fmt == 'p')
		return (p_process(info, fmt));
	else if (fmt == 'd' || fmt == 'i')
		return (di_process(info, fmt));
	else
		return (uxx_process(info, fmt));
}

static void	meet_percent(const char **fmt, int *count, t_info *info)
{
	(*fmt)++;
	// if (**fmt == '%')
	// {
	// 	ft_putchar_fd(**fmt, 1);
	// 	count++;
	// 	(*fmt)++;
	// }
	// else
	// {
		while (is_spec(**fmt) == 0)
			(*fmt)++;
		*count += spec_switch(**fmt, info);
		info->curr = info->curr->next;
	// }
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
