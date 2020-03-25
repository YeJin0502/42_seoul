/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 00:22:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 00:49:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int w = 640; // 전역변수는 나중에 맵에서 읽어야할 정보들.
int h = 480; // 지금은 임시로 전역변수로.
double d = 1 / 2 * PI;
int Map[11][15] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void *make_info() // 아마 매개변수로 argc, argv 받지않을까?
{
	t_info *info;
	void *mlx_value;
	void *win_value;

	info = (t_info *)malloc(sizeof(t_info));
	info->R_width = w;
	info->R_height = h;
	/* 이 사이에 NO~C 까지... 만들어야함 */
	info->dir = d;
	info->map = Map;
	info->map_width = 15;
	info->map_height = 11;
	info->tile_width = info->R_width / info->map_width; // 맵이 화면보다 더 큰경우 있어서 또 예외처리 해줘야됨.
	info->tile_height = info->R_height / info->map_height; // 이부분 헷갈릴수 있음. 확인 필요.
	info->x = h / 2;
	info->y = w / 2;
	mlx_value = mlx_init();
	win_value = mlx_new_window(mlx_value, info->R_height, info->R_width, "moon");
	info->mlx = mlx_value;
	info->win = win_value;
	return (info);
}
