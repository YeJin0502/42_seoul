/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:05:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 17:02:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
// malloc, free, write, va_start, va_arg, va_copy, va_end
// libft 다 써도 됨.
// - 다음 변환을 관리한다: cspdiuxX%
#include <stdio.h> //임시

typedef struct		s_content
{
	int				met_dot;
	int				minus;
	int				zero;
	size_t			width;
	size_t			prec;
	int				is_nega;
	// int				is_prec_zero;
	// char			spec; // 변환에서 필요하면 추가하는데, switch에서만 필요하면 없앨거임.
}					t_cont; // static 변수로 연결리스트 위치 저장해야하나?

typedef struct	s_info
{
	va_list		va;
	int			arg_num;
	t_list		*lst;
	t_list		*curr;
}				t_info;

int		ft_printf(const char *fmt, ...);
int		check_and_init(const char *fmt, t_info *info);
int		is_spec(char mover);
int		print_and_count(const char *fmt, t_info *info);
int		c_process(t_info *info, char spec);
int		s_process(t_info *info);
int		p_process(t_info *info, char spec);
int		di_process(t_info *info, char spec);
int		uxx_process(t_info *info, char spec);
char	*apply_flag(char *s_arg, t_info *info, char spec);
char	*apply_flag_s(char *s_arg, t_info *info);
char	*dec_to_hex(size_t dec, char spec);
char	*pf_itoa_u(unsigned int n);

#endif