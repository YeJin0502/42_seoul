/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 01:27:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double norm_angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	if (angle > 2 * PI)
		angle = fmod(angle, 2 * PI); // 이거 다른 함수들 살펴봐야.
	return (angle); // 맞나?
}

void raycast(t_info *info, t_rc *rc)
{
	int i;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	i = -1;
	while (++i < info->win_width)
	{
		rc->ray_angle = norm_angle(rc->ray_angle);
		rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
		rc->is_ray_up = !(rc->is_ray_down);
		rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
		rc->is_ray_right = !(rc->is_ray_left);
		find_ray_dist(info, rc);
		render(info, rc, i);
		rc->ray_angle += FOV / info->win_width;
	}
}
