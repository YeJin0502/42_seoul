/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 03:24:25 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double norm_Angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	while (angle >= 2 * PI)
		angle = angle - 2 * PI;
	return (angle); // 맞나?
}

int hasWallAt(double x, double y, t_info *info)
{
	int mapGridIndexX = floor(x / TILE_SIZE);
	int mapGridIndexY = floor(y / TILE_SIZE);

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (1);
	else if (info->grid[mapGridIndexY][mapGridIndexX] != 0)
		return (1);
	return (0);
} // 맞나?

double point_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
}

int key_hook(int keycode, void *param)
{
	t_info *info;

	mlx_clear_window(info->mlx, info->win);

	info = (t_info *)param;
	info->rotationAngle += info->turnDirection * info->rotationSpeed;
	double moveStep = info->walkDirection * info->moveSpeed;
	info->x += cos(info->rotationAngle) * moveStep;
	info->y += sin(info->rotationAngle) * moveStep;

	double rayAngle = info->rotationAngle - (FOV_ANGLE / 2);

	for (int i = 0; i < NUM_RAYS; i++)
	{
		// rayAngle = norm_Angle(rayAngle);

		double wallHitX = 0;
		double wallHitY = 0;
		double distance = 0;

		double xintercept, yintercept;
		double xstep, ystep;

		int isRayFacingDown = (rayAngle > 0 && rayAngle < PI) ? 1:0;
		int isRayFacingUp = (isRayFacingDown) ? 0:1; // 이런 삼항연산자 되나?
		int isRayFacingRight = (rayAngle < 0.5 * PI || rayAngle > 1.5 * PI) ? 1:0;
		int isRayFacingLeft = (isRayFacingRight) ? 0:1; // 맞나?

		int wasHitVertical = 0;

		// horizontal
		int foundHorzWallHit = 0;
		double horzWallHitX = 0;
		double horzWallHitY = 0;
		yintercept = floor(info->y / TILE_SIZE) * TILE_SIZE;
		yintercept += (isRayFacingDown) ? TILE_SIZE:0;
		xintercept = info->x + (yintercept - info->y) / tan(rayAngle);
		ystep = TILE_SIZE;
		ystep *= (isRayFacingUp) ? -1:1;
		xstep = TILE_SIZE / tan(rayAngle);
		xstep *= (isRayFacingLeft && xstep > 0) ? -1:1; // 여기 이해 안됨.
		xstep *= (isRayFacingRight && xstep < 0) ? -1:1; 
		double nextHorzTouchX = xintercept;
		double nextHorzTouchY = yintercept;
		if (isRayFacingUp)
			nextHorzTouchY--;
		while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH
			&& nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
		{
			if (hasWallAt(nextHorzTouchX, nextHorzTouchY, info)) // hasWallAt 아직 함수 안만듦
			{
				foundHorzWallHit = 1;
				horzWallHitX = nextHorzTouchX;
				horzWallHitY = nextHorzTouchY;
				break;
			}
			else
			{
				nextHorzTouchX += xstep;
				nextHorzTouchY += ystep;
			}
		}

		// vertical
		int foundVertWallHit = 0;
		double vertWallHitX = 0;
		double vertWallHitY = 0;
		xintercept = floor(info->x / TILE_SIZE) * TILE_SIZE;
		xintercept += (isRayFacingRight) ? TILE_SIZE:0;
		yintercept = info->y + (xintercept - info->x) / tan(rayAngle);
		xstep = TILE_SIZE;
		xstep *= (isRayFacingLeft) ? -1:1;
		ystep = TILE_SIZE / tan(rayAngle);
		ystep *= (isRayFacingUp && ystep > 0) ? -1:1; // 여기 이해 안됨.
		ystep *= (isRayFacingDown && ystep < 0) ? -1:1;
		double nextVertTouchX = xintercept;
		double nextVertTouchY = yintercept;
		if (isRayFacingLeft)
			nextVertTouchX--;
		while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH
			&& nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
		{
			if (hasWallAt(nextHorzTouchX, nextHorzTouchY, info)) // hasWallAt 아직 함수 안만듦
			{
				foundHorzWallHit = 1;
				vertWallHitX = nextHorzTouchX;
				vertWallHitY = nextHorzTouchY;
				break;
			}
			else
			{
				nextHorzTouchX += xstep;
				nextHorzTouchY += ystep;
			}
		}

		double horzHitDistance = (foundHorzWallHit) ?
			point_distance(info->x, info->y, horzWallHitX, horzWallHitY) : 10000; // max_value가 뭐지? 왜 쓰는거지?
		double vertHitDistance = (foundVertWallHit) ?
			point_distance(info->x, info->y, vertWallHitX, vertWallHitY) : 10000;

		wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
		wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
		distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
		wasHitVertical = (horzHitDistance < vertHitDistance) ? 0 : 1;

		// 레이캐스팅 렌더링
		double rayDistance = distance;
		double distancePlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		double wallStripeHeight = (TILE_SIZE / rayDistance) * distancePlane;

		double wallStart = (WINDOW_HEIGHT / 2) - (wallStripeHeight / 2);
		double wallEnd = (WINDOW_HEIGHT / 2) + (wallStripeHeight / 2);

		int j = wallStart - 1;
		while (++j < wallEnd)
			mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF);

		rayAngle += FOV_ANGLE / NUM_RAYS;
	}

	// mlx_pixel_put(info->mlx, info->win, info->x, info->y, 0xFFFFFF);

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
