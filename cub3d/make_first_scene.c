/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_first_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:30:56 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 04:05:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void make_first_scene(t_info *info)
{
	// 한번 쓰려는 용도로는 구조체 포인터가 아니라 구조체 할당이 맞는 것 같다. 지역변수라 사라지므로?
	t_pair p1;
	t_pair p2;
	double rayAngle;
	int i;

	make_2d_map(info);
	p1.x = info->x;
	p1.y = info->y;
	rayAngle = info->view_angle - (FOV / 2.0);
	i = -1;
	while (++i < info->R_width)
	{
		p2.x = info->x + cos(rayAngle) * 30;
		p2.y = info->y + sin(rayAngle) * 30;
		draw_line(p1, p2, info);
		rayAngle += FOV / info->R_width;
	}
}
