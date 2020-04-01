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
    if (!info->win_width || !info->win_height)
        error_exit(1);
}

static void init_fc(char *line, char *fc, t_info *info, t_ps *ps)
{
    char *rgb;

    rgb = line + 1;
    while (*rgb == ' ')
        rgb++;
    if (ft_strncmp(fc, "F", 1) == 0)
    {
        if (info->f[0] || info->f[1] || info->f[2]) // 맞나? 이미 한번 들어오면... 이거 안되면 플래그 써야지.
            error_exit(1);
        info->f[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->f[2] = ft_atoi(rgb);
        if (!info->f[0] || !info->f[1] || !info->f[2])
            error_exit(1);
    }
    else
    {
        info->c[0] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[1] = ft_atoi(rgb);
        rgb = ft_strchr(rgb, ',') + 1;
        info->c[2] = ft_atoi(rgb); 
        if (!info->c[0] || !info->c[1] || !info->c[2])
            error_exit(1);
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
    free(ps->line);
}

void init_mlx(t_info *info, int argc)
{
    info->argc = argc;
    info->mlx = mlx_init();
    if (info->argc == 2)
        info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "gmoon");
}

t_info *init_info(int argc, char *filename)
{
    t_info *info;
    t_ps *ps;

    info = (t_info *)malloc(sizeof(t_info));
    ft_memset(info, 0, sizeof(t_info));
    ps = (t_ps *)malloc(sizeof(t_ps));
    ft_memset(ps, 0, sizeof(t_ps));
    parsing(info, ps, filename);
    init_map(info, ps, filename);
    init_mlx(info, argc);
    init_texture(info, ps);
    return (info);
}
