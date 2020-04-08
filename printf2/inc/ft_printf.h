/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:05:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/08 20:47:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
// malloc, free, write, va_start, va_arg, va_copy, va_end
#include <stdio.h> //임시

typedef struct		s_content
{
	int				met_dot;
	int				minus;
	int				zero;
	int				width;
	int				prec;
	char			spec;
}					t_cont;

// typedef struct		s_list
// {
// 	t_cont				*cont;
// 	// int				met_dot;
// 	// int				minus;
// 	// int				zero;
// 	// int				width;
// 	// int				prec;
// 	// char			spec;
// 	struct s_list	*next; // 연결리스트?
// }					t_list;

typedef struct	s_info
{
	va_list		va;
	int			arg_num;
	t_list		*flag;
}				t_info;

int	ft_printf(const char *fmt, ...);
int check_and_init(const char *fmt, t_info *info);

#endif