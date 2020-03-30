/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 21:23:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 21:23:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_win_size(char *line, t_ps *ps, t_info *info)
{
    char *adr;

    adr = line + 1;
    while (*adr == ' ')
        adr++;
    info->win_width = ft_atoi(adr);
    if (info->win_width > DISPLAY_WIDTH)
        info->win_width = DISPLAY_WIDTH;
    adr = ft_strchr(adr, ' ');
    info->win_height = ft_atoi(adr);
    if (info->win_height > DISPLAY_HEIGHT)
        info->win_height = DISPLAY_HEIGHT;
}

static void init_fc(char *line, char *fc, t_info *info, t_ps *ps)
{
    char *rgb;

    rgb = line + 1;
    while (*rgb == ' ')
        rgb++;
    if (ft_strncmp(fc, "F", 1) == 0)
    {
        info->f[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[2] = ft_atoi(rgb);
    }
    else
    {
        info->c[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[2] = ft_atoi(rgb); 
    }
}

static void parsing(t_info *info, t_ps *ps, char *filename)
{
    ps->fd = open(filename, O_RDONLY);
    while (get_next_line(ps->fd, &(ps->line)) || ft_strlen(ps->line))
    {
        ps->map_start++;
        if (ft_strnstr(ps->line, "R ", 2))
            init_win_size(ps->line, ps, info);
        else if (ft_strnstr(ps->line, "NO ", 3))
            ps_texture(ps->line, "NO", ps);
        else if (ft_strnstr(ps->line, "SO ", 3))
            ps_texture(ps->line, "SO", ps);
        else if (ft_strnstr(ps->line, "WE ", 3))
            ps_texture(ps->line, "WE", ps);
        else if (ft_strnstr(ps->line, "EA ", 3))
            ps_texture(ps->line, "EA", ps);
        else if (ft_strnstr(ps->line, "F ", 2))
            init_fc(ps->line, "F", info, ps);
        else if (ft_strnstr(ps->line, "C ", 2))
            init_fc(ps->line, "C", info, ps);
        else if (ft_strnstr(ps->line, "S ", 2))
            ps_texture(ps->line, "S ", ps);
        else if (ft_strlen(ps->line) && --ps->map_start)
            init_map_size(ps->line, info);
        free(ps->line);    
    }
}

void init_info(char *filename, t_info *info)
{
    t_ps *ps;

    ps = (t_ps *)malloc(sizeof(t_ps));
    ft_memset(ps, 0, sizeof(t_ps));
    parsing(info, ps, filename);
    free(ps->line);
    info->tile_width = info->win_width / info->map_width;
    info->tile_height = info->win_height / info->map_height;
    init_map(info, ps, filename);
    info->mlx = mlx_init();
    if (info->argc == 2) // bmp 저장할때 win 켜졌다가 꺼지는거 불편해서...
        info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "gmoon");
    init_texture(info, ps);
    free(ps->no);
    free(ps->so);
    free(ps->we);
    free(ps->ea);
    free(ps->s);
    free(ps);
}
