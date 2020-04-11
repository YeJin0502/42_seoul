/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:34:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 13:30:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	c_process(t_info *info, char spec)
{
	char	arg;
	char	*s_arg;
	char	*cv_arg;
	int		count;

	if (spec == 'c')
		arg = (char)va_arg(info->va, int);
	else
		arg = '%';
	s_arg = (char *)malloc(2);
	if (arg == 0)
		s_arg[0] = 'M';
	else
		s_arg[0] = arg;
	s_arg[1] = '\0';
	cv_arg = apply_flag(s_arg, info);
	free(s_arg);
	count = ft_strlen(cv_arg);
	if (arg == 0)
		putstr_c(cv_arg, count);
	else
		ft_putstr_fd(cv_arg, 1);
	free(cv_arg);
	return (count);
}

int	s_process(t_info *info)
{
	char	*arg;
	char	*s_arg;
	char	*cv_arg;
	int		count;
	t_cont	*flag;

	flag = ((t_cont *)(info->curr->content));
	if (flag->zero == 1)
		return (-1);
	arg = va_arg(info->va, char *);
	if (!arg)
		s_arg = ft_strdup("(null)");
	else
		s_arg = ft_strdup(arg);
	cv_arg = apply_flag_s(s_arg, info);
	free(s_arg);
	count = ft_strlen(cv_arg);
	ft_putstr_fd(cv_arg, 1);
	free(cv_arg);
	return (count);
}

int	p_process(t_info *info)
{
	long long	arg;
	char		*s_arg_tmp;
	char		*s_arg;
	char		*cv_arg;
	int			count;

	arg = va_arg(info->va, long long);
	if (!arg && ((t_cont *)(info->curr->content))->met_dot == 1)
		s_arg_tmp = ft_strdup("");
	else if (!arg)
		s_arg_tmp = ft_strdup("0");
	else
		s_arg_tmp = dec_to_hex(arg, 'x');
	s_arg = ft_strjoin("0x", s_arg_tmp);
	cv_arg = apply_flag(s_arg, info);
	free(s_arg_tmp);
	free(s_arg);
	count = ft_strlen(cv_arg);
	ft_putstr_fd(cv_arg, 1);
	free(cv_arg);
	return (count);
}

int	di_process(t_info *info)
{
	int		arg;
	char	*s_arg;
	char	*cv_arg;
	int		count;

	arg = va_arg(info->va, int);
	s_arg = ft_itoa(arg);
	cv_arg = apply_flag(s_arg, info);
	free(s_arg);
	count = ft_strlen(cv_arg);
	ft_putstr_fd(cv_arg, 1);
	free(cv_arg);
	return (count);
}

int	uxx_process(t_info *info, char spec)
{
	unsigned int	arg;
	char			*s_arg;
	char			*cv_arg;
	int				count;

	arg = va_arg(info->va, unsigned int);
	if (spec == 'u')
		s_arg = pf_itoa_u(arg);
	else if (spec != 'u' && arg == 0)
		s_arg = ft_strdup("0");
	else if (spec == 'x')
		s_arg = dec_to_hex(arg, 'x');
	else
		s_arg = dec_to_hex(arg, 'X');
	cv_arg = apply_flag(s_arg, info);
	free(s_arg);
	count = ft_strlen(cv_arg);
	ft_putstr_fd(cv_arg, 1);
	free(cv_arg);
	return (count);
}
