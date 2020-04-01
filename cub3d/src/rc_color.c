/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 22:11:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 22:11:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int make_color(int r, int g, int b)
{
    int color;

    color = 0x000000;
    color += b;
    color += 16 * 16 * g;
    color += 16 * 16 * 16 * 16 * r;
    return (color);
}

int get_color(t_img *img, int x, int y)
{
    int b;
    int g;
    int r;
    int color;

    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    b = (int)img->image_data[x * 4 + img->size_line * y];
    g = (int)img->image_data[x * 4 + img->size_line * y + 1];
    r = (int)img->image_data[x * 4 + img->size_line * y + 2];
    color = make_color(r, g, b);
    return (color);
}

void change_color(t_img *img, int x, int y, int color)
{
    int r;
    int g;
    int b;

    r = (int)((double)color / (16 * 16 * 16 * 16));
    color = color % (16 * 16 * 16 * 16);
    g = (int)((double)color / (16 * 16));
    b = color % (16 * 16); // 맞아..?
    img->image_data[x * 4 + img->size_line * y] = b;
    img->image_data[x * 4 + img->size_line * y + 1] = g;
    img->image_data[x * 4 + img->size_line * y + 2] = r;
}
