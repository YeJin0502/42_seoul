/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 04:56:24 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 04:54:23 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_casting(t_info *info, t_rc *rc)
{
	int i;

	rc->move_dist = rc->move_dir * MOVE_SPEED;
	info->view_angle += rc->rotation_dir * ROTATION_SPEED;
	info->x += cos(info->view_angle) * rc->move_dist;
	info->y += sin(info->view_angle) * rc->move_dist;
	rc->ray_angle = info->view_angle - (FOV / 2.0);
	i = -1;
	while (++i < info->R_width)
	{
		rc->ray_angle = norm_angle(rc->ray_angle);
		rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
		rc->is_ray_up = !(rc->is_ray_down);
		rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
		rc->is_ray_right = !(rc->is_ray_left);
		find_ray_dist(info, rc);
		rendering(info, rc, i);
		rc->ray_angle += FOV / info->R_width;
	}
}
