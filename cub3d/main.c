/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/31 06:47:21 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_info *info;

    if (!(argc == 2 || (argc == 3 && ft_strncmp(argv[2], "--save", sizeof(argv[2])) == 0)))
    {
        perror("Error\n");
        exit(1); // 도대체 어떻게 쓰는거여 perror...
    }
    info = (t_info *)malloc(sizeof(t_info));
    ft_memset(info, 0, sizeof(t_info));
    info->argc = argc;
    init_info(argv[1], info);
    make_first_scene(info);
    if (argc == 3)
    {
        int fd;
        fd = open("image.bmp", O_RDWR | O_CREAT, 744); // 이렇게 하는건가?
        save_bmp(fd, info->scene);
        return (0);
    }
    else
    {
        mlx_key_hook(info->win, key_hook, (void *)info);
        mlx_loop(info->mlx);
    }
    // free(info->map); // 루프를 끝내는 방법이 없나?
    // free(info);
}
