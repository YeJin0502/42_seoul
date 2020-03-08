/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 06:09:23 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_check
{
	int	num;
	int	w_wc;
	int p_wc;
	int	dot;
	int	wrong;
}				t_check;

typedef struct s_f_info
{
	int minus;
	int zero;
	int width;
	int precision;
	int negative;
}	t_f_info;

typedef struct	s_info
{
	int i;
	char *spec_adr;
	char spec;
	char *flag;
	int width_star;
	int prec_star;
	t_f_info f_info;
}				t_info;


int			ft_printf(const char *format, ...);

/*
**	pf_apply_flag_utils.c
*/
int			pf_max(int n1, int n2);

/*
**	pf_apply_flag.c
*/
char		*apply_flag(char *c_arg, t_f_info f_info, t_info info);
char *apply_flag_s(char *c_arg, t_f_info f_info, t_info info);

/*
**	pf_make_f_info.c
*/
t_f_info w0_p0(t_f_info ret, char *flag);
t_f_info w0_p1(t_f_info ret, char *flag);
t_f_info w1(t_f_info ret, char *flag);
t_f_info wc_process1(t_f_info *ret, va_list ap, int **is_wc_width);
t_f_info wc_process2(t_f_info *ret, va_list ap, int **is_wc_precision);
t_f_info make_f_info(t_info info, va_list ap); //, int *is_wc_width, int *is_wc_precision);

/*
**	pf_make_info_utils.c
*/
int make_precision(t_info *info);
int make_width(t_info *info);
int	is_spec(const char c);
int	is_flag(const char c);

char *make_specs(t_list *spec_adr, int count_s);
char		**make_flags(t_list *spec_adr, int count_s);

/*
**	pf_make_info.c
*/

t_info		*make_info(char *specs, char **flags);

/*
**	pf_printf_process.c
*/
t_list	*count_spec(const char *fmt); // 이거 대폭 수정 필요!
int is_valid(const char c, t_check *check);

int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);
t_info		*make_info_and_free(t_list *spec_adr, int count_s);
const char *meet_specifier(int *ret, const char *format, t_info info, va_list ap);

/*
**	pf_specifier_process_utils.c
*/
char		*ft_itoa_u(unsigned int n);
char		*dec_to_hex(unsigned int dex, char spec);

/*
**	pf_specifier_process.c
*/
int			c_process(va_list ap , t_info info);
int			s_process(va_list ap , t_info info);
int			p_process(va_list ap , t_info info);
int			di_process(va_list ap , t_info info);
int			uxX_process(va_list ap , t_info info);

void free_and_null(char *str);
void make_check_null(t_check *check);
char *w_bigger_then_p_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size);
int pf_min(int n1, int n2);
char *p_bigger_then_w_s(char *ret, char **c_arg, t_f_info f_info, int c_arg_size);
t_f_info make_f_info_s(t_info info, va_list ap, int *is_wc_width, int *is_wc_precision);
char	*dec_to_hex_p(size_t dec, char spec);
int is_contain(char *str, char c);

#endif