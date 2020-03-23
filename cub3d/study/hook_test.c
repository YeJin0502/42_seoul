#include "cub3d.h"

typedef struct s_point
{
	int x;
	int y;
}				t_point;

void *mlx;
void *win;

int deal_key(int key, void *param)
{
	t_point *p;
	p = (t_point *)param;

	// printf("%d\n", key);
	if (key == 65362)
	{
		(*p).y -= 1;
	}
	mlx_string_put(mlx, win, p->x, p->y, 0xFF00FF, "hello");
	printf("%d\n", (*p).y);
}

int main()
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "test");

	t_point *p;
	p = (t_point *)malloc(sizeof(t_point));

	p->x = 150;
	p->y = 150;

	while (1)
	{
		mlx_string_put(mlx, win, p->x, p->y, 0xFFFFFF, "hi");	
		mlx_key_hook(win, deal_key, p);
		if (p->y != 150)
			mlx_string_put(mlx, win, p->x, p->y, 0xFF00FF, "hi");
		mlx_loop(mlx);
	}
}
