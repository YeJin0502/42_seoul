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
    int img_w;
    int img_h;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "test");
    img = mlx_xpm_file_to_image(mlx, "redbrick.xpm", &img_w, &img_h); // mlx_new_image 랑 똑같은걸 반환하는건가?

    char *img_data;    
    int bpp;
    int size_line;
    int endian;

    mlx_put_image_to_window(mlx, win, img, 200, 200);
    img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    unsigned int color = mlx_get_color_value(mlx, 0xFFFFFF);
    printf("%u\n", color); // FFFFFF의 10진수 변환이 뜸.

    int i;
    int j;

    mlx_string_put(mlx, win, 200, 200, 16777215, "hello"); // 16진수가 아니라 10진수를 넣어도 됨!
    // i = -1;
    // while (++i < )
    // mlx_pixel_put();

    mlx_loop(mlx);
}
