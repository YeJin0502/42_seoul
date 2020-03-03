/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day1_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/04 06:21:26 by gmoon            ###   ########.fr       */
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

typedef struct		s_total
{
	int				i;
	char			specifier;
	char			arg_c;
	char			arg_s;
	void			*arg_p;
	int				arg_di;
	unsigned int	arg_uxX;
	t_flag			flag;
}					t_total;

int ft_printf(const char *format, ...)
{
	va_list ap; //
	int count_s;
	char *s_set;
	char **flag_sets;
	t_total *total;
	int i;

	if (!format)
		return 0;
	if ((count_s = count_specifier(format)) == 0)
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	s_set = make_spec(format, count_s);
	flag_sets = make_flag(format, count_s);
	va_start(ap, format);
	total = (t_total *)malloc(sizeof(t_total) * (count_s));
	i = 0;
	while (i < count_s)
	{
		total[i].i = i;
		total[i].specifier = s_set[i];
		if (total[i].specifier == 'c')
			total[i].arg_c = (char)va_arg(ap, int);
		else if (total[i].specifier == 's')
			total[i].arg_s = ft_strdup(va_arg(ap, char *));
		else if (total[i].specifier == 'p')
			total[i].arg_p = va_arg(ap, void *);
		else if (total[i].specifier == 'd')
			total[i].arg_di = va_arg(ap, int);
		else if (total[i].specifier == 'i')
			total[i].arg_di = va_arg(ap, int);
		else if (total[i].specifier == 'u')
			total[i].arg_uxX = va_arg(ap, unsigned int);
		else if (total[i].specifier == 'x')
			total[i].arg_uxX = va_arg(ap, unsigned int);
		else if (total[i].specifier == 'X')
			total[i].arg_uxX = va_arg(ap, unsigned int);
		total[i].flag = make_flag(flag_sets[i], total[i].specifier);
		i++;
	}


	return 0;
}

t_flag make_flag(char *flag_set, char specifier)
{
	int i;
	t_flag ret;

	i = 0;
	ret.left = 0;
	ret.width = 0;
	ret.precision = 0;
	ret.zero = 0;
	while (flag_set[i])
	{
		if (flag_set[i] == '0' && ret.precision = 0) // 왜? 뭐가 문제지? TT
			ret.zero = 1;
		
	}
}
