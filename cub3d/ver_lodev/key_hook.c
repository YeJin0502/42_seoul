/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/24 03:32:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, void *param)
{
	t_info *info;
	info = (t_info *)param;

	mlx_clear_window(info->mlx, info->win);
	for (int x = 0; x < w; x++)
	{
		info->key_flag = 0;
		double cameraX = 2 * x / (double)w - 1;
		double rayDirX = info->dirX + info->planeX * cameraX; // 광선이 가르키는 방향
		double rayDirY = info->dirY + info->planeY * cameraX;
		int mapX = (int)info->posX; // 블록(격자) 좌표
		int mapY = (int)info->posY;
		double sideDistX; // 첫 x 격자에 도달할 때 까지의 거리 // 여기부터 dda
		double sideDistY; // 첫 y 격자에 도달할 때 까지의 거리
		double deltaDistX; // 광선이 첫 x,y격자에서 다음 x,y 격자까지 이동하는 거리
		double deltaDistY; // deltaDistX,Y 사이의 비율만 따지면 되므로, abs(v/rayDirX,Y)에서 v가 1로 대체
		if (rayDirY == 0)
			deltaDistX = 0;
		else if (rayDirX == 0)
			deltaDistX = 1;
		else
			deltaDistX = abs(1/rayDirX);
		if (rayDirX == 0)
			deltaDistY = 0;
		else if (rayDirY == 0)
			deltaDistY = 1;
		else
			deltaDistY = abs(1/rayDirY);
		double perpWallDist;
		int stepX;
		int stepY;
		int hit = 0;
		int side;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX; // 닮음비 이용해서 구함
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		// dda 알고리즘
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (info->worldMap[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY; // 여기까지 dda
		int lineHeight = (int)(h / perpWallDist); // 모르겠음
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		int color;
		if (info->worldMap[mapX][mapY] == 1)
			color = 0xFF3333;
		else if (info->worldMap[mapX][mapY] == 2)
			color = 0x66CC66;
		else if (info->worldMap[mapX][mapY] == 3)
			color = 0x6666FF;
		else if (info->worldMap[mapX][mapY] == 4)
			color = 0xCCCCFF;
		else
			color = 0xFFFF66;
		for (int tmp_y = 0; tmp_y < drawStart; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0x6E8DED);
		for (int tmp_y = drawStart; tmp_y < drawEnd; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, color);
		for (int tmp_y = drawEnd; tmp_y < h; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0xFFFFFF);
	}
	double moveSpeed = info->frameTime * 5.0;
	double rotSpeed = info->frameTime * 3.0;
	if (keycode == 65362)
	{
		if (info->worldMap[(int)(info->posX + info->dirX * moveSpeed)][(int)(info->posY)] == 0)
			info->posX += info->dirX * moveSpeed;
		if (info->worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * moveSpeed)] == 0)
			info->posY += info->dirY * moveSpeed;
	}
	if (keycode == 65364)
	{
		if (info->worldMap[(int)(info->posX - info->dirX * moveSpeed)][(int)(info->posY)] == 0)
			info->posX -= info->dirX * moveSpeed;
		if (info->worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * moveSpeed)] == 0)
			info->posY -= info->dirY * moveSpeed;
	}
	double oldDirX = info->dirX;
	double oldPlaneX = info->planeX;
	if (keycode == 65363)
	{
		info->dirX = info->dirX * cos(-rotSpeed) - info->dirY * sin(-rotSpeed);
		info->dirY = oldDirX * sin(-rotSpeed) + info->dirY * cos(-rotSpeed);
		info->planeX = info->planeX * cos(-rotSpeed) - info->planeY * sin(-rotSpeed);
		info->planeY = oldPlaneX * sin(-rotSpeed) + info->planeY * cos(-rotSpeed);
	}
	if (keycode == 65361)
	{
		info->dirX = info->dirX * cos(rotSpeed) - info->dirY * sin(rotSpeed);
		info->dirY = oldDirX * sin(rotSpeed) + info->dirY * cos(rotSpeed);
		info->planeX = info->planeX * cos(rotSpeed) - info->planeY * sin(rotSpeed);
		info->planeY = oldPlaneX * sin(rotSpeed) + info->planeY * cos(rotSpeed);
	}
	printf("(%f,%f / %f,%f)\n", info->posX, info->posY, info->dirX, info->dirY);
	return (0);
}
