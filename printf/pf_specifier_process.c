/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:26:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 09:46:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *get_va_arg_c(va_list ap)
{
	char arg;
	char *c_arg;

	arg = (char)va_arg(ap, int);
	c_arg = (char *)malloc(2);
	if (arg != 0)
		c_arg[0] = arg; // 457~459은 어떻게하냐
	c_arg[1] = '\0';
	return (c_arg);
}

char *get_va_arg_s(va_list ap)
{
	char *arg;

	arg = va_arg(ap, char *);
	if (arg == 0)
		return (ft_strdup("(null)"));
	else if (arg[0] == '\0')
		return (ft_strdup(""));
	else
		return (ft_strdup(arg));
}

char *get_va_arg_p(va_list ap, char spec)
{
	void *arg;
	char *tmp;
	char *c_arg;

	arg = va_arg(ap, void *);
	if (arg == 0)
		c_arg = ft_strdup("(nil)");
	else
	{
		tmp = dec_to_hex((size_t)arg, spec);
		c_arg = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (c_arg);
}

char *get_va_arg_di(va_list ap)
{
	int arg;

	arg = va_arg(ap, int);
	return (ft_itoa(arg));
}

char *get_va_arg_uxX(va_list ap, char spec)
{
	unsigned int arg;

	arg = va_arg(ap, unsigned int);
	if (arg == 0)
		return (ft_strdup("0"));
	else if (spec == 'u')
		return (ft_itoa_u(arg));
	else
		return (dec_to_hex((size_t)arg, spec));
}
