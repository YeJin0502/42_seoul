/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 04:56:24 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 04:05:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void find_intersection(t_info *info, t_fd *horz)
{
	while (horz->intersection_x >= 0 && horz->intersection_x <= info->R_width &&
			horz->intersection_y >= 0 && horz->intersection_y <= info->R_height)
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

t_fd *find_horz_dist(t_info *info, t_rc *rc)
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
}

t_fd *find_vert_dist(t_info *info, t_rc *rc)
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
	}
	else
	{
		rc->intersection_x = horz->intersection_x;
		rc->intersection_y = horz->intersection_y;
		rc->ray_dist = horz->ray_dist;
	}
	free(horz);
	free(vert); // 되나?
}

void ray_casting(t_info *info, t_rc *rc)
{
	// 2d 렌더링 (테스트 용)
	t_pair p1;
	t_pair p2;
	p1.x = info->x;
	p1.y = info->y;

	rc->move_dist = rc->move_dir * MOVE_SPEED;
	info->view_angle += rc->rotation_dir * ROTATION_SPEED;
	info->x += cos(info->view_angle) * rc->move_dist;
	info->y += sin(info->view_angle) * rc->move_dist;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	int i = -1;
	while (++i < info->R_width)
	{
		rc->ray_angle = norm_angle(rc->ray_angle);
		rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
		rc->is_ray_up = !(rc->is_ray_down);
		rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
		rc->is_ray_right = !(rc->is_ray_left);

		find_ray_dist(info, rc);

		

		// 2D 렌더링 (테스트 용)
		// p2.x = info->x + cos(rc->ray_angle) * 30;
		// p2.y = info->y + sin(rc->ray_angle) * 30;
		// printf("(%f,%f) %f\n", rc->intersection_x, rc->intersection_y, rc->ray_dist);
		// printf("view: %f / ray: %f\n", info->view_angle * 180 / PI, rc->ray_angle * 180 / PI);
		p2.x = (int)rc->intersection_x;
		p2.y = (int)rc->intersection_y;
		draw_line(p1, p2, info);
		
		rc->ray_angle += FOV / info->R_width;
	}
}
