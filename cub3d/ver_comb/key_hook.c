/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 01:23:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double norm_Angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	while (angle > 2 * PI)
		angle = angle - 2 * PI;
	return (angle); // 맞나?
}

int key_hook(int keycode, void *param)
{
	t_info *info;

	// mlx_clear_window(info->mlx, info->win);
	info = (t_info *)param;
	info->rotationAngle += info->turnDirection * info->rotationSpeed;
	double moveStep = info->walkDirection * info->moveSpeed;
	info->x += cos(info->rotationAngle) * moveStep;
	info->y += sin(info->rotationAngle) * moveStep;

	double rayAngle = info->rotationAngle - (FOV_ANGLE / 2);
	for (int i = 0; i < NUM_RAYS; i++)
	{
		// horizontal
		rayAngle = norm_Angle(rayAngle);
		double wallHitX = 0;
		double wallHitY = 0;
		double distance = 0;

		int isRayFacingDown = (rayAngle > 0 && rayAngle < PI) ? 1:0;
		int isRayFacinUp = (isRayFacingDown) ? 0:1; 
		int isRayFacingRight = (rayAngle < 0.5 * PI || rayAngle > 1.5 * PI) ? 1:0;
		int isRayFacingLeft = (isRayFacingRight) ? 0:1; // 맞나?

		double xintercept, yintercept;
		double xstep, ystep;
		yintercept = floor(info->y / TILE_SIZE) * TILE_SIZE;
		xintercept = info->x + (yintercept - info->y) / 



		rayAngle += FOV_ANGLE / NUM_RAYS;
	}

	mlx_pixel_put(info->mlx, info->win, info->x, info->y, 0xFFFFFF);

	if (keycode == 65362)
	{
		info->walkDirection = 1;
		info->turnDirection = 0;
	}
	else if (keycode == 65364)
	{
		info->walkDirection = -1;
		info->turnDirection = 0; // 초기화를 안넣어주면 계속 곱해지는 문제 발생
	}
	else if (keycode == 65363)
	{
		info->walkDirection = 0;
		info->turnDirection = 1;
	}
	else if (keycode == 65361)
	{
		info->walkDirection = 0;
		info->turnDirection = -1;
	}
	printf("(%f,%f / %f)\n", info->x, info->y, info->rotationAngle);
	return (0);
}
