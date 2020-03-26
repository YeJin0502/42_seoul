/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 04:54:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 04:54:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rendering(t_info *info, t_rc *rc, int i)
{
	int j;

	rc->corrected_ray_dist = rc->ray_dist * cos(info->view_angle - rc->ray_angle);
	rc->projection_dist = info->R_width / (2 * tan(FOV / 2));
	rc->projection_height = info->tile_height * rc->projection_dist / rc->corrected_ray_dist; // 임시로 tile 높이 사용. 뭐 써야할라나..?
	rc->projection_start = (info->R_height / 2) - (rc->projection_height / 2);
	rc->projection_end = (info->R_height / 2) + (rc->projection_height / 2);
	j = rc->projection_start - 1;
	while (++j < rc->projection_end)
		mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF); // 일단은 색깔
}
