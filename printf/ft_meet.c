/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 07:00:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 01:50:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int meet_c(va_list ap) //, char *flag) // 반환값은 출력된 글자수
{
	char arg;

	arg = (char)va_arg(ap, int);
	write(1, &arg, 1);
	return (1);
}

int meet_s(va_list ap) //, char *flag)
{
	char *arg;

	arg = va_arg(ap, char *); // 이게 되나? 주소 줘서 될라나?
	write(1, arg, ft_strlen(arg));
	return ((int)ft_strlen(arg));
}

int meet_p(va_list ap) //, char *flag)
{
	void *arg;

	arg = va_arg(ap, void *);
	write(1, arg, ft_memlen(arg)); // 이게 되나...? 모르겠는데.
	return ((int)ft_memlen(arg)); 
}

int meet_d(va_list ap) //, char *flag)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	// 원래는 그전에 또! flag를 이용해 변환해주고, 프린트하고, 리턴해야함.
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_i(va_list ap) //, char *flag)
{
	int arg;
	char *c_arg;
	int c_arg_size;

	arg = va_arg(ap, int);
	c_arg = ft_itoa(arg);
	// 원래는 그전에 또! flag를 이용해 변환해주고, 프린트하고, 리턴해야함.
	c_arg_size = ft_strlen(c_arg);
	write(1, c_arg, c_arg_size);
	free(c_arg);
	return (c_arg_size);
}

int meet_u(va_list ap) //, char *flag)
{
	unsigned int arg;
	char *c_arg;

	arg = va_arg(ap, unsigned int);
	c_arg = ft_itoa_u(arg);
	// 또 변환 필요
	write(1, c_arg, ft_strlen(c_arg));
	return (ft_strlen(c_arg));
}

int meet_x(va_list ap) //, char *flag)
{
	unsigned int arg;
	char *c_arg;

	arg = va_arg(ap, unsigned int);
	c_arg = ft_itoa_u(arg);
	// 또 변환 필요
	write(1, c_arg, ft_strlen(c_arg));
	return (ft_strlen(c_arg));
}

int meet_X(va_list ap) //, char *flag)
{
	unsigned int arg;
	char *c_arg;

	arg = va_arg(ap, unsigned int);
	c_arg = ft_itoa_u(arg);
	// 또 변환 필요
	write(1, c_arg, ft_strlen(c_arg));
	return (ft_strlen(c_arg));
}