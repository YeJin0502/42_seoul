/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:00:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/23 20:55:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point *move_point(t_point *p, int x_value, int y_value)
{
	t_point *moved_point;

	moved_point = make_point(p->x, p->y);
	moved_point->x = p->x + x_value;
	moved_point->y = p->y + y_value;
	return (moved_point);
}

int main()
{
	t_info *info;
	t_boundary *boundary;
	t_ray *ray;

	// ft_memset(info, 0, sizeof(info));
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 400, 400, "test");
	boundary = make_boundary(300, 100, 300, 300);
	ray = make_ray(100, 200, 300, 300);
	plot_line(boundary->a, boundary->b, info);
	// plot_line(ray->pos, move_point(ray->pos, (ray->dir->x) * 10, (ray->dir->y) * 10), info);

	mlx_loop(info->mlx);
}
