/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 09:49:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

#include <stdio.h>////// 나중에 빼야

typedef struct	s_check
{
	int	num;
	int	w_wc;
	int p_wc;
	int	dot;
	int	wrong;
}				t_check;

typedef struct	s_f_info
{
	int minus;
	int zero;
	int width;
	int precision;
	int c_arg_nega;
	int width_nega;
	int prec_nega;
}				t_f_info;

typedef struct	s_info
{
	char *spec_adr;
	char spec;
	char *flag;
	t_f_info f_info;
}				t_info;

int			ft_printf(const char *format, ...);

/*
**	pf_apply_flag.c - 여기가 리얼 문제... 쉬었다가 수정해보자...
*/
char		*apply_flag(char *c_arg, t_f_info f_info, t_info info);
char		*apply_flag_s(char *c_arg, t_f_info f_info, t_info info);

/*
**	pf_apply_flag_utils.c - OK
*/
int			pf_max(int n1, int n2);
int			pf_min(int n1, int n2);
int			is_contain(char *str, char c);

/*
**	find_spec_adr.c - OK
*/
t_list		*find_spec_adr(const char *fmt);

/*
**	pf_make_f_info.c - OK
*/
t_f_info	make_f_info(t_info info, va_list ap);

/*
**	pf_make_info.c - OK
*/
t_info		*make_info_and_free(t_list *spec_adr, int count_s);

/*
**	pf_make_info_utils.c - OK
*/
int			is_spec(const char c);
int			is_flag(const char c);
void		all_free(t_list **lst, char **specs, char ***flags, int count_s);

/*
**	pf_printf_process.c - OK
*/
int			no_spec_print(const char *format);
int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);
const char	*meet_specifier(int *ret, const char *format, t_info info, va_list ap);
int			get_va_arg(va_list ap, t_info info);

/*
**	pf_specifier_process.c - OK
*/
char		*get_va_arg_c(va_list ap);
char		*get_va_arg_s(va_list ap);
char		*get_va_arg_p(va_list ap, char spec);
char		*get_va_arg_di(va_list ap);
char		*get_va_arg_uxX(va_list ap, char spec);

/*
**	pf_specifier_process_utils.c - OK
*/
char		*ft_itoa_u(unsigned int n);
char		*dec_to_hex(size_t dex, char spec);




#endif