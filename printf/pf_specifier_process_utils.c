/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifier_process_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:50:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 10:33:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_size_u(unsigned int n)
{
	int	size;
	
	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_u(unsigned int n)
{
	int		size;
	char	*ret;

	size = n_size_u(n);
	if (!(ret = (char *)malloc(size + 1)))
		return 0;
	ret[size] = '\0';
	while (size > 0)
	{
		ret[(size--) - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

char	*dec_to_hex(unsigned int dec, char spec)
{
	int				hex_len;
	unsigned int	tmp;
	char			*hex;

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
