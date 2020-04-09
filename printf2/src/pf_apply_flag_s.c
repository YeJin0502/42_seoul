/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:21:41 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 13:21:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


static size_t select_size(t_cont *flag)
{
	// if (flag->width && flag->met_dot && flag->prec)
	// if (flag->width && flag->met_dot)
		return ((flag->width > flag->prec) ? flag->width : flag->prec); // 되나?
	// else if (flag->width && flag->met_dot && !flag->prec)
		// return (0);
	// else if (flag->width && !flag->met_dot)
		// return (flag->width);
	// else if (!flag->width && flag->met_dot)
		// return (flag->prec);
	// else
		// return (0); // 맞나?
}

char	*apply_flag_s(char *s_arg, t_info *info)
{
	t_cont	*flag;
	size_t	size;
	char	*cv_arg;

	flag = (t_cont *)info->curr->content;
	if (ft_strlen(s_arg) <= flag->prec || flag->met_dot == 0) // 맞나?
		// flag->prec = (size > ft_strlen(s_arg)) ?
		// ft_strlen(s_arg) : size; // 맞나?
		flag->prec = ft_strlen(s_arg);
	size = select_size(flag);
	// printf("%ld\n", size);
	// if (!flag->met_dot)
		// return (ft_strdup(s_arg));
	if (!(cv_arg = (char *)malloc(size + 1)))
		return (0);
	cv_arg[size] = '\0';
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	if (flag->minus)
	{
		while (i < flag->prec)
			cv_arg[i++] = s_arg[j++];
		while (i < size)
			cv_arg[i++] = ' ';
	}
	else
	{
		while (i < size - flag->prec)
			cv_arg[i++] = ' ';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
	return (cv_arg);
}
