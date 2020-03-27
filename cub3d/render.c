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

void render(t_info *info, t_rc *rc, int i) // 분리할수도
{
	int j;

	rc->corrected_ray_dist = rc->ray_dist * cos(info->view_angle - rc->ray_angle);
	rc->projection_dist = info->win_width / (2 * tan(FOV / 2));
	rc->projection_height = info->tile_height * rc->projection_dist / rc->corrected_ray_dist; // 임시로 tile 높이 사용. 뭐 써야할라나..?
    rc->projection_start = (info->win_height / 2) - (rc->projection_height / 2);
    if (rc->projection_start < 0)
        rc->projection_start = 0;
	rc->projection_end = (info->win_height / 2) + (rc->projection_height / 2);
    if (rc->projection_end < 0)
        rc->projection_end = info->win_height - 1;
	j = rc->projection_start - 1;
	while (++j < rc->projection_end)
		mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF); // 일단은 색깔

    // if (rc->tile_hit_dir == 1)
    // {
    //     double image_x;
    //     double image_y;
    //     int color;

    //     image_x = rc->tile_x * info->no->width / info->tile_width + 0.000001; 
    //     image_y = 0;
    //     j = rc->projection_start - 1;
    //     while (++j < rc->projection_end)
    //     {
    //         // color = pixel_color(info->no->image, (int)image_x, (int)image_y, info->no->size_line);
    //         // mlx_pixel_put(info->mlx, info->win, i, j, color);
    //         printf("(%f, %f) (%d,%d)\n", image_x, image_y, (int)image_x, (int)image_y);
    //         image_y += info->no->height / rc->projection_height + 0.000001;
    //     }
    // }
    // else if (rc->tile_hit_dir == 2)
    // {
    //     double image_x;
    //     double image_y;
    //     int color;

    //     image_y = 0;
    //     image_x = rc->tile_x * info->no->width / info->tile_height + 0.000001; 
    //     j = rc->projection_start - 1;
    //     while (++j < rc->projection_end)
    //     {
    //         color = pixel_color(info->no->image, (int)image_x, (int)image_y, info->no->size_line);
    //         mlx_pixel_put(info->mlx, info->win, i, j, color);
    //         image_y += info->no->height / rc->projection_height + 0.000001;
    //     }
    // }
    // else if (rc->tile_hit_dir == 3)
    // {
    //     double image_y;
    //     double image_x;
    //     int color;

    //     image_y = 0;
    //     image_x = rc->tile_x * info->no->width / info->tile_width + 0.000001; 
    //     j = rc->projection_start - 1;
    //     while (++j < rc->projection_end)
    //     {
    //         color = pixel_color(info->no->image, (int)image_x, (int)image_y, info->no->size_line);
    //         mlx_pixel_put(info->mlx, info->win, i, j, color);
    //         image_y += info->no->height / rc->projection_height + 0.000001;
    //     }
    // }
    // else
    // {
    //     double image_y;
    //     double image_x;
    //     int color;

    //     image_y = 0;
    //     image_x = rc->tile_x * info->no->width / info->tile_height + 0.000001; 
    //     j = rc->projection_start - 1;
    //     while (++j < rc->projection_end)
    //     {
    //         color = pixel_color(info->no->image, (int)image_x, (int)image_y, info->no->size_line);
    //         mlx_pixel_put(info->mlx, info->win, i, j, color);
    //         image_y += info->no->height / rc->projection_height + 0.000001;
    //     }
    // }
}
