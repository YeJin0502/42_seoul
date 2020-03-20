#include <mlx.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('X');
}

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	mlx_pixel_put(mlx, win, 250, 250, 0xFFFFFF);
	mlx_key_hook(win, deal_key, (void *)0);
	
	mlx_loop(mlx);
}