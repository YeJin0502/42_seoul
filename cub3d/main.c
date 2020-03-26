/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 06:55:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_info *info;

	info = init_info(); // 아마 argc, argv를 매개변수로.
	// make_first_scene(info); // 이런식으로 짜는게 맞을까? 왜 첫번째 화면은 느리게 뜰까..?

	mlx_key_hook(info->win, key_hook, (void *)info); // 아마 나중에 mlx_hook으로 바꿔야 할 듯?
	mlx_loop(info->mlx);
}
