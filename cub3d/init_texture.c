/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 06:29:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 15:51:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ps_texture(char *line, char *wall, t_ps *ps) // 유효성검사를 여기서?
{
    char *mover;
    char *filename;

    mover = line + 2;
    while (*mover == ' ')
        mover++;
    filename = ft_strdup(mover);
    if (open(filename, O_RDONLY) == -1)
        error_exit(1);
    if (ft_strncmp(wall, "NO", 2) == 0 && !ps->no)
        ps->no = filename;
    else if (ft_strncmp(wall, "SO", 2) == 0 && !ps->so)
        ps->so = filename;
    else if (ft_strncmp(wall, "WE", 2) == 0 && !ps->we)
        ps->we = filename;
    else if (ft_strncmp(wall, "EA", 2) == 0 && !ps->ea)
        ps->ea = filename;
    else if (ft_strncmp(wall, "S", 1) == 0 && !ps->s)
        ps->s = filename;
    else
        error_exit(2);
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
    info->s = make_xpm_img(ps->s, info);
    free(ps->no);
    free(ps->so);
    free(ps->we);
    free(ps->ea);
    free(ps->s);
    free(ps);
}
