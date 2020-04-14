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
    {
        if (rc->is_item == 0 && rc->item_i_start)
            rc->was_item = 1;
        return (1);
    }
    else if (info->map[map_y][map_x] == 1)
    {
        if (rc->is_item == 0 && rc->item_i_start)
            rc->was_item = 1;
        return (1);
    }
    else if (info->map[map_y][map_x] == 2)
    {
        // printf("%d,%d\n", map_x, map_y);
        rc->is_item = 1;
        rc->items->item_x = (map_x + 0.5) * info->tile_width;
        rc->items->item_y = (map_y + 0.5) * info->tile_height;
        // return (2);
    }
    // else
        // rc->is_item = 0;
    return (0);
}
