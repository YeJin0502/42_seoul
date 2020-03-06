/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/07 01:42:22 by gmoon            ###   ########.fr       */
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

int			ft_printf(const char *format, ...);

/*
**	pf_apply_flag_utils.c
*/
int			ft_max(int n1, int n2);

/*
**	pf_apply_flag.c
*/
char		*apply_flag(char *c_arg, char spec, t_f_info f_info);

/*
**	pf_make_f_info.c
*/
t_f_info w0_p0(t_f_info ret, char *flag);
t_f_info w0_p1(t_f_info ret, char *flag);
t_f_info w1(t_f_info ret, char *flag);
t_f_info wc_process1(t_f_info *ret, va_list ap, int **is_wc_width);
t_f_info wc_process2(t_f_info *ret, va_list ap, int **is_wc_precision);
t_f_info	make_f_info(char *flag, va_list ap, int *is_wc_width, int *is_wc_precision);

/*
**	pf_make_info_utils.c
*/
int make_precision(char *flag);
int make_width(char *flag);
int	is_spec(const char c);
int	is_flag(const char c);

char		*make_specs(const char *format, int count_s);
char		**make_flags(const char *format, int count_s);

/*
**	pf_make_info.c
*/

t_info		*make_info(char *specs, char **flags);

/*
**	pf_printf_process.c
*/
int			count_arg(const char *format, int *count_s);
int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);
t_info		*make_info_and_free(const char *format, int count_s);
const char *meet_specifier(int *ret, const char *format, t_info info, va_list ap);

/*
**	pf_specifier_process_utils.c
*/
char		*ft_itoa_u(unsigned int n);
char		*dec_to_hex(unsigned int dex, char spec);

/*
**	pf_specifier_process.c
*/
int			c_process(va_list ap , char *flag, char spec);
int			s_process(va_list ap , char *flag, char spec);
int			p_process(va_list ap , char *flag, char spec);
int			di_process(va_list ap , char *flag, char spec);
int			uxX_process(va_list ap , char *flag, char spec);

void free_and_null(char *str);


#endif