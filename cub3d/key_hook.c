/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:42:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 07:37:42 by gmoon            ###   ########.fr       */
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



void free_all(t_info *info, t_rc *rc)
{
    // free(info->f); // 전역변수가 아니면 malloc 하지않을까...? 헷갈리네. 애초에 *f가 아니라 f[3]? malloc 안써도 방법이 있나?
    // free(info->c); // 지역변수를 너무 안쓰다보니...
    mlx_destroy_image(info->mlx, info->no->image); // 이게 무슨 기능이지..? free의 기능인건가? image_data는 free를 안해도 되나?
    mlx_destroy_image(info->mlx, info->so->image); // free를 따로 해줘야하는것인가..? free의 기능이 없다면
    mlx_destroy_image(info->mlx, info->we->image); // destroy window는 창을 끄는거라고 쳐도, destroy image는 도대체 뭐여?
    mlx_destroy_image(info->mlx, info->ea->image);
    mlx_destroy_image(info->mlx, info->scene->image);
    // free(info->f);
    // free(info->c);
    // int i;
    // i = -1;
    // while (++i < info->map_height) // 아 이거 항상 헷갈리네
    //     free(info->map[i]);
    // free(info->map);
    mlx_destroy_window(info->mlx, info->win);
    free(info->win);
    free(info->mlx);
}

int key_hook(int keycode, void *param) // 작명을 나중에 mainloop같은 걸로 바꾸면 되지 않을까? 키만 받는거도 아니고.
{
    t_info  *info;
    t_rc    *rc;

    info = (t_info *)param;
    rc = (t_rc *)malloc(sizeof(t_rc));
    ft_memset(rc, 0, sizeof(rc)); // 널포인터는 프리해줄수 있나? 있으면 rc 위로 올리면 되지 않나?
    if (keycode == KEY_ESC) // 0
    {
        free_all(info, rc);
        exit(1);
    }
    init_rc_key(rc, keycode);
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
