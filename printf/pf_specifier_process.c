/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/08 22:35:21 by gmoon            ###   ########.fr       */
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
		arg = "(null)"; // null 개념 약해서 문자열로 줘버리는거 오반데..ㅠㅠ 일단은..나중에고치자
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
	char	*c_arg;
	int		c_arg_size;
	int is_width_wc;
	int is_precision_wc;

	is_width_wc = 0;
	is_precision_wc = 0;
	info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	arg = va_arg(ap, void *);
	if (is_width_wc == 1 || is_precision_wc == 1) // 이 지저분한 부분은... 나중에 고칠수 있지 않을까?
		info.f_info = make_f_info(info, ap, &is_width_wc, &is_precision_wc);
	if (arg == 0)
		c_arg = ft_strdup("(nil)");
	else
		c_arg = ft_strjoin("0x", dec_to_hex_p((size_t)arg, info.spec)); // 이런거 수정하면 줄일수있을듯
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info);
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
	if (arg == 0)
		c_arg = ft_strdup("0"); // 예외처리 하나씩 하지말고 여기서 해도 될듯? ft_itoa_u에서는 지우자.
	else if (info.spec == 'u') // 위에 d나 i에서도 여기서 바로 해주고, apply_flag에서는 지우자.
		c_arg = ft_itoa_u(arg);
	else
		c_arg = dec_to_hex(arg, info.spec);
	// printf("!%s!\n", c_arg);
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}
