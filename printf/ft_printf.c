/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 01:28:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_flag
{
	int	left;
	int	width;
	int	precision;
	int	zero;
}				t_flag;

typedef struct	s_total
{
	int		i;
	char	specifier;
	char	*arg;
	t_flag	s_flag;
}				t_total;

int ft_printf(const char *format, ...)
{
	va_list ap; //
	int count_s;
	char *char_s;
	t_total *total;

	if (!format)
		return 0;
	count_s = count_specifier(format);
	if (count_s == 0)
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	char_s = char_specifier(format, count_s);

	va_start(ap, format);

	int i = 0;
	total = (t_total *)malloc(sizeof(t_total) * (count_s)); // +1 해줘서 널포인트 가르키게 하려고했는데 안되는듯. 연결리스트여야 가능한가봐..?
	while (i < count_s)
	{
		total[i].i = i; // 아 구조체 malloc 해주는게 헷갈리네.
		total[i].specifier = char_s[i];
		if (total[i].specifier == 'c')
			total[i].arg = va_arg(ap, char);
		else if (total[i].specifier == 'x')
			asdfasdf;
		total[i].s_flag = 함수;
		i++;
	}


	return 0;
}

