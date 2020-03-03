/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/03 17:20:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int ft_printf(const char *format, ...)
{
	va_list ap; //
	int size;
	int i;

	size = ft_lstsize(ap);
	va_start(ap, size);
	i = 0;
	while (i < size)
	{
		int num
	}

}

int main()
{
	ft_printf("aaa");
}