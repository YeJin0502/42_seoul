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
	rc->bar_height = (info->tile_height + info->tile_width) / 2 * rc->projection_dist / rc->corrected_ray_dist; // 임시로 tile 높이 사용. 뭐 써야할라나..? // int로 하면 빨라지지 않을까?
    rc->bar_start = (info->win_height / 2) - (rc->bar_height / 2);
    if (rc->bar_start < 0)
        rc->bar_start = 0;
	rc->bar_end = (info->win_height / 2) + (rc->bar_height / 2);
    if (rc->bar_end < 0)
        rc->bar_end = info->win_height - 1;
}

static t_img *select_img(t_info *info, t_rc *rc)
{
    t_img *img;

    if (rc->tile_hit_dir == 1)
        img = info->no;
    else if (rc->tile_hit_dir == 2)
        img = info->ea;
    else if (rc->tile_hit_dir == 3)
        img = info->so;
    else
        img = info->we; // 맞나? 순서 헷갈리네. 나중에 확인
    return (img);
}

static int pixel_color(t_img *img, int x, int y)
{
    int b_i;
    int g_i;
    int r_i;
	int color;

    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    b_i = (int)img->image_data[x * 4 + img->size_line * y];
    g_i = (int)img->image_data[x * 4 + img->size_line * y + 1]; // 괄호 안해줘도 되려나?
    r_i = (int)img->image_data[x * 4 + img->size_line * y + 2];
	color = 0x000000;
	color += b_i;
	color += 16 * 16 * g_i;
	color += 16 * 16 * 16 * 16 * r_i;
	return (color);
}

void render(t_info *info, t_rc *rc, int i)
{
    t_img *img;
	int j;
    int color;

	calculate_bar(info, rc);
    img = select_img(info, rc);
    if (rc->tile_hit_dir == (1 || 3))
        rc->image_x = rc->tile_x * img->width / info->tile_width + 0.000001;
    else
        rc->image_x = rc->tile_x * img->width / info->tile_height + 0.000001;
    rc->image_y = 0;
    j = rc->bar_start - 1;
    while (++j < rc->bar_end)
    {
        color = pixel_color(info->no, (int)rc->image_x, (int)rc->image_y);
        mlx_pixel_put(info->mlx, info->win, i, j, color);
        rc->image_y += (double)img->height / rc->bar_height + 0.000001;
    }
}
