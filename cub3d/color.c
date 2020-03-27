/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 20:33:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 20:33:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dec_to_hex(int dec)
{
	long long	hex_len;
	int 		tmp;
	char		*hex;

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
		else
			hex[hex_len] = dec % 16 + 'A' - 10;
		dec = dec / 16;
	}
	return (hex);
}
