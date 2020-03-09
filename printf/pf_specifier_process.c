/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 07:08:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	c_process(va_list ap, t_info info)
{
	char	arg;
	char	*c_arg;
	char	*c_arg_ret;
	int		ret_size;

	info.f_info = make_f_info(info, ap);
	arg = (char)va_arg(ap, int);
	c_arg = (char *)malloc(2);
	if (arg != 0)
		c_arg[0] = arg; // 457~459은 어떻게하냐
	c_arg[1] = '\0';
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}

int	s_process(va_list ap, t_info info)
{
	char	*arg;
	char	*c_arg;
	char	*c_arg_ret;
	int		ret_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, char *);
	if (arg == 0)
		c_arg = ft_strdup("(null)");
	else if (arg[0] == '\0')
		c_arg = ft_strdup("");
	else
		c_arg = ft_strdup(arg);
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag_s(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}

int	p_process(va_list ap, t_info info)
{
	void	*arg;
	char	*tmp;
	char	*c_arg;
	char	*c_arg_ret;
	int		ret_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, void *);
	if (arg == 0)
		c_arg = ft_strdup("(nil)");
	else
	{
		tmp = dec_to_hex((size_t)arg, info.spec);
		c_arg = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}

int	di_process(va_list ap, t_info info)
{
	int		arg;
	char	*c_arg;
	char	*c_arg_ret;
	int		ret_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}

int	uxX_process(va_list ap, t_info info)
{
	unsigned int	arg;
	char			*c_arg;
	char			*c_arg_ret;
	int				ret_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, unsigned int);
	if (arg == 0)
		c_arg = ft_strdup("0");
	else if (info.spec == 'u')
		c_arg = ft_itoa_u(arg);
	else
		c_arg = dec_to_hex((size_t)arg, info.spec);
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	ret_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, ret_size);
	free(c_arg);
	free(c_arg_ret);
	return (ret_size);
}
