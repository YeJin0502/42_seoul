/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/17 01:27:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info *info;

	if (!(argc == 2 || (argc == 3
		&& ft_strncmp(argv[2], "--save", sizeof(argv[2])) == 0)))
		error_exit(1);
	info = init_info(argc, argv[1]);
	make_first_scene(info);
	if (argc == 3)
	{
		save_bmp_image(info->scene, argv[1]);
		exit(0);
	}
	else
	{
		mlx_key_hook(info->win, key_hook, (void *)info);
		mlx_hook(info->win, 17, 1L << 17, press_x_button, (void *)0);
		mlx_loop(info->mlx);
	}
}
