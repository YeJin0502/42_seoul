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

int is_wall(double intersection_x, double intersection_y, t_info *info)
{
    int map_x;
    int map_y;
    if (intersection_x < 0 || intersection_x > info->win_width ||
        intersection_y < 0 || intersection_y > info->win_height)
        return (1);
    map_x = intersection_x / info->tile_width + 0.00000001; // 아 이거 오차 어떻게 수정하냐
    map_y = intersection_y / info->tile_height + 0.00000001; // floor 안써도 바로 되지 않나?
    // printf("(%d, %d) (%f, %f)\n", map_x, map_y, intersection_x / info->tile_width, intersection_y / info->tile_height);
    // printf("(%d,%d) %d\n", map_x, map_y, info->map[map_y][map_x]);
    if (map_x < 0 || map_x >= info->map_width || map_y < 0 || map_y >= info->map_height)
        return (1);
    else if (info->map[map_y][map_x] == 1)
        return (1);
    else if (info->map[map_y][map_x] == 2) // && (fmod(intersection_y, info->tile_height) < 1)) // 너무 야맨데..?
        return (2);
    return (0);
}
