/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:01:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 11:27:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	make_cv_arg_minus(char *cv_arg, size_t size, char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < ft_strlen(str))
		cv_arg[i++] = str[j++];
	while (i < size)
		cv_arg[i++] = ' ';
}

static void	make_cv_arg_zero(char *cv_arg, size_t size, t_cont *flag, char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->is_nega)
		while (i < size)
			cv_arg[i++] = str[j++];
	else
	{
		while (i < size - ft_strlen(str))
			cv_arg[i++] = '0';
		while (i < size)
			cv_arg[i++] = str[j++];
	}
}

void		make_cv_arg(char *cv_arg, size_t size, t_cont *flag, char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->width > flag->prec)
	{
		if (flag->minus == 1)
			make_cv_arg_minus(cv_arg, size, str);
		else if (flag->zero == 1)
			make_cv_arg_zero(cv_arg, size, flag, str);
		else
		{
			while (i < size - ft_strlen(str))
				cv_arg[i++] = ' ';
			while (i < size)
				cv_arg[i++] = str[j++];
		}
	}
	else
		while (i < size)
			cv_arg[i++] = str[j++];
}
