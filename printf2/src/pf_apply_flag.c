/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:36:40 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 17:15:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*apply_flag(char *s_arg, t_info *info, char spec)
{
	t_cont	*flag;
	size_t	size;
	char	*cv_arg;
	char	*str;
	char	*s_arg_adr;

	if (!spec)
		return (0);
	s_arg_adr = s_arg;
	flag = (t_cont *)info->curr->content;
	str = 0;
	flag->width = (flag->width > ft_strlen(s_arg)) ? flag->width : 0;
	if (ft_strncmp(s_arg, "0", ft_strlen(s_arg)) == 0 &&
		flag->prec == 0 && flag->met_dot == 1 && !flag->width)
		return (ft_strdup(""));
	else if (ft_strncmp(s_arg, "0", ft_strlen(s_arg)) == 0 &&
			flag->prec == 0 && flag->met_dot == 1 && flag->width)
		str = ft_strdup("");
	if (s_arg[0] == '-')
	{
		flag->is_nega = 1;
		s_arg = s_arg + 1;
	}
	flag->prec = (flag->prec > ft_strlen(s_arg)) ? flag->prec : ft_strlen(s_arg);
	size = (flag->width > flag->prec) ? flag->width : flag->prec;
	if (size == ft_strlen(s_arg))
		return (ft_strdup(s_arg_adr));
	if (flag->is_nega && flag->width < flag->prec)
		size++;

	if (flag->met_dot)
		flag->zero = 0;

	size_t i;
	size_t j;
	i = 0;
	j = 0;
	if (!str)
	{
		if (flag->is_nega && !flag->zero)
		{
			str = (char *)malloc(flag->prec + 2);
			str[flag->prec + 1] = '\0';
			str[i++] = '-';
			while (i < flag->prec + 1 - ft_strlen(s_arg))
				str[i++] = '0';
			while (i < flag->prec + 1)
				str[i++] = s_arg[j++];
		}
		else if (flag->is_nega && flag->zero)
		{
			str = (char *)malloc(flag->width + 1);
			str[flag->width] = '\0';
			str[i++] = '-';
			while (i < flag->width - ft_strlen(s_arg))
				str[i++] = '0';
			while (i < flag->width)
				str[i++] = s_arg[j++];
		}
		else
		{
			str = (char *)malloc(flag->prec + 1);
			str[flag->prec] = '\0';
			while (i < flag->prec - ft_strlen(s_arg))
				str[i++] = '0';
			while (i < flag->prec)
				str[i++] = s_arg[j++];
		}
	}

	if (!(cv_arg = (char *)malloc(size + 1)))
		return (0);
	cv_arg[size] = '\0';
	i = 0;
	j = 0;
	if (flag->width > flag->prec) // && flag->prec > ft_strlen(s_arg))
	{
		if (flag->minus == 1)
		{
			while (i < ft_strlen(str))
				cv_arg[i++] = str[j++];
			while (i < size)
				cv_arg[i++] = ' ';
		}
		else if (flag->zero == 1 && flag->is_nega)
			while (i < size)
				cv_arg[i++] = str[j++];
		else if (flag->zero == 1)
		{
			while (i < size - ft_strlen(str))
				cv_arg[i++] = '0';
			while (i < size)
				cv_arg[i++] = str[j++];
		}
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
	return (cv_arg);
}
