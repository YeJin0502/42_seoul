/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 04:54:19 by gmoon            ###   ########.fr       */
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
	// if (rc->keycode == KEY_D || rc->keycode == KEY_A) // 아 옆으로 어떻게하지
	// {
	// 	info->x += sin(info->view_angle) * rc->move_dist;
	// 	info->y += cos(info->view_angle) * rc->move_dist;		
	// }
	// else
	// {
	// }
	info->x += cos(info->view_angle) * rc->move_dist;
	info->y += sin(info->view_angle) * rc->move_dist;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	int i = -1;
	while (++i < info->R_width)
	{
		// 2D 렌더링 (테스트 용)
		p2.x = info->x + cos(rc->ray_angle) * 30;
		p2.y = info->y + sin(rc->ray_angle) * 30;
		draw_line(p1, p2, info);
		
		rc->ray_angle += FOV / info->R_width;
	}
}

int key_hook(int keycode, void *param)
{
	t_info *info;
	t_rc *rc;

	info = (t_info *)param;
	rc = (t_rc *)malloc(sizeof(t_rc));
	rc->keycode = keycode;
	rc->move_dir = 0;  // 이런걸 release 함수가 대신하나? 도대체 release 함수는 언제 쓰는거지?
	rc->rotation_dir = 0; // 원하는 키 아닐때는 루프 안돌게 하는건가? 지금은 다른 키 눌러도 업데이트됨.
	if (keycode == KEY_W)
	{
		rc->move_dir = 1;
		rc->rotation_dir = 0;
	}
	else if (keycode == KEY_S)
	{
		rc->move_dir = -1;
		rc->rotation_dir = 0;
	}
	// else if (keycode == KEY_D)
	// {
	// 	rc->move_dir = -1; // 될까?
	// 	rc->rotation_dir = 0; // 잘 안됨ㅠㅠ 수정 필요
	// }
	// else if (keycode == KEY_A)
	// {
	// 	rc->move_dir = 1;
	// 	rc->rotation_dir = 0;
	// }
	else if (keycode == KEY_RIGHT)
	{
		rc->move_dir = 0;
		rc->rotation_dir = 1;
	}
	else if (keycode == KEY_LEFT)
	{
		rc->move_dir = 0;
		rc->rotation_dir = -1;
	}

	mlx_clear_window(info->mlx, info->win);

	// 2d 렌더링 (테스트 용)
	make_2d_map(info);

	ray_casting(info, rc);
	return (0);
}