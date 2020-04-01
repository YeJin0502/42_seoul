/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 23:46:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 14:42:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_check(t_info *info)
{
    int i;
    int j;

    i = -1;
    while (++i < info->map_width)
        if (info->map[0][i] != 1 || info->map[info->map_height - 1][i] != 1)
            error_exit(1);
    i = -1;
    while (++i < info->map_height)
        if (info->map[i][0] != 1 || info->map[i][info->map_width - 1] != 1)
            error_exit(1);
}
