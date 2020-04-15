/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 22:55:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/16 00:48:30 by gmoon            ###   ########.fr       */
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
	// rc->is_item = 0;
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
	// rc->item_ray_dist = distance(info->x, info->y,
						// rc->items->item_x, rc->items->item_y);
	item->bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / item->ray_dist;
	item->bar_start = (info->win_height / 2) - (item->bar_height / 2);
	item->bar_end = (info->win_height / 2) + (item->bar_height / 2);
	item->render_width = (item->bar_height * info->s->width) / info->s->height;
	item->image_x = info->s->width;
	// item->i = (int)(item->i_start + item->i_end) / 2; // 될라나?
	item->i = (info->win_width / 2) - abs_double(info->x - item->x)
			* rc->projection_dist / abs_double(info->y - item->y);
	printf("%f %f\n", item->x, item->y);
	item->i_min = item->i - (int)item->render_width / 2 - 1;
	item->i_max = item->i + (int)item->render_width / 2;
	render_item_sub2(info, rc, item);
}

// int find_i_end(t_info *info, t_rc rc, t_item *item, int i)
// {
// 	// int i;

// 	// rc.ray_angle = info->view_angle + (FOV / 2.0);
// 	// rc.is_item = 1;
// 	// i = info->win_width;
// 	while (item->x == rc.item_x && item->y == rc.item_y)
// 	{
// 		init_ray_angle(&rc);
// 		find_ray_dist(info, &rc);
// 		if (item->x != rc.item_x || item->y == rc.item_y)
// 			return (i - 1);
// 		rc.ray_angle += FOV / info->win_width;
// 		i++;
// 	}
// 	return (0);
// }

// int find_i_start(t_info *info, t_rc rc, t_item *item, int i)
// {
// 	// int i;

// 	// rc.ray_angle = info->view_angle - (FOV / 2.0);
// 	// rc.is_item = 1;
// 	// i = 0;
// 	while (item->x == rc.item_x && item->y == rc.item_y)
// 	{
// 		init_ray_angle(&rc);
// 		find_ray_dist(info, &rc);
// 		if (item->x != rc.item_x && item->y != rc.item_y)
// 			return (i + 1);
// 		rc.ray_angle -= FOV / info->win_width;
// 		i--;
// 	}
// 	return (0);
// }

void render_item(t_info *info, t_rc *rc, t_item **item)
{
	int i_item;

	i_item = -1;
	while (++i_item < info->item_count && item[i_item]->ray_dist)
	// i_item = 1;
	{
		// printf("%d, %f, (%d, %d)\n", i_item, item[i_item]->ray_dist,
		// 		item[i_item]->i_start, item[i_item]->i_end);
		// if (item[i_item]->i_start == 1)
		// {
		// 	item[i_item]->i_start = find_i_start(info, rc, item);
		// 	// printf("%d, (%d, %d)\n", i_item, item[i_item]->i_start, item[i_item]->i_end);
		// }
		// else if (item[i_item]->i_start && !item[i_item]->i_end)
		// {
		// 	// printf("%d\n", i_item);
		// 	item[i_item]->i_end = find_i_end(info, rc, item);
		// }
		if (item[i_item]->x || item[i_item]->y)
		{
			render_item_sub1(info, rc, item[i_item]);
		}
	}
}
