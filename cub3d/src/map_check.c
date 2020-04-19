/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 23:46:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/20 04:38:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		char_check(char *line, int map_width)
{
	int i;

	i = 0;
	while (i < map_width && line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' &&
			line[i] != ' ' && line[i] != '\n' && line[i] != 'N' &&
			line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			error_exit(3);
		i++;
	}
}

static void	wall_check_sub1(char **map, int i, int j, t_info *info)
{
	int mov;

	mov = -1;
	while (i - ++mov >= 0)
	{
		if (map[i - mov][j] == 1)
			break ;
		else if (map[i - mov][j] == -1)
			error_exit(3);
	}
	mov = -1;
	while (i + ++mov < info->map_height)
	{
		if (map[i + mov][j] == 1)
			break ;
		else if (map[i + mov][j] == -1)
			error_exit(3);
	}
}

static void	wall_check_sub2(char **map, int i, int j, t_info *info)
{
	int mov;

	mov = -1;
	while (j - ++mov >= 0)
	{
		if (map[i][j - mov] == 1)
			break ;
		else if (map[i][j - mov] == -1)
			error_exit(3);
	}
	mov = -1;
	while (j + ++mov < info->map_width)
	{
		if (map[i][j + mov] == 1)
			break ;
		else if (map[i][j + mov] == -1)
			error_exit(3);
	}
}

void		wall_check(t_info *info)
{
	char **map;
	int i;
	int j;

	map = info->map;
	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		while (++j < info->map_width)
		{
			if (map[i][j] == 0)
			{
				wall_check_sub1(map, i, j, info);
				wall_check_sub2(map, i, j, info);
			}
		}
	}
}
