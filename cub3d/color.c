/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 20:33:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 20:33:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int pixel_color(t_img *img, int x, int y)
{
    int b_i;
    int g_i;
    int r_i;
	int color;

    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    b_i = (int)(img->image_data[x * 4 + img->size_line * y ]);
    g_i = (int)img->image_data[x * 4 + img->size_line * y + 1]; // 괄호 안해줘도 되려나?
    r_i = (int)img->image_data[x * 4 + img->size_line * y + 2];
	color = 0x000000;
	color += b_i;
	color += 16 * 16 * g_i;
	color += 16 * 16 * 16 * 16 * r_i;
	return (color);
}
