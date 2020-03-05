/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 08:14:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_info
{
	int i;
	char spec;
	char *flag;
}	t_info;

typedef struct s_f_info
{
	int minus;
	int zero;
	int width;
	int precision;
}	t_f_info;

// ft_printf.c
int			ft_printf(const char *format, ...);
int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);

// pf_apply_flag_utils.c 함수개수 아래에서 남으면 아래로 합치고 static으로 하면 될듯.
int			ft_max(int n1, int n2);

// pf_apply_flag.c
char		*apply_flag(char *c_arg, char *flag, char spec);

// pf_dec_to_hex.c
char		*dec_to_hex_x(unsigned int dex);
char		*dec_to_hex_X(unsigned int dex);

// pf_make_f_info.c
int			make_precision(char *flag);
int			make_width(char *flag);
t_f_info	make_f_info(char *flag);
char		*apply_flag(char *c_arg, char *flag, char spec);

// pf_make_info_utils.c - flags 줄이다가 여기로 옮기면 될듯
int			is_spec(const char c);
int			is_flag(const char c);

// pf_make_info.c - flags 만 줄이면 됨
char		*make_specs(const char *format, int count_s);
char		**make_flags(const char *format, int count_s);
t_info		*make_info(char *specs, char **flags);
t_info		*make_info_and_free(const char *format, int count_s);

// pf_meet.c
const char	*if_same_move(const char *format, char *flag);
int			pt_memory(void *arg); // 이름 바꿔야함...
const char *meet_percent(int *ret, const char *format, t_info info, va_list ap);
int			meet_c(va_list ap , char *flag, char spec);
int			meet_s(va_list ap , char *flag, char spec);
int			meet_p(va_list ap , char *flag, char spec);
int			meet_d(va_list ap , char *flag, char spec);
int			meet_i(va_list ap , char *flag, char spec);
int			meet_u(va_list ap , char *flag, char spec);
int			meet_x(va_list ap , char *flag, char spec);
int			meet_X(va_list ap , char *flag, char spec);

// pf_printf_process
int			count_spec(const char *format);
int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);

// pf_utils.c
void		ft_putnbr_u(unsigned int n, int fd);
char		*ft_itoa_u(unsigned int n);
int			ft_memlen(void *str);


#endif