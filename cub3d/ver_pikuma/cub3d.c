/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:22:45 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 00:06:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int grid[MAP_NUM_ROWS][MAP_NUM_COLS] =
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
}; // ; 안붙여주면 안되나? // 일단은 전역변수

t_info *setup()
{
	// 목표: 초기화?

}

void update()
{
	// 다음 프레임에서 렌더링 하기 전에 상태 업데이트
}

void rect(t_point p1, int x, int y, t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
			mlx_pixel_put(info->mlx, info->win, p1.x + i, p1.y + j, 0xFFFFFF);
	}
}

void map_render(t_info *info)
{
	int i;
	int j;
	t_point tile;

	i = -1;
	while (++i < MAP_NUM_ROWS)
	{
		j = -1;
		while (++j < MAP_NUM_COLS)
		{
			tile.x = j * TILE_SIZE;
			tile.y = i * TILE_SIZE;
			// rect(tile, TILE_SIZE, TILE_SIZE, info);
		}
	}
}

void draw()
{
	update();
	// 목표: 프레임(?)마다 렌더링
	

}

int main()
{
	void *mlx_value;
	void *win_value;
	t_info *info;

	mlx_value = mlx_init();
	win_value = mlx_new_window(mlx_value, WINDOW_WIDTH, WINDOW_HEIGHT, "test");
	info = (t_info *)malloc(sizeof(t_info));
	info->mlx = mlx_value;
	info->win = win_value;
}