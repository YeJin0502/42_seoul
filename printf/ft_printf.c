/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 07:46:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

check_flag();

print_c();
print_s();
print_p;
print_d;
print_i;
print_u;
print_x;
print_X;



int ft_printf(const char *format, ...)
{
	int ret;
	int count_s;
	va_list ap;
	char **flag;

	count_s = count_spec(format);
	if (!(count_s = count_spec(format)))
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	va_start(ap, format);
	flag = make_flag;
	
	while (*format)
	{
		if (*format == '%' && *(format+1) != '%')
			meet_percent(ret, format);
		else
		{
			write(1, &format[i], 1);
			ret++;
		}
		format++;
	}


}



// // 테스트
// int main()
// {
// 	ft_printf("hi%dhello%d%%", 1, 2);
// }