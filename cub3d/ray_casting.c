/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 04:56:24 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 21:00:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_wall(double intersection_x, double intersection_y, t_info *info)
{
	int map_x;
	int map_y;
	if (intersection_x < 0 || intersection_x > info->R_width ||
		intersection_y < 0 || intersection_y > info->R_height)
		return (1); // 맞나?
	map_x = (int)floor(intersection_x / info->tile_width);
	map_y = (int)floor(intersection_y / info->tile_height);
	if (info->map[map_y][map_x] != 0)
		return (1);
	return (0);
}

double distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
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

		// horz
		t_fh horz;
		// 반복문에서 계속 지역변수로 만들었다, 없어졌다 하는게 나을까
		// 아니면 한번 malloc 하고 반복문 끝나면 지우는게 나을까
		horz.intersection_y = floor(info->y / info->tile_height) * info->tile_height;
		if (rc->is_ray_down)
			horz.intersection_y += info->tile_height;
		horz.intersection_x = info->x + (horz.intersection_y - info->y) / tan(rc->ray_angle);

		horz.dy = info->tile_height;
		if (rc->is_ray_up)
			horz.dy *= -1;
		horz.dx = info->tile_height / tan(rc->ray_angle);
		if ((rc->is_ray_left && horz.dx > 0) || (rc->is_ray_right && horz.dx < 0))
			horz.dx *= -1;

		if (rc->is_ray_up)
			horz.intersection_y--;
		
		while (horz.intersection_x >= 0 && horz.intersection_x <= info->R_width &&
				horz.intersection_y >= 0 && horz.intersection_y <= info->R_height) // 함수 뺄 필요 있음.
		{
			if (is_wall(horz.intersection_x, horz.intersection_y, info)) // 이렇게 해야되나? // 해야하는듯. 왜냐하면 평행해서 안만나는 경우 있어서!!!
			{
				horz.is_wall_hit = 1;
				break;
			}
			else
			{
				horz.intersection_x += horz.dx;
				horz.intersection_y += horz.dy;
			}
		}

		if (horz.is_wall_hit)
			horz.ray_dist = distance(info->x, info->y, horz.intersection_x, horz.intersection_y);
		else
			horz.ray_dist = 100000000; // 선택되지 않기 위해 큰 값. max 값으로 교체해야 할듯... 몇인지 몰라.

		// vert
		t_fh vert;

		vert.intersection_x = floor(info->x / info->tile_width) * info->tile_width;
		if (rc->is_ray_right)
			vert.intersection_x += info->tile_width;
		vert.intersection_y = info->y + (vert.intersection_x - info->x) * tan(rc->ray_angle);

		vert.dx = info->tile_width;
		if (rc->is_ray_left)
			vert.dx *= -1;
		vert.dy = info->tile_width * tan(rc->ray_angle);
		if ((rc->is_ray_down && vert.dy < 0) || (rc->is_ray_up && vert.dy > 0))
			vert.dy *= -1;
		
		if (rc->is_ray_left)
			vert.intersection_x--;

		while (vert.intersection_x >= 0 && vert.intersection_x <= info->R_width &&
				vert.intersection_y >= 0 && vert.intersection_y <= info->R_height)
		{
			if (is_wall(vert.intersection_x, vert.intersection_y, info) != 0)
			{
				vert.is_wall_hit = 1;
				break;
			}
			else
			{
				vert.intersection_x += vert.dx;
				vert.intersection_y += vert.dy;
			}
		}

		if (vert.is_wall_hit)
			vert.ray_dist = distance(info->x, info->y, vert.intersection_x, vert.intersection_y);
		else
			vert.ray_dist = 100000000;

		if (vert.ray_dist < horz.ray_dist)
		{
			rc->intersection_x = vert.intersection_x;
			rc->intersection_y = vert.intersection_y;
			rc->ray_dist = vert.ray_dist;
		}
		else
		{
			rc->intersection_x = horz.intersection_x;
			rc->intersection_y = horz.intersection_y;
			rc->ray_dist = horz.ray_dist;
		}

		p2.x = (int)rc->intersection_x;
		p2.y = (int)rc->intersection_y;
		
		// 2D 렌더링 (테스트 용)
		// p2.x = info->x + cos(rc->ray_angle) * 30;
		// p2.y = info->y + sin(rc->ray_angle) * 30;
		// printf("(%f,%f) %f\n", rc->intersection_x, rc->intersection_y, rc->ray_angle * 180 / PI);
		draw_line(p1, p2, info);
		
		rc->ray_angle += FOV / info->R_width;
	}
}
