#include <mlx.h>
#include <stdio.h>

// int main()
// {
//     void *mlx;
//     void *win;
//     void *img;
//     int a = 100;
//     int b = 100;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 640, 480, "test");
//     img = mlx_xpm_file_to_image(mlx, "redbrick.xpm", &a, &b);
//     mlx_put_image_to_window(mlx, win, img, 200, 300);
//     mlx_loop(mlx);
// }

int main()
{
    void *mlx;
    void *win;
    void *img;
    int a;
    int b;
    int bpp;
    int size_line;
    int endian;
    char *adr;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "test");
    img = mlx_xpm_file_to_image(mlx, "redbrick.xpm", &a, &b);
    printf("(%d,%d)\n", a, b); // a, b에 가로 세로 길이 저장됨.
    mlx_put_image_to_window(mlx, win, img, 200, 200);
    adr = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    printf("[%d,%d,%d]\n", bpp, size_line, endian);
    printf("<%s>\n", adr);
    // mlx_pixel_put();

    mlx_loop(mlx);
}
