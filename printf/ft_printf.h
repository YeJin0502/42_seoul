/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 01:58:55 by gmoon            ###   ########.fr       */
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

int			ft_printf(const char *format, ...);

int			count_spec(const char *format);
int			is_spec(const char c);
int			is_flag(const char c);
char		*make_specs(const char *format, int count_s);
char		**make_flags(const char *format, int count_s);
t_info		*make_list(char *specs, char **flags);
const char	*if_same_move(const char *format, char *flag);
const char	*meet_percent(int *ret, const char *format, t_info info, va_list ap);

int			meet_c(va_list ap); // , char *flag);
int			meet_s(va_list ap); // , char *flag);
int			meet_p(va_list ap); // , char *flag);
int			meet_d(va_list ap); // , char *flag);
int			meet_i(va_list ap); // , char *flag);
int			meet_u(va_list ap); // , char *flag);
int			meet_x(va_list ap); // , char *flag);
int			meet_X(va_list ap); // , char *flag);

void		ft_putnbr_u(unsigned int n, int fd);
char		*ft_itoa_u(unsigned int n);
int			ft_memlen(void *str);



#endif