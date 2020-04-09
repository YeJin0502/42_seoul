/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:36:40 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/09 17:14:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	minus_or_zero(char *s_arg, char *cv_arg, t_cont *flag, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->minus == 1)
	{
		while (i < ft_strlen(s_arg))
			cv_arg[i++] = s_arg[j++];
		while (i < size)
			cv_arg[i++] = ' ';
	}
	else
	{
		while (i < size - ft_strlen(s_arg))
			cv_arg[i++] = '0';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
}

void	width_or_prec(char *s_arg, char *cv_arg, t_cont *flag, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->prec)
	{
		while (i < size - flag->prec)
			cv_arg[i++] = ' ';
		while (i < size - ft_strlen(s_arg))
			cv_arg[i++] = '0';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
	else
	{
		while (i < size - ft_strlen(s_arg))
			cv_arg[i++] = ' ';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
}

char	*apply_flag(char *s_arg, t_info *info)
{
	t_cont	*flag;
	size_t	size;
	char	*cv_arg;

	flag = (t_cont *)info->curr->content;
	flag->width = (ft_strlen(s_arg) < flag->width) ? flag->width : 0;
	flag->prec = (ft_strlen(s_arg) < flag->prec) ? flag->prec : 0;
	if (!(size = (flag->width > flag->prec) ? flag->width : flag->prec))
		return (ft_strdup(s_arg));
	else if (flag->prec)
	{
		flag->minus = 0;
		flag->zero = 0;
	}
	if (!(cv_arg = (char *)malloc(size + 1)))
		return (0);
	cv_arg[size] = '\0';
	if (flag->minus || flag->zero)
		minus_or_zero(s_arg, cv_arg, flag, size);
	else
		width_or_prec(s_arg, cv_arg, flag, size);
	return (cv_arg);
}

char	*apply_flag_s(char *s_arg, t_info *info)
{
	t_cont	*flag;
	char	*cv_arg;

	flag = (t_cont *)info->lst->content;
	if (!flag)
		return (0);
	cv_arg = ft_strdup(s_arg);
	return (cv_arg);
}
