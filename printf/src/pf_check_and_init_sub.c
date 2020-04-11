/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_and_init_sub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:10:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 13:53:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ci_sub1(char spec, t_cont *flag, t_info *info)
{
	if (spec == 's' && flag->zero == 1)
		return (3);
	info->arg_num++;
	ft_lstadd_back(&(info->lst), ft_lstnew(flag));
	return (0);
}

static int	ci_sub2(char **mover, t_cont *cont)
{
	if (**mover == '-' && cont->minus == 0)
		cont->minus = 1;
	else if (**mover == '0' && cont->zero == 0 && cont->met_dot == 0)
		cont->zero = 1;
	else if (**mover == '0' && cont->met_dot == 1)
		cont->prec = ft_atoi(*mover);
	else if (**mover == '.' && cont->met_dot == 0)
		cont->met_dot = 1;
	else
		return (1);
	return (0);
}

static int	ci_sub3(char **mover, t_cont *cont)
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
	else
		return (1);
	return (0);
}

static int	ci_sub4(t_cont *cont, t_info *info)
{
	if (cont->met_dot == 0 && cont->width == 0)
	{
		cont->width = va_arg(info->va, int);
		if (cont->width < 0)
		{
			cont->width *= -1;
			cont->minus = 1;
		}
	}
	else if (cont->met_dot == 1 && cont->prec == 0)
	{
		cont->prec = va_arg(info->va, int);
		if (cont->prec < 0)
		{
			cont->prec = 0;
			cont->met_dot = 0;
		}
	}
	else
		return (1);
	return (0);
}

int			ci_sub(char **mover, t_cont *flag, t_info *info)
{
	while (**mover)
	{
		if (is_spec(**mover) == 1)
			return (ci_sub1(**mover, flag, info));
		else if (**mover == '-' || **mover == '0' || **mover == '.')
		{
			if (ci_sub2(mover, flag) == 1)
				return (1);
		}
		else if ('1' <= **mover && **mover <= '9')
		{
			if (ci_sub3(mover, flag) == 1)
				return (1);
		}
		else if (**mover == '*')
		{
			if (ci_sub4(flag, info) == 1)
				return (1);
		}
		else
			return (1);
		(*mover)++;
	}
	return (2);
}
