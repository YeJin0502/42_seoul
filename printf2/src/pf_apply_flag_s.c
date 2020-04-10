/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:21:41 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 11:35:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	make_cv_arg_s(char *cv_arg, t_cont *flag, char *s_arg, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->minus)
	{
		while (i < (size_t)flag->prec)
			cv_arg[i++] = s_arg[j++];
		while (i < size)
			cv_arg[i++] = ' ';
	}
	else
	{
		while (i < size - (size_t)flag->prec)
			cv_arg[i++] = ' ';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
}

char		*apply_flag_s(char *s_arg, t_info *info)
{
	t_cont	*flag;
	size_t	size;
	char	*cv_arg;

	flag = (t_cont *)info->curr->content;
	if (ft_strlen(s_arg) <= (size_t)flag->prec || flag->met_dot == 0)
		flag->prec = ft_strlen(s_arg);
	size = (flag->width > flag->prec) ? flag->width : flag->prec;
	if (!(cv_arg = (char *)malloc(size + 1)))
		return (0);
	cv_arg[size] = '\0';
	make_cv_arg_s(cv_arg, flag, s_arg, size);
	return (cv_arg);
}
