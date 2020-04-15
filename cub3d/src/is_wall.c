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

int is_wall(double intersection_x, double intersection_y, t_info *info, t_rc *rc)
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
		if (rc)
		{
			// rc->is_item = 1;
			rc->item_x = (map_x + 0.5) * info->tile_width;
			rc->item_y = (map_y + 0.5) * info->tile_height;
			// printf("%f, %f, %f, %f\n", info->x, info->y,
			// 							(map_x + 0.5) * info->tile_width,
			// 							(map_y + 0.5) * info->tile_height);
			rc->item_ray_dist = distance(info->x, info->y,
										(map_x + 0.5) * info->tile_width,
										(map_y + 0.5) * info->tile_height);
		}
		return (2);
	}
	return (0);
}
