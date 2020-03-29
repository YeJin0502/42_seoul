/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 22:15:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv) // **로 하면 안되지않았나?
{
    t_info *info;

    parsing(argv[1], info);
    info = init_info(); // 아마 argc, argv를 매개변수로.

    // int i;
    // i = -1;
    // while (++i < 15)
    //     printf("%d\n", info->map[0][i]);
    
    
    make_first_scene(info); // 이런식으로 짜는게 맞을까? 왜 첫번째 화면은 느리게 뜰까..?
    mlx_key_hook(info->win, key_hook, (void *)info); // 아마 나중에 mlx_hook으로 바꿔야 할 듯?
    mlx_loop(info->mlx);
}
