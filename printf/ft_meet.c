/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 07:00:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 07:00:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void meet_c(va_list ap)
{
	char ret;

	ret = va_arg(ap, char);
	write(1, &ret, 1);
	return ;
}

char *meet_s(va_list ap)
{
	char *ret;

	ret = va_arg(ap, char *); // 이게 되나? 주소 줘서 될라나?
	write(1, ret, ft_strlen(ret));
	return ;
}

void *meet_p(va_list ap)
{
	void *ret;

	ret = va_arg(ap, void *); // 메모리주소 어떻게하지..?
	write(1, ret, 1); // 이게 되나...? 모르겠는데.
	return ; 
}

void meet_d(va_list ap)
{
	int ret;

	ret = va_arg(ap, int);
	ft_putnbr_fd(ret, 1);
	return (ret);
}

int meet_i(va_list ap)
{
	int ret;

	ret = va_arg(ap, int);
	ft_putnbr_fd(ret, 1);
	return (ret);
}

unsigned int meet_u(va_list ap)
{
	unsigned int ret;

	ret = va_arg(ap, unsigned int);
	ft_putunbr(ret, 1);
	return (ret);
}

unsigned int meet_x(va_list ap)
{
	unsigned int ret;

	ret = va_arg(ap, unsigned int);
	ft_putunbr(ret, 1);
	return (ret);
}

unsigned int meet_X(va_list ap)
{
	unsigned int ret;

	ret = va_arg(ap, unsigned int);
	ft_putunbr(ret, 1);
	return (ret);
}