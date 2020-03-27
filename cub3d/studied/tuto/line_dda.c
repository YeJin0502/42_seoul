#include <mlx.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "test");

    int x0 = 100, y0 = 100;
    int x1 = 400, y1 = 300;
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
        mlx_pixel_put(mlx, win, round(x), round(y), 0xFFFFFF);
    }
    mlx_loop(mlx); // 중간에 써주면 뭘 그려도 검은 화면 뜬다.
}