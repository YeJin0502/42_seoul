/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/15 14:25:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double norm_angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	if (angle > 2 * PI)
		angle = fmod(angle, 2 * PI);
	return (angle);
}

void init_ray_angle(t_rc *rc)
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
	rc->ray_dists = (double *)malloc(sizeof(double) * info->win_width);
	ft_memset(rc->ray_dists, 0, sizeof(double) * info->win_width);
	rc->items = (t_item *)malloc(sizeof(t_item) * info->item_count);
	ft_memset(rc->items, 0, sizeof(t_item) * info->item_count);
	i = -1;
	while (++i < info->win_width)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		render(info, rc, i);
		if (rc->is_item == 1 && !rc->item_i_start)
			rc->item_i_start = i;
		else if (rc->is_item == 0 && rc->item_i_start && !rc->item_i_end)
			rc->item_i_end = i - 1;
		rc->ray_angle += FOV / info->win_width;
		rc->ray_dists[i] = rc->ray_dist;
	}
	render_item(info, rc);
	if (info->argc == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->scene->image, 0, 0);
}
