#include <mlx.h>

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");

	int x0 = 100, y0 = 130;
	int x1 = 380, y1 = 300;

	int dx = x1 - x0;
	int dy = y1 - y0;
	int D = 2 * dy - dx;

	while (x0 <= x1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0xFFFFFF);
		if (D > 0)
		{
			y0 += 1;
			D -= 2 * dx;
		}
		D += 2 * dy;
		x0++;
	}
	mlx_loop(mlx);
}