/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 08:30:38 by gmoon            ###   ########.fr       */
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
	if (arg != 0) // 이렇게해볼까
		c_arg[0] = arg; // 457~459은 어떻게하냐
	c_arg[1] = '\0';
	if (*(info.flag) != '\0')
		c_arg = apply_flag(c_arg, info.f_info, info);
	if (c_arg == NULL) // 아마 다 추가하고, free도 해야할 듯.
		return 0;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int	s_process(va_list ap, t_info info)
{
	char		*arg;
	char		*c_arg;
	int			c_arg_size;

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, char *);
	if (arg == 0)
		c_arg = ft_strdup("(null)"); // null 개념 약해서 문자열로 줘버리는거 오반데..ㅠㅠ 일단은..나중에고치자
	else if (arg[0] == '\0')
		c_arg = ft_strdup("\0");
	else
		c_arg = ft_strdup(arg);
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

	info.f_info = make_f_info(info, ap);
	arg = va_arg(ap, void *);
	if (arg == 0)
		c_arg = ft_strdup("(nil)");
	else
		c_arg = ft_strjoin("0x", dec_to_hex((size_t)arg, info.spec)); // 이런거 수정하면 줄일수있을듯
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
	if (*info.flag != '\0')
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
