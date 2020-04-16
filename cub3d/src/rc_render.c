/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 01:27:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 01:27:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*select_wall_img(t_info *info, t_rc *rc)
{
	t_img *wall_img;

	if (rc->tile_hit_dir == 1)
		wall_img = info->no;
	else if (rc->tile_hit_dir == 2)
		wall_img = info->ea;
	else if (rc->tile_hit_dir == 3)
		wall_img = info->so;
	else
		wall_img = info->we;
	return (wall_img);
}

static void		init_to_render_wall(t_info *info, t_rc *rc)
{
	rc->ray_dist *= cos(info->view_angle - rc->ray_angle);
	rc->projection_dist = info->win_width / (2 * tan(FOV / 2));
	rc->bar_height = (info->tile_height + info->tile_width) / 2
					 * rc->projection_dist / rc->ray_dist;
	rc->bar_start = (info->win_height / 2) - (rc->bar_height / 2);
	rc->bar_end = (info->win_height / 2) + (rc->bar_height / 2);
	rc->wall_image = select_wall_img(info, rc);
	if (rc->tile_hit_dir == 1 || rc->tile_hit_dir == 3)
		rc->wall_image_x = rc->tile_x * rc->wall_image->width / info->tile_width + 0.000001;
	else
		rc->wall_image_x = rc->tile_x * rc->wall_image->width / info->tile_height + 0.000001;
	rc->wall_image_y = 0;
}

static void		render_wall(t_info *info, t_rc *rc, int i)
{
	int j;
	int color;

	j = -1;
	while (++j < rc->bar_start)
	{
		color = make_color(info->c[0], info->c[1], info->c[2]);
		change_color(info->scene, i, j, color);
	}
	j = rc->bar_start - 1;
	while (++j < rc->bar_end)
	{
		if (0 <= j && j <= info->win_height)
		{
			color = get_color(rc->wall_image, (int)rc->wall_image_x, (int)rc->wall_image_y);
			change_color(info->scene, i, j, color);
		}
		rc->wall_image_y += (double)rc->wall_image->height / rc->bar_height + 0.000001;
	}
	while (++j < info->win_height)
	{
		color = make_color(info->f[0], info->f[1], info->f[2]);
		change_color(info->scene, i, j, color);
	}
}

void 			render(t_info *info, t_rc *rc, int i)
{
	init_to_render_wall(info, rc);
	render_wall(info, rc, i);
}
