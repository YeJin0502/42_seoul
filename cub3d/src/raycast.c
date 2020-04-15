/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/15 23:16:52 by gmoon            ###   ########.fr       */
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

t_item **init_item(t_info *info) // 작명 마음에 안든당
{
	t_item **item;
	int i;

	item = (t_item **)malloc(sizeof(t_item *) * info->item_count);
	i = -1;
	while (++i < info->item_count)
	{
		item[i] = (t_item *)malloc(sizeof(t_item));
		ft_memset(item[i], 0, sizeof(t_item));
	}
	// ft_memset(item, 0, sizeof(t_item) * info->item_count); // 이렇게 해도 될까? 조건문 돌려야하나?
	// item->ray_dists = (double *)malloc(sizeof(double) * info->item_count);
	// ft_memset(item->ray_dists, 0, sizeof(double) * info->item_count);
	// item->i_starts = (int *)malloc(sizeof(int) * info->item_count);
	// ft_memset(item->i_starts, 0, sizeof(int) * info->item_count);
	// item->i_ends = (int *)malloc(sizeof(int) * info->item_count);
	// ft_memset(item->i_ends, 0, sizeof(int) * info->item_count);
	return (item);
}

int find_i_end(t_info *info, t_rc rc, t_item *item, int i)
{
	// int i;

	// rc.ray_angle = info->view_angle + (FOV / 2.0);
	// rc.is_item = 1;
	// i = info->win_width;
	while (item->item_x == rc.item_x && item->item_y == rc.item_y)
	{
		init_ray_angle(&rc);
		find_ray_dist(info, &rc);
		if (item->item_x != rc.item_x || item->item_y == rc.item_y)
			return (i - 1);
		rc.ray_angle += FOV / info->win_width;
		i++;
	}
	return (0);
}

int find_i_start(t_info *info, t_rc rc, t_item *item, int i)
{
	// int i;

	// rc.ray_angle = info->view_angle - (FOV / 2.0);
	// rc.is_item = 1;
	// i = 0;
	while (item->item_x == rc.item_x && item->item_y == rc.item_y)
	{
		init_ray_angle(&rc);
		find_ray_dist(info, &rc);
		if (item->item_x != rc.item_x && item->item_y != rc.item_y)
			return (i + 1);
		rc.ray_angle -= FOV / info->win_width;
		i--;
	}
	return (0);
}

void raycast(t_info *info, t_rc *rc)
{
	int i;
	t_item **item; // *item으로 했었음.
	int i_item;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	rc->ray_dists = (double *)malloc(sizeof(double) * info->win_width);
	ft_memset(rc->ray_dists, 0, sizeof(double) * info->win_width);
	item = init_item(info);
	i = -1;
	i_item = 0;
	while (++i < info->win_width)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		rc->ray_dists[i] = rc->ray_dist;
		render(info, rc, i);
		// if ((item[i_item]->item_x != rc->item_x || item[i_item]->item_y != rc->item_y)
		if (item[i_item]->item_x != rc->item_x || item[i_item]->item_y != rc->item_y) 
			// && !item[i_item]->i_start)
		{
			item[i_item]->item_x = rc->item_x;
			item[i_item]->item_y = rc->item_y;
			item[i_item]->ray_dist = rc->item_ray_dist;
			i_item++;
			// item[i_item]->i_start = i;
		}
		// else if (rc->item_x == 0 && rc->item_y == 0
		// 		 && item[i_item]->i_start && !item[i_item]->i_end)
		// {
		// 	item[i_item]->i_end = i - 1;
		// }
		// if (item[i_item]->i_start == 1)
		// {
		// 	item[i_item]->i_start = find_i_start(info, *rc, item[i_item], i);
		// }
		// else if (item[i_item]->i_start && !item[i_item]->i_end)
		// {
		// 	// printf("%d\n", i_item);
		// 	item[i_item]->i_end = find_i_end(info, *rc, item[i_item], i);
		// 	printf("%d, (%d, %d)\n", i_item, item[i_item]->i_start, item[i_item]->i_end);
		// }
		// if ((item[i_item]->item_x != rc->item_x || item[i_item]->item_y != rc->item_y))
		// 	// && item[i_item]->i_start)
		// {
		// 	i_item++;
		// 	// // printf("%d\n", i_item);
		// }
		rc->ray_angle += FOV / info->win_width;
	}
	render_item(info, rc, item);
	if (info->argc == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->scene->image, 0, 0);
}
