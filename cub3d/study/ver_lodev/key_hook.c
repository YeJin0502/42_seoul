/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 20:40:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, void *param)
{
	t_info *info;
	t_cal *cal;

	info = (t_info *)param;
	cal = (t_cal *)malloc(sizeof(t_cal));
	mlx_clear_window(info->mlx, info->win);

	for (int x = 0; x < w; x++)
	{
		cal->cameraX = 2 * x / (double)w - 1;
		cal->rayDirX = info->dirX + info->planeX * cal->cameraX; 
		cal->rayDirY = info->dirY + info->planeY * cal->cameraX;
		cal->mapX = (int)info->posX;
		cal->mapY = (int)info->posY;

		if (cal->rayDirY == 0)
			cal->deltaDistX = 0;
		else if (cal->rayDirX == 0)
			cal->deltaDistX = 1;
		else
			cal->deltaDistX = abs(1 / cal->rayDirX);
		if (cal->rayDirX == 0)
			cal->deltaDistY = 0;
		else if (cal->rayDirY == 0)
			cal->deltaDistY = 1;
		else
			cal->deltaDistY = abs(1 / cal->rayDirY);

		if (cal->rayDirX < 0)
		{
			cal->stepX = -1;
			cal->sideDistX = (info->posX - cal->mapX) * cal->deltaDistX;
		}
		else
		{
			cal->stepX = 1;
			cal->sideDistX = (cal->mapX + 1.0 - info->posX) * cal->deltaDistX; // 닮음비 이용해서 구함
		}
		if (cal->rayDirY < 0)
		{
			cal->stepY = -1;
			cal->sideDistY = (info->posY - cal->mapY) * cal->deltaDistY;
		}
		else
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

		// 레이캐스팅 높이 계산
		if (cal->side == 0)
			cal->perpWallDist = (cal->mapX - info->posX + (1 - cal->stepX) / 2) / cal->rayDirX;
		else
			cal->perpWallDist = (cal->mapY - info->posY + (1 - cal->stepY) / 2) / cal->rayDirY; // 여기까지 dda
		cal->lineHeight = (int)(h / cal->perpWallDist); // 모르겠음
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
		for (int tmp_y = 0; tmp_y < cal->drawStart; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0x6E8DED);
		for (int tmp_y = cal->drawStart; tmp_y < cal->drawEnd; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, cal->color);
		for (int tmp_y = cal->drawEnd; tmp_y < h; tmp_y++)
			mlx_pixel_put(info->mlx, info->win, x, tmp_y, 0xFFFFFF);
	}
	// image_pointer = mlx_new_image(info->mlx, w, h);
	double moveSpeed = info->frameTime * 5.0;
	double rotSpeed = info->frameTime * 3.0;
	double oldDirX = info->dirX;
	double oldPlaneX = info->planeX;
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
