/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:45:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/16 23:56:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_exit(int errno)
{
	if (errno == 1)
	{
		perror("Error\n");
		exit(1);
	}
	else if (errno == 2)
	{
		ft_putstr_fd("Error\n: Some elements is missing.\n", 1);
		exit(1);
	}
	else if (errno == 3)
	{
		ft_putstr_fd("Error\n: Map is wrong.\n", 1);
		exit(1);
	}
	else if (errno == 4)
	{
		ft_putstr_fd("Error\n: Duplicate elements.\n", 1);
		exit(1);
	}
	else if (errno == 5)
	{
		ft_putstr_fd("Error\n: Xserver error.\n", 1);
		exit(1);
	}
}
