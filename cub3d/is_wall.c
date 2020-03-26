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
	if (intersection_x < 0 || intersection_x > info->R_width ||
		intersection_y < 0 || intersection_y > info->R_height)
		return (1);
	map_x = (int)floor(intersection_x / info->tile_width + 0.000001); // 아 이거 오차 어떻게 수정하냐
	map_y = (int)floor(intersection_y / info->tile_height + 0.000001);
    // printf("(%.10f,%.10f) [%d,%d] %.10f\n", intersection_x, intersection_y, map_y, map_x, info->tile_width); /////
	if (info->map[map_y][map_x] != 0)
		return (1);
	return (0);
}
