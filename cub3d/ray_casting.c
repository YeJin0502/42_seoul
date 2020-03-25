/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 04:56:24 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 06:18:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

		int is_ray_down;
		int is_ray_up;
		int is_ray_right;
		int is_ray_left;
		is_ray_down = (rc->ray_angle > 0 && rc->ray_angle < PI); // 이런거도 1, 0 반환함! 신기. 
		is_ray_up = !is_ray_down; // 이거도 신기하네. 공부 필요.
		is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
		is_ray_right = !is_ray_left;
		
		double x_intercept;
		double y_intercept;
		double x_step;
		double y_step;

		t_intersection horz;
		t_intersection vert;
		
		// horz
		horz.is_wall_hit = 0;
		horz.hit_point_x = 0;
		horz.hit_point_y = 0;

		y_intercept = floor(info->y / info->tile_height) * info->tile_height;	
		y_intercept += (is_ray_down) ? info->tile_height : 0;
		x_intercept = info->x + (y_intercept - info->y) / tan(rc->ray_angle);
		
		y_step = info->tile_height;
		y_step = (is_ray_up) ? -1 : 1;

		x_step = info->tile_height / tan(rc->ray_angle);
		x_step *= (is_ray_left && x_step > 0) ? -1 : 1; // 특히 이해 안됨!
		x_step *= (is_ray_right && x_step < 0) ? -1 : 1;

		horz.next_touch_x = x_intercept;
		horz.next_touch_y = y_intercept;

		if (is_ray_up)
			horz.next_touch_y--; // 특히 이해안됨.

		// 작성중...

		
		// 2D 렌더링 (테스트 용)
		// p2.x = info->x + cos(rc->ray_angle) * 30;
		// p2.y = info->y + sin(rc->ray_angle) * 30;
		draw_line(p1, p2, info);
		
		rc->ray_angle += FOV / info->R_width;
	}
}
