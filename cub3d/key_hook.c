/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 19:27:05 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double norm_Angle(double angle)
{
	if (angle < 0)
		angle = angle + 2 * PI;
	if (angle < 2 * PI)
		angle = remainder(angle, 2 * PI);
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

void draw_line(int x0, int y0, int x1, int y1, t_info *info) // 임시. 아마 안쓰겠지
{
	int dx = x1 - x0;
    int dy = y1 - y0;
    int steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    float Xi = (float)dx / (float)steps;
    float Yi = (float)dy / (float)steps; // float 안붙여주면 증가 안함
    
    float x = (float)x0, y = (float)y0;
    for (int v = 0; v < steps; v++)
    {
        x = x + Xi;
        y = y + Yi;
        mlx_pixel_put(info->mlx, info->win, round(x), round(y), 0xFF00FF);
    }
}

int key_hook(int keycode, void *param)
{
	t_info *info;
	t_cal *cal;

	info = (t_info *)param;
	cal = (t_cal *)malloc(sizeof(t_cal));
	mlx_clear_window(info->mlx, info->win);
	info->rotationAngle += info->turnDirection * info->rotationSpeed;
	cal->moveStep = info->walkDirection * info->moveSpeed;
	info->x += cos(info->rotationAngle) * cal->moveStep;
	info->y += sin(info->rotationAngle) * cal->moveStep;

	cal->rayAngle = info->rotationAngle - (FOV_ANGLE / 2);
	for (int i = 0; i < NUM_RAYS; i++)
	{
		cal->rayAngle = norm_Angle(cal->rayAngle);
		cal->wallHitX = 0;
		cal->wallHitY = 0;
		cal->distance = 0;
		cal->wasHitVertical = 0;

		cal->isRayFacingDown = (cal->rayAngle > 0 && cal->rayAngle < PI) ? 1 : 0;
		cal->isRayFacingUp = (cal->isRayFacingDown) ? 0 : 1;
		cal->isRayFacingRight = (cal->rayAngle < 0.5 * PI || cal->rayAngle > 1.5 * PI) ? 1 : 0;
		cal->isRayFacingLeft = (cal->isRayFacingRight) ? 0 : 1;

		// horizontal
		t_line *horz;
		horz = (t_line *)malloc(sizeof(t_line));

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

		yintercept = info->y + (xintercept - info->x) * tan(rayAngle);

		xstep = TILE_SIZE;
		xstep *= (isRayFacingLeft) ? -1:1;

		ystep = TILE_SIZE * tan(rayAngle);
		ystep *= (isRayFacingUp && ystep > 0) ? -1:1; // 여기 이해 안됨.
		ystep *= (isRayFacingDown && ystep < 0) ? -1:1;

		double nextVertTouchX = xintercept;
		double nextVertTouchY = yintercept;

		if (isRayFacingLeft)
			nextVertTouchX--;
		
		while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH
			&& nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT)
		{
			if (hasWallAt(nextVertTouchX, nextVertTouchY, info)) // hasWallAt 아직 함수 안만듦
			{
				foundVertWallHit = 1;
				vertWallHitX = nextVertTouchX;
				vertWallHitY = nextVertTouchY;
				break;
			}
			else
			{
				nextVertTouchX += xstep;
				nextVertTouchY += ystep;
			}
		}

		double horzHitDistance = (foundHorzWallHit) ?
			point_distance(info->x, info->y, horzWallHitX, horzWallHitY) : 10000000; // max_value가 뭐지? 왜 쓰는거지?
		double vertHitDistance = (foundVertWallHit) ?
			point_distance(info->x, info->y, vertWallHitX, vertWallHitY) : 10000000;

		wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
		wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
		distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
		wasHitVertical = (horzHitDistance < vertHitDistance) ? 0 : 1;

		// 레이캐스팅 렌더링
		double correctWallDistance = distance * cos(rayAngle - info->rotationAngle);
		double distancePlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		double wallStripeHeight = (TILE_SIZE / correctWallDistance) * distancePlane;

		double wallStart = (WINDOW_HEIGHT / 2) - (wallStripeHeight / 2);
		double wallEnd = (WINDOW_HEIGHT / 2) + (wallStripeHeight / 2);

		int j = wallStart - 1;
		while (++j < wallEnd)
			mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF);


		// rayAngle += FOV_ANGLE / NUM_RAYS;
		// draw_line(info->x, info->y, wallHitX, wallHitY, info);
		rayAngle += 0.001090; // 수정해야함
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
	return (0);
}
