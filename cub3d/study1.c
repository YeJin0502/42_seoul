#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <unistd.h>
#include <math.h>

/*
typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int main(void)
{
    data_t        data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
*/

/*
// introduction to minilibX
int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    mlx_loop(mlx_ptr);
}
*/

/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int deal_key(int key, void *param)
{
    ft_putchar('X');
    return 0;
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    char *str = "hello";

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_string_put(mlx_ptr, win_ptr, 350, 350, 0xFFFFFF, str);
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr);
}
*/

/*
// 정사각형
int main()
{
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "moongua");
	x = 100;
	y = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
			mlx_pixel_put(mlx, win, x, y++, 0xff0000);
		x++;
	}
    mlx_loop(mlx);
}
*/

/*
// 원
int main()
{
	void *mlx;
	void *win;
	int x;
	int y;
	int o;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "moongua");
	o = 200;
	x = 0;
	while (x <= 400)
	{
		y = 0;
		while (y <= 400)
		{
			if ((x - o)*(x - o) + (y - o)*(y - o) <= 10000)
				mlx_pixel_put(mlx, win, x, y, 0xff0000);
			y++;
		}
		x++;
	}
    mlx_loop(mlx); // 없으면 바로 창 꺼짐
}
*/

// 삼각형은 삼각형인데... y축이 반대다보니... 뒤집어진 정삼각형임.
int main()
{
	void *mlx;
	void *win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "dmdkr");

	int dx;
	int dy;
	int o;
	int x = o + dx;
	int y = o + dy;

	o = 200;
	dx = -200;
	while (dx <= 200)
	{
		dy = -200;
		while (dy <= 200)
		{
			if ((dy - 2*dx <= 100 && dy >= 0 && dx <= 0) ||
				(dy + 2*dx <= 100 && dy >= 0 && dx >= 0))
				mlx_pixel_put(mlx, win, o + dx, o + dy, 0xff0000);
			dy++;
		}
		dx++;
	}
	mlx_loop(mlx); // 없으면 바로 창 꺼짐
}
