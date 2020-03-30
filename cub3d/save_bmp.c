/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 03:45:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 04:09:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_bmp(int fd, t_img *scene)
{
    char bitmapheader[54];
    int filesize;

    bitmapheader[0] = 'B';
    bitmapheader[1] = 'M';
    filesize = 54 + (scene->width * scene->height * 3);

}