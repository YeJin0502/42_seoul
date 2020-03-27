#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

// #define w 640
// #define h 480
#define w 800
#define h 400
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
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

double posX = 22, posY = 12;
double dirX = -1, dirY = 0;
double planeX = 0, planeY = 0.66;
double frameTime = 0.007;

int key_hook(int keycode, void *param)
{
	double moveSpeed = frameTime * 5.0;
	double rotSpeed = frameTime * 3.0;
	if (keycode == 65362)
	{
		if (worldMap[(int)(posX + dirX * moveSpeed)][(int)(posY)] == 0)
			posX += dirX * moveSpeed;
		if (worldMap[(int)(posX)][(int)(posY + dirY * moveSpeed)] == 0)
			posY += dirY * moveSpeed;
	}
	if (keycode == 65364)
	{
		if (worldMap[(int)(posX - dirX * moveSpeed)][(int)(posY)] == 0)
			posX -= dirX * moveSpeed;
		if (worldMap[(int)(posX)][(int)(posY - dirY * moveSpeed)] == 0)
			posY -= dirY * moveSpeed;
	}
	double oldDirX = dirX;
	double oldPlaneX = planeX;
	if (keycode == 65363)
	{
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (keycode == 65361)
	{
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
	printf("(%f,%f / %f,%f)\n", posX, posY, dirX, dirY);
	return 0;
}

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, "test");

	while (1)
	{
		for (int x = 0; x < w; x++)
		{
			double cameraX = 2 * x / (double)w - 1;
			double rayDirX = dirX + planeX * cameraX; // 광선이 가르키는 방향
			double rayDirY = dirY + planeY * cameraX;

			int mapX = (int)posX; // 블록(격자) 좌표
			int mapY = (int)posY;
			double sideDistX; // 첫 x 격자에 도달할 때 까지의 거리
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
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX; // 닮음비 이용해서 구함
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}

			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

			int lineHeight = (int)(h / perpWallDist); // 모르겠음
			int drawStart = -lineHeight / 2 + h / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if (drawEnd >= h)
				drawEnd = h - 1;

			// for (int tmp_y = 0; tmp_y < drawStart; tmp_y++)
			// 	mlx_pixel_put(mlx, win, x, tmp_y, 0x6E8DED);
			for (int tmp_y = drawStart; tmp_y < drawEnd; tmp_y++)
				mlx_pixel_put(mlx, win, x, tmp_y, 0xFFFFFF);
			// for (int tmp_y = drawEnd; tmp_y < h; tmp_y++)
			// 	mlx_pixel_put(mlx, win, x, tmp_y, 0xF86363);
			
		}
		// printf("[%d]\n",x);
		mlx_key_hook(win, key_hook, (void *)0);
		// mlx_loop(mlx);
	}
}
