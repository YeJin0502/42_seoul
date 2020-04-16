/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 21:19:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 21:19:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_dup_item(double item_x, double item_y, t_item **item, int item_count)
{
	int i;

	i = 0;
	while (i < item_count && item[i])
	{
		if ((int)item[i]->x == (int)item_x && (int)item[i]->y == (int)item_y)
			return (1);
		i++;
	}
	return (0);
}

static void	init_item(int map_x, int map_y, t_info *info, t_rc *rc)
{
	rc->item_x = (map_x + 0.5) * info->tile_width;
	rc->item_y = (map_y + 0.5) * info->tile_height;
	if (is_dup_item(rc->item_x, rc->item_y, rc->item, info->item_count) == 0)
	{
		(rc->item)[rc->i_item]->x = rc->item_x;
		(rc->item)[rc->i_item]->y = rc->item_y;
		(rc->item)[rc->i_item]->ray_dist = distance(info->x, info->y,
										(map_x + 0.5) * info->tile_width,
										(map_y + 0.5) * info->tile_height);
		rc->i_item++;
	}
}

int			is_wall(double intersection_x, double intersection_y, t_info *info, t_rc *rc)
{
	int map_x;
	int map_y;

	if (intersection_x < 0 || intersection_x > info->win_width ||
		intersection_y < 0 || intersection_y > info->win_height)
		return (1);
	map_x = intersection_x / info->tile_width + 0.00000001;
	map_y = intersection_y / info->tile_height + 0.00000001;
	if (map_x < 0 || map_x >= info->map_width || map_y < 0 || map_y >= info->map_height)
		return (1);
	else if (info->map[map_y][map_x] == 1)
		return (1);
	else if (info->map[map_y][map_x] == 2)
	{
		if (rc && rc->item)
			init_item(map_x, map_y, info, rc);
		return (2);
	}
	return (0);
}
