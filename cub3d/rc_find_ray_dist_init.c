/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_dist_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 06:08:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 06:08:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_horz(t_info *info, t_rc *rc, t_fd *horz)
{
    horz->intersection_y = floor(info->y / info->tile_height) * info->tile_height;
    horz->intersection_y += (rc->is_ray_down) ? info->tile_height : 0;
    horz->intersection_x = info->x + (horz->intersection_y - info->y) / tan(rc->ray_angle);
    horz->dy = info->tile_height;
    horz->dy *= (rc->is_ray_up) ? -1 : 1;
    horz->dx = info->tile_height / tan(rc->ray_angle);
    if ((rc->is_ray_left && horz->dx > 0) || (rc->is_ray_right && horz->dx < 0))
        horz->dx *= -1;
    horz->intersection_y += (rc->is_ray_up) ? -1 : 0;
}

void init_vert(t_info *info, t_rc *rc, t_fd *vert)
{
    vert->intersection_x = floor(info->x / info->tile_width) * info->tile_width;
    vert->intersection_x += (rc->is_ray_right) ? info->tile_width : 0;
    vert->intersection_y = info->y + (vert->intersection_x - info->x) * tan(rc->ray_angle);
    vert->dx = info->tile_width;
    vert->dx *= (rc->is_ray_left) ? -1 : 1;
    vert->dy = info->tile_width * tan(rc->ray_angle);
    if ((rc->is_ray_down && vert->dy < 0) || (rc->is_ray_up && vert->dy > 0))
        vert->dy *= -1;
    vert->intersection_x += (rc->is_ray_left) ? -1 : 0;
}

void init_ray_dist(t_rc *rc, t_fd *fd)
{
    rc->intersection_x = fd->intersection_x;
    rc->intersection_y = fd->intersection_y;
    rc->ray_dist = fd->ray_dist;
    rc->tile_x = fd->tile_x;
    rc->tile_hit_dir = fd->tile_hit_dir;
}
