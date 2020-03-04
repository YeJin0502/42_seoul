/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 07:00:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 04:50:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

const char *meet_percent(int *ret, const char *format, t_info info, va_list ap)
{
	format++; // % 다음으로 보냄
	if (info.flag != NULL)
		format = if_same_move(format, info.flag);
	if (info.spec == 'c')
		*ret = *ret + meet_c(ap, info.flag);
	else if (info.spec == 's')
		*ret = *ret + meet_s(ap, info.flag);
	else if (info.spec == 'p')
		*ret = *ret + meet_p(ap, info.flag);
	else if (info.spec == 'd')
		*ret = *ret + meet_d(ap, info.flag);
	else if (info.spec == 'i')
		*ret = *ret + meet_i(ap, info.flag);
	else if (info.spec == 'u')
		*ret = *ret + meet_u(ap, info.flag);
	else if (info.spec == 'x')
		*ret = *ret + meet_x(ap, info.flag);
	else if (info.spec == 'X')
		*ret = *ret + meet_X(ap, info.flag);
	return (format);
}

int meet_c(va_list ap, char *flag)
{
	char arg;
	char *c_arg;
	int c_arg_size;

	arg = (char)va_arg(ap, int);
	c_arg = (char *)malloc(2);
	c_arg[0] = arg;
	c_arg[1] = '\0';
	if (flag == NULL)
		c_arg = convert_flag(arg);
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_s(va_list ap, char *flag)
{
	char *arg;
	char *c_arg;
	int *c_arg_size;

	arg = va_arg(ap, char *);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);
	else
		c_arg = arg;
	c_arg_size = ft_strlen(c_arg);
	write(1, arg, c_arg_size);
	if (flag != NULL)
		free(c_arg);
	return (c_arg_size);
}

int meet_p(va_list ap, char *flag)
{
	void *arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, void *);
	// printf("1arg:%d\n", arg);
	// printf("2arg:%d\n", (int *)arg 이건 공부해서 정리해야겠다.
	// printf("3arg:%d\n", *(int *)arg 이거 아니고 위에 두개임.
	// c_arg = char_memory(arg이게 안됨.
	c_arg = dec_to_hex_X(*(int *)arg 임시로 컴파일만 되게한거. 수정해야함
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);	
}

int meet_d(va_list ap, char *flag)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);	
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_i(va_list ap, char *flag)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);	
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_u(va_list ap, char *flag)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = ft_itoa_u(arg);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);	
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_x(va_list ap, char *flag)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = dec_to_hex_x(arg);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);	
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_X(va_list ap, char *flag)
{
	unsigned int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, unsigned int);
	c_arg = dec_to_hex_X(arg);
	if (flag != NULL)
		c_arg = convert_flag(c_arg);	
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}