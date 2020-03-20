#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int worldMap[6][6]=
{
	{1,1,1,1,1,1},
	{1,0,0,1,0,1},
	{1,0,2,0,0,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}
};

#define w 320
#define h 200
#define FOV 60
#define dir 277 // 이런거 math 라이브러리 이용해서 tan 계산해야 할 듯.
#define pi 3.141592 // 이건 어떻게 해야하지..?
#define d_degree 60 / 320 * pi / 180

int main()
{
	void *mlx;
	void *win;
	int x;

	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, "test");
	x = -1;
	while (++x < w)
	{

	}
}