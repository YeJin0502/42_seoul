/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:59:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/23 17:59:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void plot_line_low(t_point *p1, t_point *p2, t_info *info)
{
	int			dx;
	int			dy;
	int			yi;
	int			D;
	t_point	p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	yi = 1;
	if (dy < 0 && (yi = -1))
		dy = -dy;
	D = 2 * dy - dx;
	while (p.x <= p2->x)
	{
		mlx_pixel_put(info->mlx, info->win, p.x, p.y, 0xFFFFFF);
		if (D > 0)
		{
			p.y += yi;
			D -= 2 * dx;
		}
		D += 2 * dy;
		p.x++;
	}
}

static void plot_line_high(t_point *p1, t_point *p2, t_info *info)
{
	int			dx;
	int			dy;
	int			xi;
	int			D;
	t_point	p;

	p = *p1;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	xi = 1;
	if (dx < 0 && (xi = -1))
		dx = -dx;
	D = 2 * dx - dy;
	while (p.y <= p2->y)
	{
		mlx_pixel_put(info->mlx, info->win, p.x, p.y, 0xFFFFFF);
		if (D > 0)
		{
			p.x += xi;
			D -= 2 * dy;
		}
		D += 2 * dx;
		p.y++;
	}
}

void plot_line(t_point *p1, t_point *p2, t_info *info)
{
	if (abs(p2->x - p1->x) > abs(p2->y - p1->y))
	{
		if (p2->x > p1->x)
			plot_line_low(p1, p2, info);
		else
			plot_line_low(p2, p1, info);
	}
	else
	{
		if (p2->y > p1->y)
			plot_line_high(p1, p2, info);
		else
			plot_line_high(p2, p1, info);
	}
}
