/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/17 01:32:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dir(int move_dir, int rotation_dir, t_rc *rc)
{
	rc->move_dir = move_dir;
	rc->rotation_dir = rotation_dir;
}

static void	init_keycode(t_rc *rc, int keycode)
{
	rc->keycode = keycode;
	rc->move_dir = 0;
	rc->rotation_dir = 0;
	if (keycode == KEY_W)
		init_dir(1, 0, rc);
	else if (keycode == KEY_S)
		init_dir(-1, 0, rc);
	else if (keycode == KEY_D)
		init_dir(1, 0, rc);
	else if (keycode == KEY_A)
		init_dir(-1, 0, rc);
	else if (keycode == KEY_RIGHT)
		init_dir(0, 1, rc);
	else if (keycode == KEY_LEFT)
		init_dir(0, -1, rc);
}

static void	move_and_rotate(t_info *info, t_rc *rc)
{
	double move_dist;
	double new_x;
	double new_y;

	move_dist = rc->move_dir * MOVE_SPEED;
	info->view_angle += rc->rotation_dir * ROTATION_SPEED;
	new_x = info->x;
	new_y = info->y;
	if (rc->keycode == KEY_W || rc->keycode == KEY_S)
	{
		new_x += cos(info->view_angle) * move_dist;
		new_y += sin(info->view_angle) * move_dist;
	}
	else if (rc->keycode == KEY_A || rc->keycode == KEY_D)
	{
		new_x += -sin(info->view_angle) * move_dist;
		new_y += cos(info->view_angle) * move_dist;
	}
	if (is_wall(new_x, new_y, info, rc) != 1)
	{
		info->x = new_x;
		info->y = new_y;
		rc->is_move = 1;
	}
}

int			key_hook(int keycode, void *param)
{
	t_info	*info;
	t_rc	*rc;

	info = (t_info *)param;
	if (keycode == KEY_ESC)
		exit(0);
	rc = (t_rc *)malloc(sizeof(t_rc));
	ft_memset(rc, 0, sizeof(t_rc));
	init_keycode(rc, keycode);
	move_and_rotate(info, rc);
	if (rc->is_move == 1 || rc->rotation_dir != 0)
		raycast(info, rc);
	free(rc);
	rc = 0;
	return (0);
}

int			press_x_button(void *param)
{
	if (param != 0)
		exit(1);
	exit(0);
}
