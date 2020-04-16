/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 23:46:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/17 00:04:43 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	char_check(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != '2' &&
			*line != ' ' && *line != '\n' && *line != 'N' &&
			*line != 'S' && *line != 'E' && *line != 'W')
			error_exit(3);
		line++;
	}
}

void	wall_check(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map_width)
	{
		j = -1;
		while (++j < info->map_height)
		{
			if ((i == 0 || i == info->map_width - 1 ||
				j == 0 || j == info->map_height - 1) &&
				info->map[j][i] != 1)
				error_exit(3);
			// else if (info->map[j][i] < 0 || info->map[j][i] > 2)
				// error_exit(3);
		}
	}
}
