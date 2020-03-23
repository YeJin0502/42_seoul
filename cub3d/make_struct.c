/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:47:22 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/23 18:47:22 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point *make_point(int x_value, int y_value)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = x_value;
	p->y = y_value;
	return (p);
}

t_boundary *make_boundary(int x1, int y1, int x2, int y2)
{
	t_boundary *boundary;
	t_point *a_value;
	t_point *b_value;

	boundary = (t_boundary *)malloc(sizeof(t_boundary));
	a_value = make_point(x1, y1);
	b_value = make_point(x2, y2);
	boundary->a = a_value;
	boundary->b = b_value;
	return (boundary);
}

t_ray *make_ray(int x1, int y1, int x2, int y2)
{
	t_ray *ray;
	t_point *pos_value;
	t_point *dir_value;

	ray = (t_ray *)malloc(sizeof(t_ray));
	pos_value = make_point(x1, y1);
	dir_value = make_point(x2, y2);
	ray->pos = pos_value;
	ray->dir = dir_value;
	return (ray);
}
