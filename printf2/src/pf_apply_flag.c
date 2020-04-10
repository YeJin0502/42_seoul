/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:36:40 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 12:36:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	find_size(t_cont *flag, char *s_arg, char **str)
{
	if (flag->minus || flag->met_dot)
		flag->zero = 0;
	flag->width = (flag->width >= (int)ft_strlen(s_arg)) ? flag->width : 0;
	if (ft_strncmp(s_arg, "0", ft_strlen(s_arg)) == 0 &&
		flag->prec == 0 && flag->met_dot == 1 && !flag->width)
		return (0);
	else if (ft_strncmp(s_arg, "0", ft_strlen(s_arg)) == 0 &&
			flag->prec == 0 && flag->met_dot == 1 && flag->width)
		*str = ft_strdup("");
	if (s_arg[0] == '-')
	{
		flag->is_nega = 1;
		s_arg = s_arg + 1;
	}
	flag->prec = (flag->prec >= (int)ft_strlen(s_arg)) ?
				flag->prec : (int)ft_strlen(s_arg);
	return ((flag->width > flag->prec) ? flag->width : flag->prec);
}

static void	make_str_nega(t_cont *flag, char **str, char *s_arg)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!flag->zero)
	{
		*str = (char *)malloc(flag->prec + 2);
		(*str)[flag->prec + 1] = '\0';
		(*str)[i++] = '-';
		while (i < (size_t)flag->prec + 2 - ft_strlen(s_arg))
			(*str)[i++] = '0';
		while (i < (size_t)flag->prec + 1)
			(*str)[i++] = s_arg[j++ + 1];
	}
	else
	{
		*str = (char *)malloc(flag->width + 1);
		(*str)[flag->width] = '\0';
		(*str)[i++] = '-';
		while (i < (size_t)flag->width + 1 - ft_strlen(s_arg))
			(*str)[i++] = '0';
		while (i < (size_t)flag->width)
			(*str)[i++] = s_arg[j++ + 1];
	}
}

static int	make_str(t_cont *flag, char **str, char *s_arg)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*str == 0)
	{
		if (flag->is_nega)
			make_str_nega(flag, str, s_arg);
		else
		{
			if (!(*str = (char *)malloc(flag->prec + 1)))
				return (1);
			(*str)[flag->prec] = '\0';
			while (i < (size_t)flag->prec - ft_strlen(s_arg))
				(*str)[i++] = '0';
			while (i < (size_t)flag->prec)
				(*str)[i++] = s_arg[j++];
		}
	}
	return (0);
}

static char	*free_and_ret(char **str, char *ret)
{
	free(*str);
	return (ret);
}

char		*apply_flag(char *s_arg, t_info *info)
{
	t_cont	*flag;
	char	*str;
	size_t	size;
	char	*cv_arg;

	flag = (t_cont *)info->curr->content;
	if (flag->width == 0 && flag->met_dot == 0)
		return (ft_strdup(s_arg));
	str = 0;
	size = find_size(flag, s_arg, &str);
	if (flag->is_nega && flag->width < flag->prec)
		size++;
	if (size == 0)
		return (ft_strdup(""));
	else if (size == ft_strlen(s_arg))
		return (ft_strdup(s_arg));
	if (make_str(flag, &str, s_arg) != 0)
		return (free_and_ret(&str, 0));
	if (!(cv_arg = (char *)malloc(size + 1)))
		return (free_and_ret(&str, 0));
	cv_arg[size] = '\0';
	make_cv_arg(cv_arg, size, flag, str);
	return (free_and_ret(&str, cv_arg));
}
