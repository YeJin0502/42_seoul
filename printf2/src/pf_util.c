/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:21:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/10 17:16:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_spec(char mover)
{
	char *spec;

	spec = "cspdiuxX%";
	while (*spec)
	{
		if (mover == *spec)
			return (1);
		spec++;
	}
	return (0);
}

char	*dec_to_hex(size_t dec, char spec)
{
	long long	hex_len;
	size_t		tmp;
	char		*hex;

	if (dec == 0)
		return (ft_strdup("0"));
	tmp = dec;
	hex_len = 0;
	while (tmp)
	{
		tmp = tmp / 16;
		hex_len++;
	}
	if (!(hex = (char *)malloc(hex_len + 1)))
		return (0);
	hex[hex_len] = '\0';
	while (--hex_len >= 0)
	{
		if (dec % 16 <= 9)
			hex[hex_len] = dec % 16 + '0';
		else if (spec == 'x' || spec == 'p')
			hex[hex_len] = dec % 16 + 'a' - 10;
		else if (spec == 'X')
			hex[hex_len] = dec % 16 + 'A' - 10;
		dec = dec / 16;
	}
	return (hex);
}

static int	un_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*pf_itoa_u(unsigned int n)
{
	unsigned int	size;
	char			*ret;

	size = un_size(n);
	if (!(ret = (char *)malloc(size + 1)))
		return (0);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[(size--) - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}
