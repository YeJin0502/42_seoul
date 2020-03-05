/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:43:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 07:59:38 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *dec_to_hex_x(unsigned int dec)
{
	int hex_len;
	unsigned int tmp;
	char *hex;

	tmp = dec;
	hex_len = 0;
	while (tmp)
	{
		tmp = tmp / 16;
		hex_len++;
	}
	hex = (char *)malloc(hex_len + 1);
	hex[hex_len] = '\0';
	while (--hex_len >= 0)
	{
		if (0 <= dec % 16 && dec % 16 <= 9)
			hex[hex_len] = dec % 16 + '0';
		else
			hex[hex_len] = dec % 16 + 'a' - 10;
		dec = dec / 16;
	}
	return (hex);
}

char *dec_to_hex_X(unsigned int dec)
{
	int hex_len;
	unsigned int tmp;
	char *hex;

	tmp = dec;
	hex_len = 0;
	while (tmp)
	{
		tmp = tmp / 16;
		hex_len++;
	}
	hex = (char *)malloc(hex_len + 1);
	hex[hex_len] = '\0';
	while (--hex_len >= 0)
	{
		if (0 <= dec % 16 && dec % 16 <= 9)
			hex[hex_len] = dec % 16 + '0';
		else
			hex[hex_len] = dec % 16 + 'A' - 10;
		dec = dec / 16;
	}
	return (hex);
}
