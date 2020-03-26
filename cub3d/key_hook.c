/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 07:23:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_rc_key(t_rc *rc, int keycode)
{
	rc->keycode = keycode; // 옆으로 이동할때 필요할 것 같아서 추가.
	rc->move_dir = 0;  // 이런걸 release 함수가 대신하나? 도대체 release 함수는 언제 쓰는거지?
	rc->rotation_dir = 0; // 원하는 키 아닐때는 루프 안돌게 하는건가? 지금은 다른 키 눌러도 업데이트됨.
	if (keycode == KEY_W) // 참고로 dir 두개 초기화 안해주면 다른 키 눌렀을때 오류 발생.
	{
		rc->move_dir = 1;
		rc->rotation_dir = 0;
	}
	else if (keycode == KEY_S)
	{
		rc->move_dir = -1;
		rc->rotation_dir = 0;
	}
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
}

static void move_and_rotate(t_info *info, t_rc *rc)
{
	double new_x;
	double new_y;
	int map_new_x;
	int map_new_y;

	rc->move_dist = rc->move_dir * MOVE_SPEED;
	info->view_angle += rc->rotation_dir * ROTATION_SPEED;
	new_x = info->x + cos(info->view_angle) * rc->move_dist;
	new_y = info->y + sin(info->view_angle) * rc->move_dist;
	if (is_wall(new_x, new_y, info) == 0)
	{
		info->x = new_x;
		info->y = new_y;
	}
}

int key_hook(int keycode, void *param)
{
	t_info *info;
	t_rc *rc;

	info = (t_info *)param;
	rc = (t_rc *)malloc(sizeof(t_rc));
	init_rc_key(rc, keycode);
	mlx_clear_window(info->mlx, info->win);
	move_and_rotate(info, rc);
	raycast(info, rc);
	return (0);
}
