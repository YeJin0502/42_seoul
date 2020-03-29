/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_first_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:13:41 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 17:13:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void make_first_scene(t_info *info)
{
    t_rc    *rc;

    info->scene = (t_img *)malloc(sizeof(t_img)); // 이렇게 하는게 맞을까. 확신이 없는데... 이중포인터.
    info->scene->width = info->win_width;
    info->scene->height = info->win_height;
    info->scene->image = mlx_new_image(info->mlx, info->win_width, info->win_height);
    info->scene->image_data = mlx_get_data_addr(info->scene->image, &(info->scene->bpp),
                            &(info->scene->size_line), &(info->scene->endian));
    
    // printf("(%d,%d,%d)\n", info->scene->width, info->scene->height, info->scene->size_line);
    rc = (t_rc *)malloc(sizeof(t_rc));
    raycast(info, rc);
    free(rc);
}