/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 01:41:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 21:16:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void make_2d_map(t_info *info)
{
	int i;
	int j;
	int a;
	int b;

	i = -1;
	while (++i < info->map_width)
	{
		j = -1;
		while (++j < info->map_height)
			if (info->map[j][i] != 0)
			{
				a = -1;
				while (++a < info->tile_height)
				{
					b = -1;
					while (++b < info->tile_width)
						mlx_pixel_put(info->mlx, info->win, i * info->tile_width + b,
									j * info->tile_height + a, 0xFFFFFF);
				}
			}
	}
}
