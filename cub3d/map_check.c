/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 23:46:53 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 00:31:10 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_check(t_info *info)
{
    int i;
    int j;

    i = -1;
    while (++i < info->map_width)
        if (info->map[0][i] != 1 || info->map[info->map_height - 1][i] != 1)
            return (1); // 뭘 리턴해야 하지? 헷갈리는데...
    i = -1;
    while (++i < info->map_height)
        if (info->map[i][0] != 1 || info->map[i][info->map_width - 1] != 1)
            return (1);
    return (0);
}
