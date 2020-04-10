/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:05:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 14:09:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_content
{
	int			met_dot;
	int			minus;
	int			zero;
	int			width;
	int			prec;
	int			is_nega;
}				t_cont;

typedef struct	s_info
{
	va_list		va;
	int			arg_num;
	t_list		*lst;
	t_list		*curr;
}				t_info;

int				ft_printf(const char *fmt, ...);
int				check_and_init(const char *fmt, t_info *info);
int				is_spec(char mover);
int				print_and_count(const char *fmt, t_info *info);
int				c_process(t_info *info, char spec);
int				s_process(t_info *info);
int				p_process(t_info *info);
int				di_process(t_info *info);
int				uxx_process(t_info *info, char spec);
char			*apply_flag(char *s_arg, t_info *info);
char			*apply_flag_s(char *s_arg, t_info *info);
char			*dec_to_hex(size_t dec, char spec);
char			*pf_itoa_u(unsigned int n);
void			make_cv_arg(char *cv_arg, size_t size, t_cont *flag, char *str);
int				ci_sub(char **mover, t_cont *flag, t_info *info);
void			putstr_c(char *cv_arg, int count);

#endif
