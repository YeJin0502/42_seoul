/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:56:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 08:07:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

int	pf_min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	else
		return (n1);
}

int	is_contain(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}