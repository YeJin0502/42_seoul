#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 256, 256, "test");
    x = 0;
    while (x < 256)
    {
        y = 0;
        while (y < 256)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
            y++;
        }
        x++;
    }
    mlx_loop(mlx_ptr);
}
// 신기한 모양이 나옴! 근데 무지개색은 어떻게 하는걸까? 색깔 계산 아직 모르겠다.
// 색 만드는 함수가 필요한건가?