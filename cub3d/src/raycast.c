/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/17 00:05:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	norm_angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	if (angle > 2 * PI)
		angle = fmod(angle, 2 * PI);
	return (angle);
}

static void		init_ray_angle(t_rc *rc)
{
	rc->ray_angle = norm_angle(rc->ray_angle);
	rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
	rc->is_ray_up = !(rc->is_ray_down);
	rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
	rc->is_ray_right = !(rc->is_ray_left);	
}

static void		init_rc(t_info *info, t_rc *rc)
{
	int i;

	rc->ray_angle = info->view_angle - (FOV / 2.0);
	if (!(rc->ray_dists = (double *)malloc(sizeof(double) * info->win_width)))
		error_exit(1);
	ft_memset(rc->ray_dists, 0, sizeof(double) * info->win_width);
	if (!(rc->item = (t_item **)malloc(sizeof(t_item *) * info->item_count)))
		error_exit(1);
	i = -1;
	while (++i < info->item_count)
	{
		if (!(rc->item[i] = (t_item *)malloc(sizeof(t_item))))
			error_exit(1);
		ft_memset(rc->item[i], 0, sizeof(t_item));
	}
}

static void		free_rc_arr(t_info *info, t_rc *rc, t_item **item)
{
	int i;

	i = -1;
	while (++i < info->item_count)
	{
		free(item[i]);
		item[i] = 0;
	}
	free(item);
	item = 0;
	free(rc->ray_dists);
	rc->ray_dists = 0;
}

void			raycast(t_info *info, t_rc *rc)
{
	t_item	**item;
	int		i;

	init_rc(info, rc);
	item = rc->item;
	i = -1;
	while (++i < info->win_width)
	{
		init_ray_angle(rc);
		find_ray_dist(info, rc);
		rc->ray_dists[i] = rc->ray_dist;
		render(info, rc, i);
		rc->ray_angle += FOV / info->win_width;
	}
	render_item(info, rc, item);
	if (info->argc == 2)
		mlx_put_image_to_window(info->mlx, info->win,
								info->scene->image, 0, 0);
	free_rc_arr(info, rc, item);
}
