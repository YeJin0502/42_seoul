/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 21:17:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double norm_angle(double angle)
{
    while (angle < 0)
        angle = angle + 2 * PI;
    if (angle > 2 * PI)
        angle = fmod(angle, 2 * PI);
    return (angle);
}

static void init_ray_angle(t_rc *rc)
{
    rc->ray_angle = norm_angle(rc->ray_angle);
    rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
    rc->is_ray_up = !(rc->is_ray_down);
    rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
    rc->is_ray_right = !(rc->is_ray_left);	
}

void raycast(t_info *info, t_rc *rc)
{
    int i;

    rc->ray_angle = info->view_angle - (FOV / 2.0);
    i = -1;
    while (++i < info->win_width)
    {
        init_ray_angle(rc);
        find_ray_dist(info, rc);
        render(info, rc, i);
        rc->ray_angle += FOV / info->win_width;
    }
    if (info->argc == 2)
        mlx_put_image_to_window(info->mlx, info->win, info->scene->image, 0, 0);
}
