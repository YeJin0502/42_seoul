/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:09:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 19:20:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// #define PI 3.141591
// #define TILE_SIZE 64
// #define MAP_NUM_ROWS 11
// #define MAP_NUM_COLS 15
// #define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
// #define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE
// #define FOV_ANGLE 60 * PI / 180
// #define WALL_STRIP_WIDTH 1
// #define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

int Map[MAP_NUM_ROWS][MAP_NUM_COLS] =
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
	info->grid = Map;
	info->x = WINDOW_WIDTH / 2;
	info->y = WINDOW_HEIGHT / 2;
	info->turnDirection = 0;
	info->walkDirection = 0;
	info->rotationAngle = PI / 2;
	info->moveSpeed = 2;
	info->rotationSpeed = 2 * (PI / 180);

	// 2d 맵 렌더링
	// for (int a = 0; a < MAP_NUM_ROWS; a++)
	// {
	// 	for (int b = 0; b < MAP_NUM_COLS; b++)
	// 	{
	// 		int tileX = b * TILE_SIZE;
	// 		int tileY = a * TILE_SIZE;
	// 		int color = (info->grid[a][b] == 1) ? 0xFFFFFF : 0x000000;
	// 		for (int c = 0; c < TILE_SIZE; c++)
	// 			for (int d = 0; d < TILE_SIZE; d++)
	// 				mlx_pixel_put(info->mlx, info->win, tileX+c, tileY+d, color);
	// 	}
	// }

	mlx_key_hook(info->win, key_hook, info);
	mlx_loop(info->mlx);
}
