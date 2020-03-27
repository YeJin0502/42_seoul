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
    int r_i;
    int g_i;
    int b_i;
	int color;

    r_i = (int)image[x * 4 + size_line * y + 2];
    g_i = (int)image[x * 4 + size_line * y + 1];
    b_i = (int)image[x * 4 + size_line * y ];
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

    int tile_x;
    int i;
    tile_x = 60;
    i = -1;
    while (++i < img_h)
        mlx_pixel_put(mlx, win, tile_x, i, pixel_color(image_data, tile_x, i, size_line));

	// mlx_string_put(mlx, win, 300, 300, pixel_color(image_data, 0, 0, size_line), "test");
    mlx_loop(mlx);
}
