/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 00:29:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, void *param)
{
	
}

int main()
{
	t_info *info;
	info = make_info(); // 아마 argc, argv를 매개변수로.

	mlx_key_hook(info->win, key_hook, (void *)info); // 아마 나중에 mlx_hook으로 바꿔야 할 듯?
	mlx_loop(info->mlx);
}