/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 04:53:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 04:53:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double distance(double x1, double y1, double x2, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void find_intersection(t_info *info, t_fd *fd, t_rc *rc)
{
    fd->is_item_hit = 0;
    while (fd->intersection_x >= 0 && fd->intersection_x <= info->win_width &&
            fd->intersection_y >= 0 && fd->intersection_y <= info->win_height)
    {
        if (is_wall(fd->intersection_x, fd->intersection_y, info) == 2
            && fd->is_horz == 1 && fd->is_item_hit == 0)
        {
            fd->is_item_hit = 1;
            rc->item_ray_dist = distance(info->x, info->y, fd->intersection_x, fd->intersection_y);
            if (rc->is_ray_up)
                rc->item_tile_x = fmod(fd->intersection_x, info->tile_width);
            else
                rc->item_tile_x = info->tile_width - fmod(fd->intersection_x, info->tile_width);
        }
        else if (is_wall(fd->intersection_x, fd->intersection_y, info) == 1)
        {
            fd->is_wall_hit = 1;
            break;
        }
        fd->intersection_x += fd->dx;
        fd->intersection_y += fd->dy;
    }
}

static t_fd *find_horz_dist(t_info *info, t_rc *rc)
{
    t_fd *horz;

    horz = (t_fd *)malloc(sizeof(t_fd));
    ft_memset(horz, 0, sizeof(t_fd));
    init_horz(info, rc, horz);
    find_intersection(info, horz, rc);
    if (horz->is_wall_hit)
    {
        horz->ray_dist = distance(info->x, info->y, horz->intersection_x, horz->intersection_y);
        if (rc->is_ray_up)
        {
            horz->tile_x = fmod(horz->intersection_x, info->tile_width);
            horz->tile_hit_dir = 3;
        }
        else
        {
            horz->tile_x = info->tile_width - fmod(horz->intersection_x, info->tile_width);
            horz->tile_hit_dir = 1;
        }
    }
    else
        horz->ray_dist = 2203;
    return (horz);
}

static t_fd *find_vert_dist(t_info *info, t_rc *rc)
{
    t_fd *vert;

    vert = (t_fd *)malloc(sizeof(t_fd));
    ft_memset(vert, 0, sizeof(t_fd));
    init_vert(info, rc, vert);
    find_intersection(info, vert, rc);
    if (vert->is_wall_hit)
    {
        vert->ray_dist = distance(info->x, info->y, vert->intersection_x, vert->intersection_y);
        if (rc->is_ray_right)
        {
            vert->tile_x = fmod(vert->intersection_y, info->tile_height);
            vert->tile_hit_dir = 4;
        }
        else
        {
            vert->tile_x = info->tile_height - fmod(vert->intersection_y, info->tile_height);
            vert->tile_hit_dir = 2;	
        }
    }
    else
        vert->ray_dist = 2203; // 이게 최대값이라는 생각은 드는데... 어짜피 큰수 넣는거랑 똑같다면 max값 넣어도 될듯.
    return (vert);
}

void find_ray_dist(t_info *info, t_rc *rc)
{
    t_fd *horz;
    t_fd *vert;

    horz = find_horz_dist(info, rc);
    vert = find_vert_dist(info, rc);
    rc->is_item_hit = horz->is_item_hit;
    if (vert->ray_dist < horz->ray_dist)
        init_ray_dist(rc, vert);
    else
        init_ray_dist(rc, horz);
    free(horz);
    free(vert);
}