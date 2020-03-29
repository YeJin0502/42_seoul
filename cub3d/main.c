/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/30 06:19:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_info *info;

    info = (t_info *)malloc(sizeof(t_info));
    ft_memset(info, 0, sizeof(t_info));
    init_info(argv[1], info);
    make_first_scene(info);
    mlx_key_hook(info->win, key_hook, (void *)info);
    mlx_loop(info->mlx);
    // free(info->map); // 루프를 끝내는 방법이 없나?
    // free(info);
}
