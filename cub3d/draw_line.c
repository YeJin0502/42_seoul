/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:30:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 02:30:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(t_pair p1, t_pair p2, t_info *info) // 구조체, 구조체의 포인터 장단점을 모르겠다.
{
	int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    float Xi = (float)dx / (float)steps;
    float Yi = (float)dy / (float)steps; // float 안붙여주면 증가 안함
    
    float x = (float)p1.x, y = (float)p1.y;
    for (int v = 0; v < steps; v++)
    {
        x = x + Xi;
        y = y + Yi;
        mlx_pixel_put(info->mlx, info->win, round(x), round(y), 0xFF00FF);
    }
}
