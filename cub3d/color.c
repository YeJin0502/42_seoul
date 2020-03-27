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

int pixel_color(unsigned char *image, int x, int y, int size_line)
{
    int b_i;
    int g_i;
    int r_i;
	int color;

    b_i = (int)image[x * 4 + size_line * y ];
    g_i = (int)image[x * 4 + size_line * y + 1];
    r_i = (int)image[x * 4 + size_line * y + 2];
	color = 0x000000;
	color += b_i;
	color += 16 * 16 * g_i;
	color += 16 * 16 * 16 * 16 * r_i;
	return (color);
}
