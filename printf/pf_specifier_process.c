/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 20:52:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	c_process(va_list ap, char *flag, char spec)
{
	char	arg;
	char	*c_arg;
	int		c_arg_size;
	t_f_info f_info;
	int		is_wc_width;
	int		is_wc_precision;

	is_wc_width = 0;
	is_wc_precision = 0;
	f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	arg = (char)va_arg(ap, int);
	if (is_wc_width == 1 || is_wc_precision == 1)
		f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	c_arg = (char *)malloc(2);
	c_arg[0] = arg;
	c_arg[1] = '\0';
	if (flag != NULL)
		c_arg = apply_flag(c_arg, spec, f_info);
	if (c_arg == NULL)
		return 0;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	s_process(va_list ap, char *flag, char spec)
{
	char	*arg;
	char	*c_arg;
	int		c_arg_size;
	t_f_info f_info;
	int is_wc_width;
	int is_wc_precision;

	is_wc_width = 0;
	is_wc_precision = 0;
	f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	arg = va_arg(ap, char *);
	if (is_wc_width == 1 || is_wc_precision == 1)
		f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	if (flag != NULL)
		c_arg = apply_flag(arg, spec, f_info);
	else
		c_arg = arg;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	return (c_arg_size);
}

int	p_process(va_list ap, char *flag, char spec)
{
	void	*arg;
	char	*c_arg_tmp;
	char	*c_arg;
	int		c_arg_size;
	t_f_info f_info;
	int is_wc_width;
	int is_wc_precision;

	is_wc_width = 0;
	is_wc_precision = 0;
	f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	arg = va_arg(ap, void *);
	if (is_wc_width == 1 || is_wc_precision == 1)
		f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	c_arg_tmp = dec_to_hex((unsigned int)arg, spec);
	c_arg = ft_strjoin("0x", c_arg_tmp);
	if (*flag != '\0') // 왜 얘만 이렇게 검사하게될까..? 그걸 모르겠네. 다른애들은 그냥 flag != NULL 검사했는데.
		c_arg = apply_flag(c_arg, spec, f_info);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	di_process(va_list ap, char *flag, char spec)
{
	int		arg;
	char	*c_arg;
	int		c_arg_size;
	t_f_info f_info;
	int is_wc_width;
	int is_wc_precision;

	is_wc_width = 0;
	is_wc_precision = 0;
	f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	arg = va_arg(ap, int);
	if (is_wc_width == 1 || is_wc_precision == 1)
		f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	c_arg = ft_itoa(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, spec, f_info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	uxX_process(va_list ap, char *flag, char spec)
{
	unsigned int	arg;
	char			*c_arg;
	int				c_arg_size;
	t_f_info f_info;
	int is_wc_width;
	int is_wc_precision;

	is_wc_width = 0;
	is_wc_precision = 0;
	f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	arg = va_arg(ap, unsigned int);
	if (is_wc_width == 1 || is_wc_precision == 1)
		f_info = make_f_info(flag, ap, &is_wc_width, &is_wc_precision);
	if (spec == 'u')
		c_arg = ft_itoa_u(arg);
	else
		c_arg = dec_to_hex(arg, spec);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, spec, f_info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}
