/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 01:18:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char	*make_specs(const char *format, int count_s)
{
	char	*ret;
	int		i;

	if(!(ret = (char *)malloc(count_s + 1)))
		return (0);
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s && *format)
	{
		if (*(format - 1) == '%' && *format != '%')
		{
			while (is_flag(*format) == 1)
				format++;
			if (is_spec(*format) == 1)
				ret[i++] = *format;
			else
			{
				printf("zz\n");
				return 0;
			}
		}
		format++;
	}
	if (i != count_s)
		return (0);
	return (ret);
}

static char	**make_flags_sub(char **ret, const char **format, int *i, int *len)
{
	(*format)++;
	while (is_flag(*(*format + *len)) == 1)
		(*len)++;
	if (!(ret[*i] = (char *)malloc(*len + 1)))
	{
		while (--(*i) >= 0)
			free(ret[*i]);
		free(ret);
		return (0);
	}
	ret[*i][*len] = '\0';
	while (--(*len) >= 0)
		ret[*i][*len] = *(*format + *len);
	(*i)++;
	return (ret);
}

char	**make_flags(const char *format, int count_s)
{
	char **ret;
	int i;
	int len;

	if (!(ret = (char **)malloc(sizeof(char *) * count_s)))
		return (0);
	i = 0;
	while (i < count_s && *format)
	{
		len = 0;
		format = ft_strchr(format, '%');
		if (*(format + 1) == '%')
			format = format + 2;
		else
			if (make_flags_sub(ret, &format, &i, &len) == NULL)
				return (0);
		format++;
	}
	if (i != count_s)
		return 0;
	return (ret);
}

t_info	*make_info(char *specs, char **flags)
{
	int		i;
	int		size;
	t_info	*ret;

	i = 0;
	size = ft_strlen(specs);
	if (!(ret = (t_info *)malloc(sizeof(t_info) * size)))
		return (0);
	while (i < size)
	{
		ret[i].i = i;
		ret[i].spec = specs[i];
		if (!(ret[i].flag = (char *)malloc(ft_strlen(flags[i]) + 1)))
		{
			while (--i >= 0)
				free(ret[i].flag);
			free(ret);
		}
		ret[i].flag[ft_strlen(flags[i])] = '\0';
		ret[i].flag = ft_memmove(ret[i].flag, flags[i], ft_strlen(flags[i]));
		i++;
	}
	return (ret);
}
