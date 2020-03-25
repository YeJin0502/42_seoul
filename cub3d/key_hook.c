/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:01:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 22:25:39 by gmoon            ###   ########.fr       */
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
	int mapGridIndexX = floor(x / TILESIZE_Y);
	int mapGridIndexY = floor(y / TILESIZE_X);

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

void draw_line(int x0, int y0, int x1, int y1, t_info *info)
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
	cal->moveStep = info->walkDirection * info->moveSpeed;
	info->rotationAngle += info->turnDirection * info->rotationSpeed; // 뭔가 순서가 중요한 듯.
	info->x += cos(info->rotationAngle) * cal->moveStep;
	info->y += sin(info->rotationAngle) * cal->moveStep;
	cal->rayAngle = info->rotationAngle - ((FOV_ANGLE) / 2);

// printf("(%f,%f)", info->rotationAngle*180/PI, cal->rayAngle*180/PI);
	// 테스트용 2d 맵
	for (int a = 0; a < MAP_NUM_ROWS; a++)
	{
		for (int b = 0; b < MAP_NUM_COLS; b++)
		{
			int tileX = b * TILESIZE_X;
			int tileY = a * TILESIZE_Y;
			int color = (info->grid[a][b] == 1) ? 0xFFFFFF : 0x000000;
			for (int c = 0; c <= TILESIZE_X; c++)
				for (int d = 0; d <= TILESIZE_Y; d++)
					mlx_pixel_put(info->mlx, info->win, tileX+c, tileY+d, color);
		}
	}

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

		//////////////////////////////
		// horizontal
		//////////////////////////////
		t_line *horz;
		horz = (t_line *)malloc(sizeof(t_line));

		horz->foundWallHit = 0;
		horz->WallHitX = 0;
		horz->WallHitY = 0;

		cal->yintercept = floor(info->y / TILESIZE_Y) * TILESIZE_Y;
		cal->yintercept += (cal->isRayFacingDown) ? TILESIZE_Y : 0;

		cal->xintercept = info->x + (cal->yintercept - info->y) / tan(cal->rayAngle);

		cal->ystep = TILESIZE_Y;
		cal->ystep *= (cal->isRayFacingUp) ? -1 : 1;

		cal->xstep = TILESIZE_Y / tan(cal->rayAngle);
		cal->xstep *= (cal->isRayFacingLeft && cal->xstep > 0) ? -1 : 1; // 여기 이해 안됨.
		cal->xstep *= (cal->isRayFacingRight && cal->xstep < 0) ? -1 : 1; 
		horz->nextTouchX = cal->xintercept;
		horz->nextTouchY = cal->yintercept;

		if (cal->isRayFacingUp)
			horz->nextTouchY--; // 다듬기할때 삭제하긴함
		
		while (horz->nextTouchX >= 0 && horz->nextTouchX <= WINDOW_WIDTH
			&& horz->nextTouchY >= 0 && horz->nextTouchY <= WINDOW_HEIGHT)
		{
			if (hasWallAt(horz->nextTouchX, horz->nextTouchY, info))
			{
				horz->foundWallHit = 1;
				horz->WallHitX = horz->nextTouchX;
				horz->WallHitY = horz->nextTouchY;
				break;
			}
			else
			{
				horz->nextTouchX += cal->xstep;
				horz->nextTouchY += cal->ystep;
			}
		}
		
		//////////////////////////////
		// vertical
		//////////////////////////////
		t_line *vert;
		vert = (t_line *)malloc(sizeof(t_line));
		vert->foundWallHit = 0;
		vert->WallHitX = 0;
		vert->WallHitY = 0;

		cal->xintercept = floor(info->x / TILESIZE_X) * TILESIZE_X; // 재사용해도 되나? 원래 그런가?
		cal->xintercept += (cal->isRayFacingRight) ? TILESIZE_X : 0;

		cal->yintercept = info->y + (cal->xintercept - info->x) * tan(cal->rayAngle);

		cal->xstep = TILESIZE_X;
		cal->xstep *= (cal->isRayFacingLeft) ? -1 : 1;

		cal->ystep = TILESIZE_X * tan(cal->rayAngle);
		cal->ystep *= (cal->isRayFacingUp && cal->ystep > 0) ? -1 : 1; // 여기 이해 안됨.
		cal->ystep *= (cal->isRayFacingDown && cal->ystep < 0) ? -1 : 1;

		vert->nextTouchX = cal->xintercept;
		vert->nextTouchY = cal->yintercept;

		if (cal->isRayFacingLeft)
			vert->nextTouchX--;
		
		while (vert->nextTouchX >= 0 && vert->nextTouchX <= WINDOW_WIDTH
			&& vert->nextTouchY >= 0 && vert->nextTouchY <= WINDOW_HEIGHT)
		{
			if (hasWallAt(vert->nextTouchX, vert->nextTouchY, info))
			{
				vert->foundWallHit = 1;
				vert->WallHitX = vert->nextTouchX;
				vert->WallHitY = vert->nextTouchY;
				break;
			}
			else
			{
				vert->nextTouchX += cal->xstep;
				vert->nextTouchY += cal->ystep;
			}
		}

		horz->HitDistance = (horz->foundWallHit) ?
			point_distance(info->x, info->y, horz->WallHitX, horz->WallHitY) : 10000000; // 정확하게 하려면 최댓값으로 바꿀 것.
		vert->HitDistance = (vert->foundWallHit) ?
			point_distance(info->x, info->y, vert->WallHitX, vert->WallHitY) : 10000000;

		cal->wallHitX = (horz->HitDistance < vert->HitDistance) ? horz->WallHitX : vert->WallHitX;
		cal->wallHitY = (horz->HitDistance < vert->HitDistance) ? horz->WallHitY : vert->WallHitY;
		cal->distance = (horz->HitDistance < vert->HitDistance) ? horz->HitDistance : vert->HitDistance;
		cal->wasHitVertical = (horz->HitDistance < vert->HitDistance) ? 0 : 1;
		
		//////////////////////////////
		// 레이캐스팅 렌더링
		//////////////////////////////
		// cal->WallDistance = cal->distance * cos(cal->rayAngle - info->rotationAngle);
		// cal->distancePlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		// cal->wallStripeHeight = (((cal->wasHitVertical) ? TILESIZE_X : TILESIZE_Y) / cal->WallDistance) * cal->distancePlane;

		// cal->wallStart = (WINDOW_HEIGHT / 2) - (cal->wallStripeHeight / 2);
		// cal->wallEnd = (WINDOW_HEIGHT / 2) + (cal->wallStripeHeight / 2);

		// int j;
		// j = cal->wallStart - 1;
		// while (++j < cal->wallEnd)
		// 	mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF);

		draw_line(info->x, info->y, cal->wallHitX, cal->wallHitY, info);
		// cal->rayAngle += (FOV_ANGLE) / (NUM_RAYS);
		cal->rayAngle += 0.001090; // 수정해야함

	}

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
