/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 01:28:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_specifier(const char *format)
{
	int count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format - 1) != '%')
			count++;
		format++;
	}
	return (count);
}

char *char_specifier(const char *format, int count_s)
{
	char *ret;
	int i;
	char *spec_set;

	spec_set = "cspdiuxX";
	if(!(ret = (char *)malloc(count_s + 1)))
		return (0);
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			if ()
			
		}
		format++;
	}
	return (ret);
}

int is_in_spec_set(const char c)
{
	char *spec_set;

	spec_set = "cspdiuxX";
	while (*spec_set)
	{
		if (*spec_set == c)
			return (1);
		spec_set++;
	}
	return (0);
}

int is_in_flag_set(const char c)
{
	char *flag_set;

	flag_set = "-.0*";
	while (*flag_set)
	{
		if (*flag_set == c)
			return (1);
		flag_set++;
	}
	return (0);
}
