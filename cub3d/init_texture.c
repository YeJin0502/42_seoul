/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 06:29:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 01:46:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ps_texture(char *line, char *wall, t_ps *ps)
{
    char *filename;

    filename = line + 2;
    while (*filename == ' ')
        filename++;
    if (ft_strncmp(wall, "NO", 2) == 0)
        ps->no = ft_strdup(filename);
    else if (ft_strncmp(wall, "SO", 2) == 0)
        ps->so = ft_strdup(filename);
    else if (ft_strncmp(wall, "WE", 2) == 0)
        ps->we = ft_strdup(filename);
    else if (ft_strncmp(wall, "EA", 2) == 0)
        ps->ea = ft_strdup(filename);
    else
        ps->s = ft_strdup(filename);
}

static t_img *make_xpm_img(char *filename, t_info *info) // 다른데서도 쓸만함
{
    t_img *img;

    img = (t_img *)malloc(sizeof(t_img));
    img->image = mlx_xpm_file_to_image(info->mlx, filename, &(img->width), &(img->height));
    img->image_data = (unsigned char *)mlx_get_data_addr(img->image, &(img->bpp), &(img->size_line), &(img->endian));
    return (img);
}

void init_texture(t_info *info, t_ps *ps)
{
    info->no = make_xpm_img(ps->no, info);
    info->so = make_xpm_img(ps->so, info);
    info->we = make_xpm_img(ps->we, info);
    info->ea = make_xpm_img(ps->ea, info);
    // info->s = make_img(ps->s, info);
}
