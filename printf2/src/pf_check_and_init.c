/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:48:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/08 20:48:58 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int is_spec(char mover)
{
	char *spec;

	spec = "cspdiuxX";
	while (*spec)
	{
		if (mover == *spec)
			return (1);
		spec++;
	}
	return (0);
}

static int ci_process(char **mover, t_info *info) // malloc 되어있으면 값 그냥 줘도 되는거 헷갈림.
{
	t_cont *cont;

	cont = (t_cont *)malloc(sizeof(t_cont));
	ft_memset(cont, 0, sizeof(t_cont));
	while (**mover)
	{
		if (is_spec(**mover) == 1)
		{
			info->arg_num++;
			cont->spec = **mover;
			ft_lstadd_back(&(info->flag), ft_lstnew(cont));
			return (0);
		}
		else if (**mover == '-' && cont->minus == 0)
			cont->minus = 1;
		else if (**mover == '0' && cont->zero == 0)
			cont->zero = 1;
		else if (**mover == '.' && cont->met_dot == 0)
			cont->met_dot = 1;
		else if ('1' <= **mover && **mover <= '9' && cont->met_dot == 0)
		{
			cont->width = ft_atoi(*mover);
			while (ft_isdigit(**mover) != 0 && **mover)
			{
				// printf("(%c)\n", **mover);
				(*mover)++;
			}
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
		(*mover)++;
	}
	return (2);
}

int check_and_init(const char *fmt, t_info *info)
{
	char *mover;

	mover = (char *)fmt;
	// info->flag = (t_flag *)malloc(sizeof(t_flag));
	// ft_memset(info->flag, 0, sizeof(t_flag));
	while (*mover)
	{
		if (*mover == '%') // %-0% 이런건 어떻게 되려나?
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
