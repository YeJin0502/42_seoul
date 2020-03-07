/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/08 03:26:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	c_process(va_list ap, t_info info)
{
	int			is_width_wc;
	int			is_precision_wc;
	char		arg;
	char		*c_arg;
	int			c_arg_size;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = (char)va_arg(ap, int);
	if (is_width_wc == 1 || is_precision_wc == 1)
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	c_arg = (char *)malloc(2);
	c_arg[0] = arg;
	c_arg[1] = '\0';
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info);
	if (c_arg == NULL) // 아마 다 추가하고, free도 해야할 듯.
		return 0;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}
///


int	s_process(va_list ap, t_info info)
{
	int			is_width_wc;
	int			is_precision_wc;
	char		*arg;
	char		*c_arg;
	int			c_arg_size;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = va_arg(ap, char *);
	if (arg == 0)
		return (0);
	if (is_width_wc == 1 || is_precision_wc == 1)
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	c_arg = ft_strdup(arg);
	// if (ft_isascii((int)c_arg) == 1)
	// 	return (0);
	if (*(info.flag) != '\0')
		c_arg = apply_flag_s(c_arg, info.f_info, info);
	if (c_arg == 0)
		return (0);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	p_process(va_list ap, t_info info)
{
	void	*arg;
	char	*c_arg_tmp;
	char	*c_arg;
	int		c_arg_size;
	int is_width_wc;
	int is_precision_wc;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = va_arg(ap, void *);
	if (is_width_wc == 1 || is_precision_wc == 1)
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	c_arg_tmp = dec_to_hex((unsigned int)arg, info.spec);
	c_arg = ft_strjoin("0x", c_arg_tmp);
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg_tmp);
	free(c_arg);
	return (c_arg_size);
}

int	di_process(va_list ap, t_info info)
{
	int		arg;
	char	*c_arg;
	int		c_arg_size;
	int is_width_wc;
	int is_precision_wc;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = va_arg(ap, int);
	if (is_width_wc == 1 || is_precision_wc == 1)
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	c_arg = ft_itoa(arg);
	if (*info.flag != '\0') // 이걸로 다 바꿔야할듯?
		c_arg = apply_flag(c_arg, info.f_info);	
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
	int is_width_wc;
	int is_precision_wc;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = va_arg(ap, unsigned int);
	if (is_width_wc == 1 || is_precision_wc == 1)
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	if (info.spec == 'u')
		c_arg = ft_itoa_u(arg);
	else
		c_arg = dec_to_hex(arg, info.spec);
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}
