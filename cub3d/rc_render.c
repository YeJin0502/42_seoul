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

static void calculate_bar(t_info *info, t_rc *rc)
{
    rc->corrected_ray_dist = rc->ray_dist * cos(info->view_angle - rc->ray_angle);
    rc->projection_dist = info->win_width / (2 * tan(FOV / 2));
    rc->bar_height = (info->tile_height + info->tile_width) / 2
                    * rc->projection_dist / rc->corrected_ray_dist; // 임시로 tile 높이 사용. 뭐 써야할라나..?
    rc->bar_start = (info->win_height / 2) - (rc->bar_height / 2);
    rc->bar_end = (info->win_height / 2) + (rc->bar_height / 2);
}

static t_img *select_img(t_info *info, t_rc *rc)
{
    t_img *wall_img;

    if (rc->tile_hit_dir == 1)
        wall_img = info->no;
    else if (rc->tile_hit_dir == 2)
        wall_img = info->ea;
    else if (rc->tile_hit_dir == 3)
        wall_img = info->so;
    else
        wall_img = info->we; // 맞나? 순서 헷갈리네. 나중에 확인
    return (wall_img);
}

static int get_color(t_img *img, int x, int y)
{
    int b;
    int g;
    int r;
    int color;

    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    b = (int)img->image_data[x * 4 + img->size_line * y];
    g = (int)img->image_data[x * 4 + img->size_line * y + 1];
    r = (int)img->image_data[x * 4 + img->size_line * y + 2];
    color = 0x000000;
    color += b;
    color += 16 * 16 * g;
    color += 16 * 16 * 16 * 16 * r;
    return (color);
}

void change_color(t_img *img, int x, int y, int color) // void로 해도 바뀔라나?
{
    int r;
    int g;
    int b;

    r = (int)((double)color / (16 * 16 * 16 * 16)); // 맞나..?
    color = color % (16 * 16 * 16 * 16);
    g = (int)((double)color / (16 * 16));
    b = color % (16 * 16); // 맞아..?

    // printf("(%d,%d,%d) <%d,%d,%d>\n", r, g, b, x * 4 + img->size_line * y, x * 4 + img->size_line * y + 1, x * 4 + img->size_line * y + 2);
    img->image_data[x * 4 + img->size_line * y] = b; // 되나? 바뀌나??
    img->image_data[x * 4 + img->size_line * y + 1] = g;
    img->image_data[x * 4 + img->size_line * y + 2] = r;
}

void render(t_info *info, t_rc *rc, int i)
{
    t_img *wall_img;
    int j;
    int color;

    calculate_bar(info, rc);
    wall_img = select_img(info, rc);
    // if (rc->tile_hit_dir == (1 || 3)) // 이거 안되고 있었는데 문제를 못느꼈네.. 뭐지?
    if (rc->tile_hit_dir == 1 || rc->tile_hit_dir == 3)
        rc->image_x = rc->tile_x * wall_img->width / info->tile_width + 0.000001;
    else
        rc->image_x = rc->tile_x * wall_img->width / info->tile_height + 0.000001;
    rc->image_y = 0;
    j = rc->bar_start - 1;
    while (++j < rc->bar_end)
    {
        if ((int)rc->image_y >= 0 && (int)rc->image_y <= wall_img->height - 1 &&
            0 <= j && j <= info->win_height)
        {
            color = get_color(wall_img, (int)rc->image_x, (int)rc->image_y);
            change_color(info->scene, i, j, color);
            // printf("color:%d, i:%d, j:%d\n", color,i ,j);
            // break;
            // mlx_pixel_put(info->mlx, info->win, i, j, color);
        }
        rc->image_y += (double)wall_img->height / rc->bar_height + 0.000001;
    }
}
