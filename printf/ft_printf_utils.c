/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 07:07:20 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_spec(const char *format)
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

int is_spec(const char c)
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

int is_flag(const char c)
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

char *make_spec(const char *format, int count_s)
{
	char *ret;
	int i;

	if(!(ret = (char *)malloc(count_s + 1)))
		return (0);
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			while (is_flag(*format) == 1)
				format++;
			if (is_spec(*format) == 1)
				ret[i++] = *format;
			else
				return 0;
		}
		format++; // 대충 돌아가는거 확인.
	}
	return (ret);
}

char **make_flag(char *format, int count_s)
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
			while (is_spec(*(format + len)) == 0)
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
			{
				ret[i][len - 1] = *(format + len);
				len--;
			}
			i++;
		}
		format++;
	}
	return (ret);
}
// 나중에 줄이던가 하자.

void	ft_putunbr(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10, fd);
		ft_putunbr(n % 10, fd);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	return ;
} // 되나? 테스트 안해봄
