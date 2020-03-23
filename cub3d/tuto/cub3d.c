/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:24:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/23 23:25:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int grid_size = 64;
int worldMap[4][4]=
{
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1}
};
int FOV = 60;
int window_w = 320;
int window_h = 200;
int map_w = 256;
int map_h = 256;
int posX = 96;
int posY = 160;
int dirX = 1;
int dirY = 1;

int plane_dst = 277; // tan으로 직접 계산 가능.
int d_degree = 60/320; // 이거도 계산 가능한 값.

// 라디안과 디그리: 60도 = 60*pi/180라디안

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, window_w, window_h, "test");

	int x;
	x = -1;
	while (++x <= window_w)
	{
		
	}

}