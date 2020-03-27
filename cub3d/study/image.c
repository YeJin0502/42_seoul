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

    // mlx_put_image_to_window(mlx, win, img, 0, 0);

    // int tile_x;
    // int i;
    // tile_x = 60;
    // i = -1;
    // while (++i < img_h)
        // mlx_pixet_put(mlx, win, tile_x, i, pixel_color(image_data, 0, 0, size_line));
    int color;
    color = pixel_color(image_data, 63, 63, size_line);
    printf("%d\n", color);
    for (int i = 100; i < 200; i++)
        mlx_pixel_put(mlx, win, i, 100, color);

    mlx_string_put(mlx, win, 300, 300, pixel_color(image_data, 0, 63, size_line), "test");
    mlx_string_put(mlx, win, 350, 300, pixel_color(image_data, 64, 63, size_line), "test");
    

    mlx_loop(mlx);
}
