/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 04:56:24 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 20:21:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_wall(t_info *info, t_rc *rc, t_fh horz)
{
	int map_x;
	int map_y;
	if (horz.intersection_x < 0 || horz.intersection_x > info->R_width ||
		horz.intersection_y < 0 || horz.intersection_y > info->R_height)
		return (1); // 맞나?
	map_x = (int)floor(horz.intersection_x / info->tile_width);
	map_y = (int)floor(horz.intersection_y / info->tile_height);
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
		if (rc->is_ray_left && horz.dx > 0) // 음수여야 하는데 양수라 음수로.
			horz.dx *= -1;
		else if (rc->is_ray_right && horz.dx < 0) // 양수여야 하는데 음수라 양수로.
			horz.dx *= -1;

		if (rc->is_ray_up)
			horz.intersection_y--;
		
		while (horz.intersection_x >= 0 && horz.intersection_x <= info->R_width &&
				horz.intersection_y >= 0 && horz.intersection_y <= info->R_height) // 함수 뺄 필요 있음.
		{
			if (is_wall(info, rc, horz)) // 이렇게 해야되나? // 해야하는듯. 왜냐하면 평행해서 안만나는 경우 있어서!!!
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
			horz.ray_dist = distance(info->x, horz.intersection_x, info->y, horz.intersection_y);
		else
			horz.ray_dist = 100000000; // 선택되지 않기 위해 큰 값. max 값으로 교체해야 할듯... 몇인지 몰라.

		// vert




		p2.x = (int)horz.intersection_x;
		p2.y = (int)horz.intersection_y;
		
		printf("(%f,%f) %f\n", (double)p2.x, (double)p2.y, rc->ray_angle *180 /PI);
		// 2D 렌더링 (테스트 용)
		// p2.x = info->x + cos(rc->ray_angle) * 30;
		// p2.y = info->y + sin(rc->ray_angle) * 30;
		draw_line(p1, p2, info);
		
		rc->ray_angle += FOV / info->R_width;
	}
}
