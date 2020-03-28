/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 03:13:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_rc_key(t_rc *rc, int keycode)
{
    rc->keycode = keycode; // 옆으로 이동할때 필요할 것 같아서 추가.
    rc->move_dir = 0;  // 이런걸 release 함수가 대신하나? 도대체 release 함수는 언제 쓰는거지?
    rc->rotation_dir = 0; // 원하는 키 아닐때는 루프 안돌게 하는건가? 지금은 다른 키 눌러도 업데이트됨.
    printf("%d\n", keycode);
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
    else if (keycode == KEY_D)
    {
        rc->move_dir = 1;
        rc->rotation_dir = 0;
    }
    else if (keycode == KEY_A)
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
    double  new_x;
    double  new_y;

    rc->move_dist = rc->move_dir * MOVE_SPEED;
    info->view_angle += rc->rotation_dir * ROTATION_SPEED;
    if (rc->keycode == KEY_W || rc->keycode == KEY_S)
    {
        new_x = info->x + cos(info->view_angle) * rc->move_dist;
        new_y = info->y + sin(info->view_angle) * rc->move_dist;
    }
    else if (rc->keycode == KEY_A || rc->keycode == KEY_D)
    {
        new_x = info->x - sin(info->view_angle) * rc->move_dist;
        new_y = info->y + cos(info->view_angle) * rc->move_dist;
    }
    if (is_wall(new_x, new_y, info) == 0)
    {
        info->x = new_x;
        info->y = new_y;
        rc->is_move = 1;
    }
    else
        rc->is_move = 0;
}

int key_hook(int keycode, void *param) // 작명을 나중에 mainloop같은 걸로 바꾸면 되지 않을까? 키만 받는거도 아니고.
{
    t_info  *info;
    t_rc    *rc;

    info = (t_info *)param;
    if (keycode == KEY_ESC)
    {
        // free(info->no->image); // 맞나?
        // free(info->no->image_data);
        // free(info->no); // 너무 많은데...
        // free(info); // 함수 만들어줘야 할듯.
        // mlx_destroy_window(info->mlx, info->win);
        // 으악 free들은 내일하자
        exit(1);
    }
    rc = (t_rc *)malloc(sizeof(t_rc));
    init_rc_key(rc, keycode);

    // 테스트용
	// int i;
	// int j;
	// int a;
	// int b;
	// i = -1;
	// while (++i < info->map_width)
	// {
	// 	j = -1;
	// 	while (++j < info->map_height)
	// 		if (info->map[j][i] != 0)
	// 		{
	// 			a = -1;
	// 			while (++a < info->tile_height)
	// 			{
	// 				b = -1;
	// 				while (++b < info->tile_width)
	// 					mlx_pixel_put(info->mlx, info->win, i * info->tile_width + b,
	// 								j * info->tile_height + a, 0xFFFFFF);
	// 			}
	// 		}
	// }

    move_and_rotate(info, rc);
    if (rc->is_move == 1 || rc->rotation_dir != 0)
    {
        mlx_clear_window(info->mlx, info->win);
        raycast(info, rc);
    }
    free(rc);
    rc = 0; // 댕글링 포인터
    return (0);
}
