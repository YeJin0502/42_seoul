/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:48:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/09 17:05:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ci_sub1(t_cont *flag, t_info *info)
{
	info->arg_num++;
	ft_lstadd_back(&(info->lst), ft_lstnew(flag));
	return (0);
}

static int	ci_sub2(char **mover, t_cont *cont, t_info *info)
{
	if ('1' <= **mover && **mover <= '9' && cont->met_dot == 0)
	{
		cont->width = ft_atoi(*mover);
		while (ft_isdigit(**mover) != 0 && **mover)
			(*mover)++;
		(*mover)--;
	}
	else if ('1' <= **mover && **mover <= '9' && cont->met_dot == 1)
	{
		cont->prec = ft_atoi(*mover);
		while (ft_isdigit(**mover) != 0 && **mover)
			(*mover)++;
		(*mover)--;
	}
	else if (**mover == '*' && cont->met_dot == 0 && cont->width == 0)
		cont->width = va_arg(info->va, int);
	else if (**mover == '*' && cont->met_dot == 1 && cont->prec == 0)
		cont->prec = va_arg(info->va, int);
	else
		return (1);
	return (0);
}

static int	ci_sub3(char **mover, t_cont *cont)
{
	if (**mover == '-' && cont->minus == 0 && cont->zero == 0)
		cont->minus = 1;
	else if (**mover == '0' && cont->zero == 0 && cont->minus == 0)
		cont->zero = 1;
	else if (**mover == '.' && cont->met_dot == 0)
		cont->met_dot = 1;
	else
		return (1);
	return (0);
}

static int	ci_process(char **mover, t_info *info)
{
	t_cont *flag;

	flag = (t_cont *)malloc(sizeof(t_cont));
	ft_memset(flag, 0, sizeof(t_cont));
	while (**mover && **mover != '%')
	{
		if (is_spec(**mover) == 1)
			return (ci_sub1(flag, info));
		else if (**mover == '-' || **mover == '0' || **mover == '.')
		{
			if (ci_sub3(mover, flag) == 1)
				return (1);
		}
		else if (('1' <= **mover && **mover <= '9') || **mover == '*')
		{
			if (ci_sub2(mover, flag, info) == 1)
				return (1);
		}
		else
			return (1);
		(*mover)++;
	}
	return (2);
}

int			check_and_init(const char *fmt, t_info *info)
{
	char *mover;

	mover = (char *)fmt;
	while (*mover)
	{
		if (*mover == '%')
		{
			mover++;
			if (*mover != '%')
				if (ci_process(&mover, info) != 0)
					return (1);
		}
		mover++;
	}
	return (0);
}
