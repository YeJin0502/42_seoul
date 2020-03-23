/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/24 01:44:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int keycode, void *param)
{
	t_info *info;
	info = (t_info *)param;

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
	return 0;
}
