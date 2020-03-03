/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 04:21:51 by gmoon            ###   ########.fr       */
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

char *make_s_set(const char *format, int count_s)
{
	char *ret;
	int i;
	int j;

	if(!(ret = (char *)malloc(count_s + 1)))
		return (0);
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			while (is_in_flag_set(*format) == 1)
				format++;
			if (is_in_spec_set(*format) == 1)
				ret[i++] = *format;
			else
				return 0;
		}
		format++; // 대충 돌아가는거 확인.
	}
	return (ret);
}

char **make_flag_sets(char *format, int count_s)
{
	char **ret;
	int i;
	int len;

	if (!(ret = (char **)malloc(sizeof(char *) * count_s)))
		return 0;
	i = 0;
	len = 0;
	while (i < count_s)
	{
		format = ft_strchr(format, '%');
		if (*(format + 1) == '%')
			format = format + 2;
		else
		{
			while (is_in_spec_set(*(format + len)) == 0)
				len++;
			if (!(ret[i] = (char *)malloc(len + 1)))
			{
				while (--i >= 0)
					free(ret[i]);
				free(ret);
				return (0);
			}
			ret[i][len] = '\0';
			while (len > 0)
				ret[i][(len--) - 1] = *(format + (len--));
			i++;
		}
		format++;
	}
	return (ret);
}
// 나중에 줄이던가 하자.

