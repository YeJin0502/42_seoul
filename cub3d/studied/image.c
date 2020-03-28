#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int pixel_color(unsigned char *image, int x, int y, int size_line)
{
    int b_i;
    int g_i;
    int r_i;
	int color;

    b_i = (int)image[x * 4 + size_line * y ];
    g_i = (int)image[x * 4 + size_line * y + 1];
    r_i = (int)image[x * 4 + size_line * y + 2];
	color = 0x000000;
	color += b_i;
	color += 16 * 16 * g_i;
	color += 16 * 16 * 16 * 16 * r_i;
	return (color);
}

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_w, img_h;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "test");
    img = mlx_xpm_file_to_image(mlx, "test.xpm", &img_w, &img_h); // mlx_new_image 랑 똑같은걸 반환하는건가?
    unsigned char *image_data;
    int bpp, size_line, endian;
    image_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    // int test;
    // test = mlx_get_color_value(mlx, 16733491);
    // printf("%u\n", test);


    // int tile_x;
    // int i;
    // tile_x = 60;
    // i = -1;
    // while (++i < img_h)
        // mlx_pixet_put(mlx, win, tile_x, i, pixel_color(image_data, 0, 0, size_line));

    image_data[10 * 4 + size_line * 10] = 255;
    image_data[10 * 4 + size_line * 10 + 1] = 255;
    image_data[10 * 4 + size_line * 10 + 2] = 255;

    mlx_put_image_to_window(mlx, win, img, 0, 0);


    mlx_loop(mlx);
}
