/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 06:10:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 21:50:37 by gmoon            ###   ########.fr       */
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

static void init_rc_ray(t_rc *rc)
{
    rc->ray_angle = norm_angle(rc->ray_angle);
    rc->is_ray_down = (0 < rc->ray_angle && rc->ray_angle < PI);
    rc->is_ray_up = !(rc->is_ray_down);
    rc->is_ray_left = (0.5 * PI < rc->ray_angle && rc->ray_angle < 1.5 * PI);
    rc->is_ray_right = !(rc->is_ray_left);	
    
}

// 테스트용
void draw_line(int x1, int y1, int x2, int y2, t_info *info) // 구조체, 구조체의 포인터 장단점을 모르겠다.
{
	int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    float Xi = (float)dx / (float)steps;
    float Yi = (float)dy / (float)steps; // float 안붙여주면 증가 안함
    
    float x = (float)x1, y = (float)y1;
    for (int v = 0; v < steps; v++)
    {
        x = x + Xi;
        y = y + Yi;
        mlx_pixel_put(info->mlx, info->win, round(x), round(y), 0xFF00FF);
    }
}

void raycast(t_info *info, t_rc *rc)
{
    t_img *new_scene;
    int i;

    rc->ray_angle = info->view_angle - (FOV / 2.0);
    i = -1;
    while (++i < info->win_width)
    {
        init_rc_ray(rc);
        find_ray_dist(info, rc);
        // draw_line(info->x, info->y, rc->intersection_x , rc->intersection_y, info); // 테스트용
        render(info, rc, i);
        rc->ray_angle += FOV / info->win_width;
    }
    mlx_put_image_to_window(info->mlx, info->win, info->scene->image, 0, 0);
}
