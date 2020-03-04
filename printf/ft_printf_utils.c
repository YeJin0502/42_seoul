/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 03:58:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int	count_spec(const char *format)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format - 1) != '%')
			count++;
		format++;
	}
	return (count);
}

int	is_spec(const char c)
{
	char	*spec_set;

	spec_set = "cspdiuxX";
	while (*spec_set)
	{
		if (*spec_set == c)
			return (1);
		spec_set++;
	}
	return (0);
}

int	is_flag(const char c)
{
	char	*flag_set;

	flag_set = "-.0123456789"; // 수정)숫자 추가해줌
	while (*flag_set)
	{
		if (*flag_set == c)
			return (1);
		flag_set++;
	}
	return (0);
}

char	*make_specs(const char *format, int count_s)
{
	char	*ret;
	int		i;

	if(!(ret = (char *)malloc(count_s + 1)))
		return (0);
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s)
	{
		if (*(format - 1) == '%' && *format != '%')
		{
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

char	**make_flags(const char *format, int count_s)
{
	char **ret;
	int i;
	int len;

	if (!(ret = (char **)malloc(sizeof(char *) * count_s)))
		return 0;
	i = 0;
	while (i < count_s)
	{
		len = 0;
		format = ft_strchr(format, '%');
		if (*(format + 1) == '%')
			format = format + 2;
		else
		{
			format++; //flag 가르킴
			while (is_flag(*(format + len)) == 1)
				len++;
			if (!(ret[i] = (char *)malloc(len + 1)))
			{
				while (--i >= 0)
					free(ret[i]);
				free(ret);
				return (0);
			}
			ret[i][len] = '\0';
			while (--len >= 0)
				ret[i][len] = *(format + len);
			i++;
			// printf("i:%d, len:%d, now:%c ret[i]:%s\n", i, len, *format, ret[i]);
		}
		format++;
	}
	return (ret);
}
// 나중에 줄이던가 하자.

t_info	*make_list(char *specs, char **flags)
{
	int		i;
	int		size;
	t_info	*ret;

	i = 0;
	size = ft_strlen(specs);
	ret = (t_info *)malloc(sizeof(t_info) * size);
	while (i < size)
	{
		ret[i].i = i;
		ret[i].spec = specs[i];
		ret[i].flag = (char *)malloc(ft_strlen(flags[i]) + 1);
		ret[i].flag[ft_strlen(flags[i])] = '\0';
		// ret[i].flag = flags[i]; // 이거 바로 넣을 수 있나..? 주소 넣는거나, 복사하는게 헷갈리네.
		ret[i].flag = ft_memmove(ret[i].flag, flags[i], ft_strlen(flags[i]));
		i++;
	}
	return (ret);
} // 될라나..? 테스트도 어렵네.

////////////////

//
const char *if_same_move(const char *format, char *flag)
{
	while (*format == *flag)
	{
		format++;
		flag++;
	}
	return (format);
}
