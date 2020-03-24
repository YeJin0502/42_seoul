/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:09:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 04:17:38 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	for (int a = 0; a < MAP_NUM_ROWS; a++)
	{
		for (int b = 0; b < MAP_NUM_COLS; b++)
		{
			int tileX = b * TILE_SIZE;
			int tileY = a * TILE_SIZE;
			int color = (info->grid[a][b] == 1) ? 0xFFFFFF : 0x000000;
			for (int c = 0; c < TILE_SIZE; c++)
				for (int d = 0; d < TILE_SIZE; d++)
					mlx_pixel_put(info->mlx, info->win, tileX+c, tileY+d, color);
		}
	}	

////////////////////
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
		int wasHitVertical = 0;

		int isRayFacingDown = (rayAngle > 0 && rayAngle < PI) ? 1:0;
		int isRayFacingUp = (isRayFacingDown) ? 0:1; // 이런 삼항연산자 되나?
		int isRayFacingRight = (rayAngle < 0.5 * PI || rayAngle > 1.5 * PI) ? 1:0;
		int isRayFacingLeft = (isRayFacingRight) ? 0:1; // 맞나?

		double xintercept = 0;
		double yintercept = 0;
		double xstep = 0;
		double ystep = 0;

		// horizontal
		int foundHorzWallHit = 0;
		double horzWallHitX = 0;
		double horzWallHitY = 0;

		yintercept = floor(info->y / TILE_SIZE) * TILE_SIZE;
		yintercept += (isRayFacingDown) ? TILE_SIZE : 0;

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
			point_distance(info->x, info->y, horzWallHitX, horzWallHitY) : 10000000000; // max_value가 뭐지? 왜 쓰는거지?
		double vertHitDistance = (foundVertWallHit) ?
			point_distance(info->x, info->y, vertWallHitX, vertWallHitY) : 10000000000;

		wallHitX = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
		wallHitY = (horzHitDistance < vertHitDistance) ? horzWallHitY : vertWallHitY;
		distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
		wasHitVertical = (horzHitDistance < vertHitDistance) ? 0 : 1;

		///////////////////

		draw_line(info->x, info->y, wallHitX, wallHitY, info);
printf("(%d / %f / %f)\n", wasHitVertical, horzHitDistance, vertHitDistance);

		// // 레이캐스팅 렌더링
		// double rayDistance = distance;
		// double distancePlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		// double wallStripeHeight = (TILE_SIZE / rayDistance) * distancePlane;

		// double wallStart = (WINDOW_HEIGHT / 2) - (wallStripeHeight / 2);
		// double wallEnd = (WINDOW_HEIGHT / 2) + (wallStripeHeight / 2);

		// int j = wallStart - 1;
		// while (++j < wallEnd)
		// 	mlx_pixel_put(info->mlx, info->win, i, j, 0xFFFFFF);

		rayAngle += FOV_ANGLE / NUM_RAYS;
	}
////////////////////

	// mlx_key_hook(info->win, key_hook, info);
	mlx_loop(info->mlx);
}
