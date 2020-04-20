/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 22:55:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/20 13:05:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		render_item_sub(t_info *info, t_rc *rc, t_item *item)
{
	int j;
	int color;

	item->i_min = item->i - (int)item->render_width / 2 - 1;
	item->i_max = item->i + (int)item->render_width / 2;
	while (++item->i_min < item->i_max)
	{
		j = item->bar_start - 1;
		item->image_y = 0;
		while (++j < item->bar_end)
		{
			if (0 <= j && j <= info->win_height
				&& item->ray_dist < rc->ray_dists[item->i_min]
				&& 0 <= item->i_min && item->i_min <= info->win_width)
				if ((color = get_color(info->s,
					(int)item->image_x, (int)item->image_y)))
					change_color(info->scene, item->i_min, j, color);
			item->image_y +=
			(double)info->s->height / item->bar_height + 0.000001;
		}
		item->image_x -=
		(double)info->s->width / item->render_width + 0.000001;
	}
}

static void		render_item_init(t_info *info, t_rc *rc, t_item *item)
{
	item->vec_x = item->x - info->x;
	item->vec_y = item->y - info->y;
	item->dirvec_x = item->ray_dist * cos(info->view_angle);
	item->dirvec_y = item->ray_dist * sin(info->view_angle);
	item->dir_angle = asin((item->vec_x * item->dirvec_y
					- item->vec_y * item->dirvec_x)
					/ (item->ray_dist * item->ray_dist));
	item->bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / item->ray_dist;
	item->bar_start = (info->win_height / 2) - (item->bar_height / 2);
	item->bar_end = (info->win_height / 2) + (item->bar_height / 2);
	item->render_width = (item->bar_height * info->s->width) / info->s->height;
	item->image_x = info->s->width;
	if (cos(item->dir_angle) != 0)
		item->i =
		((info->win_width / 2) - (item->ray_dist * sin(item->dir_angle))
		* rc->projection_dist / (item->ray_dist * cos(item->dir_angle)));
}

static void		sort_item(t_info *info, t_item **item)
{
	int		count;
	int		i;
	t_item	*tmp;

	count = 0;
	while (count < info->item_count && item[count]->ray_dist)
		count++;
	tmp = (t_item *)malloc(sizeof(t_item));
	while (--count > 0)
	{
		i = -1;
		while (++i < count)
		{
			if (item[i]->ray_dist < item[i + 1]->ray_dist)
			{
				ft_memmove(tmp, item[i], sizeof(t_item));
				ft_memmove(item[i], item[i + 1], sizeof(t_item));
				ft_memmove(item[i + 1], tmp, sizeof(t_item));
			}
		}
	}
	free(tmp);
	tmp = 0;
}

void			render_item(t_info *info, t_rc *rc, t_item **item)
{
	int i_item;

	sort_item(info, item);
	i_item = -1;
	while (++i_item < info->item_count && item[i_item]->ray_dist)
	{
		if (item[i_item]->x || item[i_item]->y)
		{
			render_item_init(info, rc, item[i_item]);
			render_item_sub(info, rc, item[i_item]);
		}
	}
}
