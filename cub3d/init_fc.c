/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:44:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 15:45:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_init_fc(int fc[3], char *rgb)
{
    if (fc[0] || fc[1] || fc[2])
        error_exit(2);
    fc[0] = ft_atoi(rgb);
    rgb = ft_strchr(rgb, ',') + 1;
    fc[1] = ft_atoi(rgb);
    rgb = ft_strchr(rgb, ',') + 1;
    fc[2] = ft_atoi(rgb);
    if (!fc[0] || !fc[1] || !fc[2])
        error_exit(2);
}

void init_fc(char *line, char *fc, t_info *info, t_ps *ps)
{
    char *rgb;

    rgb = line + 1;
    while (*rgb == ' ')
        rgb++;
    if (ft_strncmp(fc, "F", 1) == 0)
    {
        check_init_fc(info->f, rgb);
        ps->f_complete = 1;
    }
    else
    {
        check_init_fc(info->c, rgb);
        ps->c_complete = 1;
    }
}
