/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 08:21:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_dir(int move_dir, int rotation_dir, t_rc *rc)
{
    rc->move_dir = move_dir;
    rc->rotation_dir = rotation_dir;
}

static void init_keycode(t_rc *rc, int keycode)
{
    rc->keycode = keycode;
    rc->move_dir = 0;  // 이런걸 release 함수가 대신하나? 도대체 release 함수는 언제 쓰는거지?
    rc->rotation_dir = 0; // 원하는 키 아닐때는 루프 안돌게 하는건가? 지금은 다른 키 눌러도 업데이트됨.
    printf("%d\n", keycode);
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
    else
    {
        new_x = info->x;
        new_y = info->y;
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

void free_info(t_info *info)
{
    int i;

    i = -1;
    while (++i < info->map_height)
        free(info->map[i]);
    free(info->map);
    mlx_destroy_image(info->mlx, info->no->image);
    mlx_destroy_image(info->mlx, info->so->image);
    mlx_destroy_image(info->mlx, info->we->image);
    mlx_destroy_image(info->mlx, info->ea->image);
    mlx_destroy_image(info->mlx, info->scene->image);
    mlx_destroy_window(info->mlx, info->win);
    free(info->no);
    free(info->so);
    free(info->we);
    free(info->ea);
    free(info->s);
    free(info->scene);
    free(info->mlx);
    free(info);
}

int key_hook(int keycode, void *param)
{
    t_info  *info;
    t_rc    *rc;

    info = (t_info *)param;
    if (keycode == KEY_ESC)
    {
        free_info(info);
        exit(1); // 이렇게 끝내면 still reachable인데... 여기서 still reachable은 어떻게 해석해야하지?
    }
    rc = (t_rc *)malloc(sizeof(t_rc));
    ft_memset(rc, 0, sizeof(rc));
    init_keycode(rc, keycode);
    move_and_rotate(info, rc);
    if (rc->is_move == 1 || rc->rotation_dir != 0)
    {
        mlx_clear_window(info->mlx, info->win);
        raycast(info, rc);
    }
    free(rc);
    return (0);
}
