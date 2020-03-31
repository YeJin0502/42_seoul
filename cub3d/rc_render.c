/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 01:27:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 01:27:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img *select_img(t_info *info, t_rc *rc)
{
    t_img *wall_img;

    // if (rc->is_item_hit == 1)
    //     wall_img = info->s;
    if (rc->tile_hit_dir == 1)
        wall_img = info->no;
    else if (rc->tile_hit_dir == 2)
        wall_img = info->ea;
    else if (rc->tile_hit_dir == 3)
        wall_img = info->so;
    else
        wall_img = info->we;
    return (wall_img);
}

static void init_for_render(t_info *info, t_rc *rc)
{
    rc->ray_dist *= cos(info->view_angle - rc->ray_angle);
    rc->projection_dist = info->win_width / (2 * tan(FOV / 2));
    rc->bar_height = (info->tile_height + info->tile_width) / 2
                     * rc->projection_dist / rc->ray_dist; // 임시로 tile 높이 사용. 뭐 써야할라나..?
    rc->bar_start = (info->win_height / 2) - (rc->bar_height / 2);
    rc->bar_end = (info->win_height / 2) + (rc->bar_height / 2);
    rc->wall_img = select_img(info, rc);
    if (rc->tile_hit_dir == 1 || rc->tile_hit_dir == 3)
        rc->wall_image_x = rc->tile_x * rc->wall_img->width / info->tile_width + 0.000001;
    else
        rc->wall_image_x = rc->tile_x * rc->wall_img->width / info->tile_height + 0.000001;
    rc->wall_image_y = 0;
    // printf("(%f / %f)\n", rc->item_tile_x, rc->item_ray_dist);
    rc->item_ray_dist *= cos(info->view_angle - rc->ray_angle);
    rc->item_bar_height = (info->tile_height + info->tile_width) / 2
                     * rc->projection_dist / rc->item_ray_dist;
    rc->item_bar_start = (info->win_height / 2) - (rc->item_bar_height / 2);
    rc->item_bar_end = (info->win_height / 2) + (rc->item_bar_height / 2);
    rc->item_image_x = rc->item_tile_x * info->s->width / info->tile_width + 0.000001;
    rc->item_image_y = 0;
}

void render(t_info *info, t_rc *rc, int i)
{
    int j;
    int color;

    init_for_render(info, rc);
    // printf("%d, %d, %d, %d\n", info->s->image_data[0], info->s->image_data[1], info->s->image_data[2], info->s->image_data[3]);
    // 아이템하고 벽 힛포인트를 다 저장해놓고, 아이템 색이 0이면 힛포인트 색을 저장하는 식으로 해야할 듯?
    j = -1;
    while (++j < rc->bar_start)
    {
        color = make_color(info->c[0], info->c[1], info->c[2]);
        change_color(info->scene, i, j, color);
    }
    j = rc->bar_start - 1;
    while (++j < rc->bar_end)
    {
        if (0 <= j && j <= info->win_height)
        {
            color = get_color(rc->wall_img, (int)rc->wall_image_x, (int)rc->wall_image_y);
            change_color(info->scene, i, j, color);
        }
        rc->wall_image_y += (double)rc->wall_img->height / rc->bar_height + 0.000001;
    }
    while (++j < info->win_height)
    {
        color = make_color(info->f[0], info->f[1], info->f[2]);
        change_color(info->scene, i, j, color);
    }
    j = rc->item_bar_start - 1;
    if (rc->item_tile_x)
    while (++j < rc->item_bar_end)
    {
        if (0 <= j && j <= info->win_height)
        {
            color = get_color(info->s, (int)rc->item_image_x, (int)rc->item_image_y);
            if (color)
                change_color(info->scene, i, j, color);
        }
        rc->item_image_y += (double)info->s->height / rc->item_bar_height + 0.000001;
    }
}
