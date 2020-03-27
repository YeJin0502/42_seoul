/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 04:53:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 04:53:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void find_intersection(t_info *info, t_fd *horz)
{
	while (horz->intersection_x >= 0 && horz->intersection_x <= info->win_width &&
			horz->intersection_y >= 0 && horz->intersection_y <= info->win_height)
	{
		if (is_wall(horz->intersection_x, horz->intersection_y, info))
		{
			horz->is_wall_hit = 1;
			break;
		}
		horz->intersection_x += horz->dx;
		horz->intersection_y += horz->dy;
	}
}

static t_fd *find_horz_dist(t_info *info, t_rc *rc)
{
	t_fd *horz;

	horz = (t_fd *)malloc(sizeof(t_fd));
	horz->intersection_y = floor(info->y / info->tile_height) * info->tile_height;
	horz->intersection_y += (rc->is_ray_down) ? info->tile_height : 0;
	horz->intersection_x = info->x + (horz->intersection_y - info->y) / tan(rc->ray_angle);
	horz->dy = info->tile_height;
	horz->dy *= (rc->is_ray_up) ? -1 : 1;
	horz->dx = info->tile_height / tan(rc->ray_angle);
	if ((rc->is_ray_left && horz->dx > 0) || (rc->is_ray_right && horz->dx < 0))
		horz->dx *= -1;
	horz->intersection_y += (rc->is_ray_up) ? -1 : 0;
	find_intersection(info, horz);
	if (horz->is_wall_hit)
		horz->ray_dist = distance(info->x, info->y, horz->intersection_x, horz->intersection_y);
	else
		horz->ray_dist = 100000000; // 선택되지 않기 위해 큰 값. max 값으로 교체해야 할듯... 몇인지 몰라.
	if (rc->is_ray_up)
		horz->tile_x = fmod(horz->intersection_x, info->tile_width); // 맞을까?
	else
		horz->tile_x = info->tile_width - fmod(horz->intersection_x, info->tile_width);
}

static t_fd *find_vert_dist(t_info *info, t_rc *rc)
{
	t_fd *vert;

	vert = (t_fd *)malloc(sizeof(t_fd));
	vert->intersection_x = floor(info->x / info->tile_width) * info->tile_width;
	vert->intersection_x += (rc->is_ray_right) ? info->tile_width : 0;
	vert->intersection_y = info->y + (vert->intersection_x - info->x) * tan(rc->ray_angle);
	vert->dx = info->tile_width;
	vert->dx *= (rc->is_ray_left) ? -1 : 1;
	vert->dy = info->tile_width * tan(rc->ray_angle);
	if ((rc->is_ray_down && vert->dy < 0) || (rc->is_ray_up && vert->dy > 0))
		vert->dy *= -1;
	vert->intersection_x += (rc->is_ray_left) ? -1 : 0;
	find_intersection(info, vert);
	if (vert->is_wall_hit)
		vert->ray_dist = distance(info->x, info->y, vert->intersection_x, vert->intersection_y);
	else
		vert->ray_dist = 100000000;
	if (rc->is_ray_right)
		vert->tile_x = fmod(vert->intersection_y, info->tile_height); // 맞을까?
	else
		vert->tile_x = info->tile_height - fmod(vert->intersection_y, info->tile_height);
}

void find_ray_dist(t_info *info, t_rc *rc)
{
	t_fd *horz;
	t_fd *vert;

	horz = find_horz_dist(info, rc);
	vert = find_vert_dist(info, rc);
	if (vert->ray_dist < horz->ray_dist)
	{
		rc->intersection_x = vert->intersection_x;
		rc->intersection_y = vert->intersection_y;
		rc->ray_dist = vert->ray_dist;
		rc->tile_x = vert->tile_x;
	}
	else
	{
		rc->intersection_x = horz->intersection_x;
		rc->intersection_y = horz->intersection_y;
		rc->ray_dist = horz->ray_dist;
		rc->tile_x = horz->tile_x;
	}
	free(horz);
	free(vert); // 되나?
}