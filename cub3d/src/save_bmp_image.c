/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 03:45:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 23:09:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void write_bmp_header(int fd, t_img *scene)
{
    unsigned char bmp_header[54];
    int filesize;

    filesize = 54 + scene->width * scene->height * 3;
    ft_memset(bmp_header, 0, 54);
    bmp_header[0] = (unsigned char)'B';
    bmp_header[1] = (unsigned char)'M';
    ft_memcpy(bmp_header + 2, &filesize, sizeof(int));
    bmp_header[10] = (unsigned char)54;
    bmp_header[14] = (unsigned char)40;
    ft_memcpy(bmp_header + 18, &scene->width, sizeof(int));
    ft_memcpy(bmp_header + 22, &scene->height, sizeof(int));
    bmp_header[26] = (unsigned char)1;
    bmp_header[28] = (unsigned char)24;
    write(fd, bmp_header, 54);
}

void write_pixel_data(int fd, t_img *scene)
{
    int w;
    int h;
    unsigned char *pixel_data;
    int i;
    int j;

    w = scene->width;
    h = scene->height;
    pixel_data = (unsigned char *)malloc(w * h * 3);
    i = -1;
    while (++i < scene->width)
    {
        j = -1;
        while (++j < scene->height)
        {
            pixel_data[3 * i + 3 * w * j] = scene->image_data[4 * i + 4 * w * (h - j)];
            pixel_data[3 * i + 3 * w * j + 1] = scene->image_data[4 * i + 4 * w * (h - j) + 1];
            pixel_data[3 * i + 3 * w * j + 2] = scene->image_data[4 * i + 4 * w * (h - j) + 2];
        }
    }
    write(fd, pixel_data, w * h * 3);
    free(pixel_data);
}

char *make_bmp_name(char *filename)
{
    char    *mover;
    int     len;
    char    *cub_name;
    char    *bmp_name;

    mover = ft_strnstr(filename, ".cub", ft_strlen(filename));
    len = 0;
    while (*mover != '/')
    {
        mover--;
        len++;
    }
    cub_name = (char *)malloc(len);
    ft_strlcpy(cub_name, mover + 1, len);
    bmp_name = ft_strjoin(cub_name, ".bmp");
    free(cub_name);
    return (bmp_name);
}

void save_bmp_image(t_img *scene, char *filename)
{
    char *bmp_name;
    int fd;

    bmp_name = make_bmp_name(filename);
    fd = open(bmp_name, O_RDWR | O_CREAT, 744);
    write_bmp_header(fd, scene);
    write_pixel_data(fd, scene);
    free(bmp_name); 
}
