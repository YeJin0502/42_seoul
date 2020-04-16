/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 22:55:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/16 20:51:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void render_item_sub2(t_info *info, t_rc *rc, t_item *item)
{
	int j;
	int color;

	while (++item->i_min < item->i_max)
	{
		j = item->bar_start - 1;
		item->image_y = 0;
		while (++j < item->bar_end)
		{
			if (0 <= j && j <= info->win_height && item->ray_dist < rc->ray_dists[item->i_min]
				&& 0 <= item->i_min && item->i_min <= info->win_width)
			{
				color = get_color(info->s, (int)item->image_x, (int)item->image_y);
				if (color)
					change_color(info->scene, item->i_min, j, color);
			}
			item->image_y += (double)info->s->height / item->bar_height + 0.000001;
		}
		item->image_x -= (double)info->s->width / item->render_width + 0.000001; // ??
	}
}

double abs_double(double num)
{
	if (num >= 0)
		return (num);
	else
		return (num);
}

static void render_item_sub1(t_info *info, t_rc *rc, t_item *item)
{
	double dot_product;
	double abs_vec;
	double abs_dirvec;

	item->vec_x = item->x - info->x;
	item->vec_y = item->y - info->y;
	item->dirvec_x = item->ray_dist * cos(info->view_angle);
	item->dirvec_y = item->ray_dist * sin(info->view_angle);
	dot_product = item->vec_x * item->dirvec_x + item->vec_y * item->dirvec_y;
	abs_vec = distance(0, 0, item->vec_x, item->vec_y);
	abs_dirvec = distance(0, 0, item->dirvec_x, item->dirvec_y);
	item->dir_angle = acos(dot_product / (abs_vec * abs_dirvec));
	item->bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / item->ray_dist;
	item->bar_start = (info->win_height / 2) - (item->bar_height / 2);
	item->bar_end = (info->win_height / 2) + (item->bar_height / 2);
	item->render_width = (item->bar_height * info->s->width) / info->s->height;
	item->image_x = info->s->width;
	// if (item->dir_angle == 0)
	// 	item->i = (info->win_width / 2);
	if (item->vec_x - item->dirvec_x >= 0)
		item->i = ((info->win_width / 2) + (abs_vec * sin(item->dir_angle))
				* rc->projection_dist / (abs_vec * cos(item->dir_angle)));
	else if (item->vec_x - item->dirvec_x < 0)
		item->i = (int)((info->win_width / 2) - (abs_vec * sin(item->dir_angle))
				* rc->projection_dist / (abs_vec * cos(item->dir_angle)));		
	item->i_min = item->i - (int)item->render_width / 2 - 1;
	item->i_max = item->i + (int)item->render_width / 2;
	render_item_sub2(info, rc, item);
}

void render_item(t_info *info, t_rc *rc, t_item **item)
{
	int i_item;

	i_item = -1;
	while (++i_item < info->item_count && item[i_item]->ray_dist)
	{
		if (item[i_item]->x || item[i_item]->y)
		{
			render_item_sub1(info, rc, item[i_item]);
		}
	}
}
