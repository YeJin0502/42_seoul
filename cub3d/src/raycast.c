/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/14 21:13:32 by gmoon            ###   ########.fr       */
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

static void render_item(t_info *info, t_rc *rc, int i)
{
	int j;
	int color;

	rc->item_ray_dist = distance(info->x, info->y,
						rc->items->item_x, rc->items->item_y);
	rc->item_bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / rc->item_ray_dist;
	rc->item_bar_start = (info->win_height / 2) - (rc->item_bar_height / 2);
	rc->item_bar_end = (info->win_height / 2) + (rc->item_bar_height / 2);
	rc->item_width = (rc->item_bar_height * info->s->width) / info->s->height;
	// printf("a) %f\n", rc->item_width);
	rc->item_image_x = 0;
	rc->item_image_y = 0;
	// printf("%f,%f\n", rc->items->item_x, rc->items->item_y);
	// printf("%f,%f\n", rc->item_bar_height, rc->item_width);
	int i_max;
	// i_max = i + info->s->width;
	i_max = i + (int)rc->item_width;
	// printf("a) %d %d\n", i, i_max); 
	// printf("[%d]\n", i);
	i--;
		j = rc->item_bar_start - 1;
	// printf("%d,%d\n", i,j);
	// printf("%d %d\n", i, i_max);
	while (++i < i_max && i < info->win_width)
	{
		j = rc->item_bar_start - 1;
		rc->item_image_y = 0;
		while (++j < rc->item_bar_end)
		{
			if (0 <= j && j <= info->win_height && rc->item_ray_dist < rc->ray_dist)
			{
				color = get_color(info->s, (int)rc->item_image_x, (int)rc->item_image_y);
				if (color)
				{
					// printf("[%d, %d]\n", (int)rc->item_image_x, (int)rc->item_image_y);
					// printf("(%d,%d)\n", i, j);
					// printf("(%d,%d) %d,%d\n", i, j, get_color(info->scene, i, j), color);
					change_color(info->scene, i, j, color);
				}
			}
			rc->item_image_y += (double)info->s->height / rc->item_bar_height + 0.000001;
		}
		rc->item_image_x += (double)info->s->width / rc->item_width + 0.000001; // ??
	}
	rc->is_item = 0;
}


static void render_item_rev(t_info *info, t_rc *rc, int i)
{
	int j;
	int color;

	rc->item_ray_dist = distance(info->x, info->y,
						rc->items->item_x, rc->items->item_y);
	rc->item_bar_height = (info->tile_height + info->tile_width) / 2
						* rc->projection_dist / rc->item_ray_dist;
	rc->item_bar_start = (info->win_height / 2) - (rc->item_bar_height / 2);
	rc->item_bar_end = (info->win_height / 2) + (rc->item_bar_height / 2);
	rc->item_width = (rc->item_bar_height * info->s->width) / info->s->height;
	// printf("b) %f\n", rc->item_width);
	rc->item_image_x = info->s->width;
	rc->item_image_y = 0;
	// printf("%f,%f\n", rc->items->item_x, rc->items->item_y);
	// printf("[%f, %f, %f, %f]\n", rc->item_ray_dist, rc->item_bar_height,
	// 							rc->item_bar_start, rc->item_bar_end);
	int i_min;
	// i_max = i + info->s->width;
	i_min = i - (int)rc->item_width;
	// printf("b) %d %d\n", i_min, i); 
	// printf("[%d]\n", i);
	i++;
	while (--i > i_min && i > 0)
	{
		j = rc->item_bar_start - 1;
		rc->item_image_y = 0;
		while (++j < rc->item_bar_end)
		{
			if (0 <= j && j <= info->win_height && rc->item_ray_dist < rc->ray_dist)
			{
				color = get_color(info->s, (int)rc->item_image_x, (int)rc->item_image_y);
				if (color)
				{
					// printf("[%d, %d]\n", (int)rc->item_image_x, (int)rc->item_image_y);
					// printf("(%d,%d)\n", i, j);
					// printf("(%d,%d) %d,%d\n", i, j, get_color(info->scene, i, j), color);
					change_color(info->scene, i, j, color);
				}
			}
			rc->item_image_y += (double)info->s->height / rc->item_bar_height + 0.000001;
		}
		rc->item_image_x -= (double)info->s->width / rc->item_width + 0.000001; // ??
	}
	rc->is_item = 0;
}


void raycast(t_info *info, t_rc *rc)
{
	int i;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	rc->items = (t_item *)malloc(sizeof(t_item) * info->item_count);
	ft_memset(rc->items, 0, sizeof(t_item) * info->item_count);
	i = -1;
	while (++i < info->win_width)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		render(info, rc, i);
		rc->ray_angle += FOV / info->win_width;
	}
	// printf("(%d, %d)\n", rc->item_i_start, rc->item_i_end);
	if (rc->item_i_start > 1)
	{
		// printf("a) %f,%f / %d\n", rc->items->item_x, rc->items->item_y, rc->item_i_start);
		render_item(info, rc, rc->item_i_start);
	}
	else if (rc->item_i_end)
	{
		// printf("b) %f,%f / %d\n", rc->items->item_x, rc->items->item_y, rc->item_i_end);
		render_item_rev(info, rc, rc->item_i_end);
	}
	if (info->argc == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->scene->image, 0, 0);
}
