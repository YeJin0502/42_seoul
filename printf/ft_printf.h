/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 05:02:10 by gmoon            ###   ########.fr       */
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

typedef struct	s_index
{
	int i;
	int j;
}				t_index;

typedef struct	s_f_info
{
	int minus;
	int zero;
	int width;
	int precision;
	int c_arg_nega;
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

t_list		*find_spec_adr(const char *fmt);
int			no_spec_print(const char *format);
t_info		*make_info_and_free(t_list *spec_adr, int count_s);
int			print_and_count(const char *format, int count_s, t_info *info, va_list ap);

/*
**	sub_function
*/
t_f_info	make_f_info(t_info info, va_list ap);
char		*convert_c(va_list ap);
char		*convert_s(va_list ap);
char		*convert_p(va_list ap, char spec);
char		*convert_di(va_list ap);
char		*convert_uxX(va_list ap, char spec);
char		*apply_flag(char *c_arg, t_f_info f_info, t_info info);
char		*apply_flag_s(char *c_arg, t_f_info f_info, t_info info);
void		p_bigger_then_w(char *ret, char *c_arg, t_f_info f_info, int c_arg_size);
void		p_bigger_then_w_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size);
void		w_bigger_then_p(char *ret, char *c_arg, t_f_info f_info, int c_arg_size);
void		w_bigger_then_p_s(char *ret, char *c_arg, t_f_info f_info, int c_arg_size);

/*
**	util_function
*/
int			is_spec(const char c);
int			is_flag(const char c);
char		**flags_free(char ***flag, int i);
void		all_free(t_list **lst, char **specs, char ***flags, int count_s);
char		*ft_itoa_u(unsigned int n);
char		*dec_to_hex(size_t dex, char spec);
int			pf_max(int n1, int n2);
int			pf_min(int n1, int n2);
int			is_contain(char *str, char c);

#endif