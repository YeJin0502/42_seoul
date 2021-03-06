/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 06:30:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/20 05:21:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_info *info, double view_angle, int i, int j)
{
	if (info->x || info->y)
		error_exit(3);
	info->map[i][j] = 0;
	info->x = info->tile_width * j + info->tile_width / 2;
	info->y = info->tile_height * i + info->tile_height / 2;
	info->view_angle = view_angle;
}

static void	convert_process(t_info *info, int i, int j)
{
	if (info->map[i][j] == ' ')
		info->map[i][j] = 1;
	else if (info->map[i][j] == '0')
		info->map[i][j] = 0;
	else if (info->map[i][j] == '1')
		info->map[i][j] = 1;
	else if (info->map[i][j] == '2')
	{
		info->item_count++;
		info->map[i][j] = 2;
	}
	else if (info->map[i][j] == 'N')
		init_player(info, 1.5 * PI, i, j);
	else if (info->map[i][j] == 'S')
		init_player(info, 0.5 * PI, i, j);
	else if (info->map[i][j] == 'W')
		init_player(info, PI, i, j);
	else if (info->map[i][j] == 'E')
		init_player(info, 0, i, j);
	else
		info->map[i][j] = -1;
}

static void	convert_map(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		while (++j < info->map_width)
			convert_process(info, i, j);
	}
}

void		init_map(t_info *info, t_ps *ps, char *filename)
{
	info->tile_width = info->win_width / info->map_width;
	info->tile_height = info->win_height / info->map_height;
	ps->fd = open(filename, O_RDONLY);
	if (!(info->map = (char **)malloc(sizeof(char *) * info->map_height)))
		error_exit(1);
	ft_memset(info->map, 0, sizeof(char *) * info->map_height);
	while (get_next_line(ps->fd, &ps->line) || ft_strlen(ps->line))
	{
		if (ps->map_start <= 0)
		{
			if (!(info->map[-ps->map_start] =
			(char *)malloc(info->map_width + 1)))
				error_exit(1);
			ft_memset(info->map[-ps->map_start], 0, info->map_width + 1);
			char_check(ps->line);
			ft_strlcpy(info->map[-ps->map_start],
			ps->line, info->map_width + 1);
		}
		ps->map_start--;
		free(ps->line);
	}
	free(ps->line);
	convert_map(info);
	wall_check(info);
}
