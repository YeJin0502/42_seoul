/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:09:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 17:53:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int Map[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	void *mlx_value;
	void *win_value;
	t_info *info;

	mlx_value = mlx_init();
	win_value = mlx_new_window(mlx_value, w, h, "test");
	info = (t_info *)malloc(sizeof(t_info));
	info->mlx = mlx_value;
	info->win = win_value;
	info->worldMap = Map;
	info->posX = mapWidth / 2;
	info->posY = mapHeight / 2;
	// info->dirX = -1;
	// info->dirY = 0;
	// info->planeX = 0;
	// info->planeY = 0.66;
	info->fov = 60 * PI / 180; // 라디안
	info->dir = PI; // 라디안
	info->frameTime = 0.004;

	t_cal *cal;
	cal = (t_cal *)malloc(sizeof(t_cal));
	double rayDir = info->dir - (info->fov / 2);
	for (int x = 0; x < w; x++)
	{
		// cal->cameraX = 2 * x / (double)w - 1;
		// cal->rayDirX = info->dirX + info->planeX * cal->cameraX; 
		// cal->rayDirY = info->dirY + info->planeY * cal->cameraX;
		
		cal->mapX = (int)info->posX;
		cal->mapY = (int)info->posY;

		// if (cal->rayDirY == 0)
		// 	cal->deltaDistX = 0;
		// else if (cal->rayDirX == 0)
		// 	cal->deltaDistX = 1;
		// else
		// 	cal->deltaDistX = abs(1 / cal->rayDirX);
		// if (cal->rayDirX == 0)
		// 	cal->deltaDistY = 0;
		// else if (cal->rayDirY == 0)
		// 	cal->deltaDistY = 1;
		// else
		// 	cal->deltaDistY = abs(1 / cal->rayDirY);

		cal->deltaDistX = 1 / cos(rayDir); // 위처럼 0인 경우 예외처리가 필요할 듯.
		cal->deltaDistY = 1 / sin(rayDir);

		if (1/2 * PI < rayDir && rayDir < 3/2 * PI) // 왼쪽
		{
			cal->stepX = -1;
			cal->sideDistX = (info->posX - cal->mapX) * cal->deltaDistX;
		}
		else // 오른쪽
		{
			cal->stepX = 1;
			cal->sideDistX = (cal->mapX + 1.0 - info->posX) * cal->deltaDistX; // 닮음비 이용해서 구함
		}
		if (0 < rayDir && rayDir < PI) // 우리가 보기에 아래? 헷갈리네
		{
			cal->stepY = -1;
			cal->sideDistY = (info->posY - cal->mapY) * cal->deltaDistY;
		}
		else // 우리가 보기에 위?
		{
			cal->stepY = 1;
			cal->sideDistY = (cal->mapY + 1.0 - info->posY) * cal->deltaDistY;
		}
		
		// dda 알고리즘
		cal->hit = 0;
		while (cal->hit == 0)
		{
			if (cal->sideDistX < cal->sideDistY)
			{
				cal->sideDistX += cal->deltaDistX;
				cal->mapX += cal->stepX;
				cal->side = 0;
			}
			else
			{
				cal->sideDistY += cal->deltaDistY;
				cal->mapY += cal->stepY;
				cal->side = 1;
			}
			if (info->worldMap[cal->mapX][cal->mapY] > 0)
				cal->hit = 1;
		}
		// draw_line(info->posX, info->posY, info->posX + cos(rayDir) * 30, info->posY + sin(rayDir) * 30, info);

		// // 레이캐스팅 렌더링
		// double rayDistance = distance;
		// double distancePlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		// double wallStripeHeight = (TILE_SIZE / rayDistance) * distancePlane;

		// double wallStart = (WINDOW_HEIGHT / 2) - (wallStripeHeight / 2);
		// double wallEnd = (WINDOW_HEIGHT / 2) + (wallStripeHeight / 2);

		// int j = wallStart - 1;
		// while (++j < wallEnd)
		// 	mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF);

		// 레이캐스팅 높이 계산
		if (cal->side == 0)
			// cal->perpWallDist = (cal->mapX - info->posX + (1 - cal->stepX) / 2) / cal->rayDirX;
			cal->perpWallDist = cal->sideDistY;
		else
			cal->perpWallDist = cal->sideDistX;
			// cal->perpWallDist = (cal->mapY - info->posY + (1 - cal->stepY) / 2) / cal->rayDirY; // 여기까지 dda
		cal->lineHeight = (int)((w / 2) / tan(info->fov / 2) / cal->perpWallDist); // 모르겠음
		cal->drawStart = -(cal->lineHeight / 2) + h / 2;
		if (cal->drawStart < 0)
			cal->drawStart = 0;
		cal->drawEnd = (cal->lineHeight / 2) + h / 2;
		if (cal->drawEnd >= h)
			cal->drawEnd = h - 1;

		// 색 결정
		if (info->worldMap[cal->mapX][cal->mapY] == 1)
			cal->color = 0xFF3333;
		else if (info->worldMap[cal->mapX][cal->mapY] == 2)
			cal->color = 0x66CC66;
		else if (info->worldMap[cal->mapX][cal->mapY] == 3)
			cal->color = 0x6666FF;
		else if (info->worldMap[cal->mapX][cal->mapY] == 4)
			cal->color = 0xCCCCFF;
		else
			cal->color = 0xFFFF66;

		// 레이캐스팅 렌더링
		// for (int tmp_y = 0; tmp_y < cal->drawStart; tmp_y++)
			// mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0x6E8DED);
		for (int tmp_y = cal->drawStart; tmp_y < cal->drawEnd; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, cal->color);
		// for (int tmp_y = cal->drawEnd; tmp_y < h; tmp_y++)
			// mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0xFFFFFF);

		rayDir += info->fov / w;
	}

	// mlx_key_hook(info->win, key_hook, info);
	mlx_loop(info->mlx);
}
