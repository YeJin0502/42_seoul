/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 22:55:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/15 14:43:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void render_item_sub2(t_info *info, t_rc *rc, int i_min, int i_max)
{
	int j;
	int color;

	while (++i_min < i_max)
	{
		j = rc->item_bar_start - 1;
		rc->item_image_y = 0;
		while (++j < rc->item_bar_end)
		{
			if (0 <= j && j <= info->win_height && rc->item_ray_dist < rc->ray_dists[i_min]
				&& 0 <= i_min && i_min <= info->win_width)
			{
				color = get_color(info->s, (int)rc->item_image_x, (int)rc->item_image_y);
				if (color)
					change_color(info->scene, i_min, j, color);
			}
			rc->item_image_y += (double)info->s->height / rc->item_bar_height + 0.000001;
		}
		rc->item_image_x -= (double)info->s->width / rc->item_width + 0.000001; // ??
	}
	rc->is_item = 0;
}

static void render_item_sub1(t_info *info, t_rc *rc, int i)
{
	int i_min;
	int i_max;

	// rc->item_ray_dist = distance(info->x, info->y,
						// rc->items->item_x, rc->items->item_y);
	rc->item_bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / rc->item_ray_dist;
	rc->item_bar_start = (info->win_height / 2) - (rc->item_bar_height / 2);
	rc->item_bar_end = (info->win_height / 2) + (rc->item_bar_height / 2);
	rc->item_width = (rc->item_bar_height * info->s->width) / info->s->height;
	rc->item_image_x = info->s->width;
	i_min = i - (int)rc->item_width / 2 - 1;
	i_max = i + (int)rc->item_width / 2;
	render_item_sub2(info, rc, i_min, i_max);
}

static void find_i_end(t_info *info, t_rc *rc)
{
	int i;

	rc->ray_angle = info->view_angle + (FOV / 2.0);
	i = info->win_width;
	while (rc->is_item == 1)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		if (rc->is_item == 0)
			rc->item_i_end = i - 1;
		rc->ray_angle += FOV / info->win_width;
		i++;
	}
}

static void find_i_start(t_info *info, t_rc *rc)
{
	int i;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	rc->is_item = 1;
	i = 0;
	while (rc->is_item == 1)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		if (rc->is_item == 0)
			rc->item_i_start = i + 1;
		rc->ray_angle -= FOV / info->win_width;
		i--;
	}
}

void render_item(t_info *info, t_rc *rc)
{
	if (rc->item_i_start == 1)
		find_i_start(info, rc);
	else if (rc->item_i_start && !rc->item_i_end)
		find_i_end(info, rc);
	if (rc->item_i_end)
		render_item_sub1(info, rc, (rc->item_i_start + rc->item_i_end) / 2);
}
