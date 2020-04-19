/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:45:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/20 05:44:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_filename(char *filename)
{
	filename = filename + ft_strlen(filename) - 4;
	if (ft_strncmp(filename, ".cub", 4) != 0)
		error_exit(0);
}

static void	putstr_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void		error_exit(int errno)
{
	if (errno == 0)
		putstr_exit("Error\n: Argv is wrong.\n");
	else if (errno == 1)
	{
		perror("Error\n");
		exit(1);
	}
	else if (errno == 2)
		putstr_exit("Error\n: Some elements is missing.\n");
	else if (errno == 3)
		putstr_exit("Error\n: Map is wrong or Wrong element input.\n");
	else if (errno == 4)
		putstr_exit("Error\n: Duplicate elements.\n");
	else if (errno == 5)
		putstr_exit("Error\n: Xserver error.\n");
}
