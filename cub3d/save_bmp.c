/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 03:45:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 07:11:14 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_bmp(int fd, t_img *scene)
{
    unsigned char bmp_header[54];
    int filesize;

    filesize = 54 + (scene->width * scene->height * 4);
    ft_memset(bmp_header, 0, 54); // 맞나?
    bmp_header[0] = (unsigned char)'B';
    bmp_header[1] = (unsigned char)'M';
    ft_memcpy(bmp_header + 2, &filesize, sizeof(int));
    // printf("%d, %d, %d\n", bmp_header[2], bmp_header[3], bmp_header[4]);
    bmp_header[10] = (unsigned char)54; // 이거도 unsigned char을 붙여줘야 하나?)
    bmp_header[14] = (unsigned char)40;
    ft_memcpy(bmp_header + 18, &scene->width, sizeof(int));
    ft_memcpy(bmp_header + 22, &scene->height, sizeof(int));
    bmp_header[26] = (unsigned char)1;
    bmp_header[28] = (unsigned char)32; // 24로 많이 하던데
    // 왜 이 아래는 안쓰지?

    // unsigned char *pixel_data;
    // pixel_data = (unsigned char *)malloc(filesize - 54);
    // int i;
    // i = -1;
    // while (++i < scene->width * scene->height)
    // {
    //     pixel_data[3 * i] = scene->image_data[4 * i + 2];
    //     pixel_data[3 * i + 1] = scene->image_data[4 * i + 1];
    //     pixel_data[3 * i + 2] = scene->image_data[4 * i]; // 순서가 맞나?
    // }
    
    unsigned char *bmp;

    write(fd, bmp_header, 54);
    write(fd, scene->image_data, scene->width * scene->height * 4);
    // write(fd, pixel_data, filesize - 54);
}