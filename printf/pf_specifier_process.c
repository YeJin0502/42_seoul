/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 02:54:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	c_process(va_list ap, t_info info)
{
	char		arg;
	char		*c_arg;
	int			c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = (char)va_arg(ap, int);
	c_arg = (char *)malloc(2);
	if (arg != 0)
		c_arg[0] = arg; // 457~459은 어떻게하냐
	c_arg[1] = '\0';
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info, info);
	if (c_arg == 0)
		return (0);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	s_process(va_list ap, t_info info)
{
	char		*arg;
	char		*c_arg;
	char		*c_arg_ret;
	int			c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, char *);
	if (arg == 0)
		c_arg = ft_strdup("(null)");
	else if (arg[0] == '\0')
		c_arg = ft_strdup("\0");
	else
		c_arg = ft_strdup(arg);
	if (*(info.flag) != '\0')
		c_arg_ret = apply_flag_s(c_arg, info.f_info, info);
	else
		c_arg_ret = ft_strdup(c_arg);
	if (c_arg_ret == 0)
		return (0);
	c_arg_size = (int)ft_strlen(c_arg_ret);
	write(1, c_arg_ret, c_arg_size);
	free(c_arg);
	free(c_arg_ret);
	return (c_arg_size);
}

int	p_process(va_list ap, t_info info)
{
	void	*arg;
	char	*c_arg;
	int		c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, void *);
	if (arg == 0)
		c_arg = ft_strdup("(nil)");
	else
		c_arg = ft_strjoin("0x", dec_to_hex((size_t)arg, info.spec));
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info, info);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	di_process(va_list ap, t_info info)
{
	int		arg;
	char	*c_arg;
	int		c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info, info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	uxX_process(va_list ap, t_info info)
{
	unsigned int	arg;
	char			*c_arg;
	int				c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, unsigned int);
	if (arg == 0)
		c_arg = ft_strdup("0");
	else if (info.spec == 'u')
		c_arg = ft_itoa_u(arg);
	else
		c_arg = dec_to_hex((size_t)arg, info.spec);
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info, info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}
