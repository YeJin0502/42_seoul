/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 04:21:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cast_ray(t_info *info)
{
	double ray;

}

int key_hook(int keycode, void *param)
{
	// 2d 렌더링
	t_pair p1;
	t_pair p2;

	t_info *info;
	int move_dir;
	int rotation_dir;
	double ray_angle;
	int i;

	// 2d 렌더링
	p1.x = info->x;
	p1.y = info->y;

	info = (t_info *)param;
	move_dir = 0;
	rotation_dir = 0;
	if (keycode == KEY_W)
	{
		move_dir = 1;
		rotation_dir = 0;
	}
	else if (keycode == KEY_S)
	{
		move_dir = -1;
		rotation_dir = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		move_dir = 0;
		rotation_dir = 1;
	}
	else if (keycode == KEY_LEFT)
	{
		move_dir = 0;
		rotation_dir = -1;
	}

	mlx_clear_window(info->mlx, info->win);

	// 2d 렌더링
	make_2d_map(info);

	double rotation_speed; // 구조체 위치를 생각해봐야 할듯. !!!
	double move_speed; // 첫 화면 세팅하면서 구조체를 만든다?
	double move_dist;

	rotation_speed = 2 * PI / 180;
	move_speed = 2;
	move_dist = move_dir * move_speed;
	info->view_angle += rotation_dir * rotation_speed;
	info->x += cos(info->view_angle) * move_dist;
	info->y += sin(info->view_angle) * move_dist;

	ray_angle = info->view_angle - (FOV / 2.0);
	i = -1;
	while (++i < info->R_width)
	{
		// 2D 렌더링
		p2.x = info->x + cos(ray_angle) * 30;
		p2.y = info->y + sin(ray_angle) * 30;
		draw_line(p1, p2, info);
		
		ray_angle += FOV / info->R_width;
	}
}