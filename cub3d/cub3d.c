/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 00:58:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int key_hook(int keycode, void *param)
// {
// 	t_info *info;

// 	info = (t_info *)param;

	
// }

void make_2d_map(t_info *info)
{
	int i;
	int j;
	int a;
	int b;

	i = -1;
	while (++i < info->map_height)
	{
		j = -1;
		while (++j < info->map_width)
		{
			a = -1;
			while (++a < )
		}
	}
}

int main()
{
	t_info *info;
	info = make_info(); // 아마 argc, argv를 매개변수로.

	make_2d_map(info);

	// mlx_key_hook(info->win, key_hook, (void *)info); // 아마 나중에 mlx_hook으로 바꿔야 할 듯?
	mlx_loop(info->mlx);
}