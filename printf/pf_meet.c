/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_meet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 07:00:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 08:02:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char *if_same_move(const char *format, char *flag)
{
	while (*format == *flag)
	{
		format++;
		flag++;
	}
	return (format);
}

int pt_memory(void *arg) // 이름 바꿔야함...
{
	int ret;
	ret = (int)arg; // 이게 안돼서 문제아닌가..ㅠㅠ
	return (ret);
}

const char *meet_percent(int *ret, const char *format, t_info info, va_list ap)
{
	format++; // % 다음으로 보냄
	if (info.flag != NULL)
		format = if_same_move(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + meet_c(ap, info.flag, info.spec);
	else if (info.spec == 's')
		*ret = *ret + meet_s(ap, info.flag, info.spec);
	else if (info.spec == 'p')
		*ret = *ret + meet_p(ap, info.flag, info.spec);
	else if (info.spec == 'd')
		*ret = *ret + meet_d(ap, info.flag, info.spec);
	else if (info.spec == 'i')
		*ret = *ret + meet_i(ap, info.flag, info.spec);
	else if (info.spec == 'u')
		*ret = *ret + meet_u(ap, info.flag, info.spec);
	else if (info.spec == 'x')
		*ret = *ret + meet_x(ap, info.flag, info.spec);
	else if (info.spec == 'X')
		*ret = *ret + meet_X(ap, info.flag, info.spec);
	return (format);
}

int meet_c(va_list ap, char *flag, char spec)
{
	char arg;
	char *c_arg;
	int c_arg_size;

	arg = (char)va_arg(ap, int);
	c_arg = (char *)malloc(2);
	c_arg[0] = arg;
	c_arg[1] = '\0';
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);
	if (c_arg == NULL)
		return 0;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_s(va_list ap, char *flag, char spec)
{
	char *arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, char *);
	if (flag != NULL)
		c_arg = apply_flag(arg, flag, spec);
	else
		c_arg = arg;
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	return (c_arg_size);
}

int meet_p(va_list ap, char *flag, char spec)
{
	void *arg;
	char *c_arg_tmp;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, void *);
	c_arg_tmp = dec_to_hex_x(pt_memory(arg));
	c_arg = ft_strjoin("0x", c_arg_tmp);
	if (*flag != '\0') // 왜 얘만 이렇게 검사하게될까..? 그걸 모르겠네. 다른애들은 그냥 flag != NULL 검사했는데.
		c_arg = apply_flag(c_arg, flag, spec);
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_d(va_list ap, char *flag, char spec)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_i(va_list ap, char *flag, char spec)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_u(va_list ap, char *flag, char spec)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = ft_itoa_u(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_x(va_list ap, char *flag, char spec)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = dec_to_hex_x(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_X(va_list ap, char *flag, char spec)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = dec_to_hex_X(arg);
	if (flag != NULL)
		c_arg = apply_flag(c_arg, flag, spec);	
	c_arg_size = (int)ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}