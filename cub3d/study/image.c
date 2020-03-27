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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\f' || \
			*str == '\n' || *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

char	*dec_to_hex(int dec)
{
	long long	hex_len;
	int 		tmp;
	char		*hex;

	tmp = dec;
	hex_len = 0;
	while (tmp)
	{
		tmp = tmp / 16;
		hex_len++;
	}
	if (!(hex = (char *)malloc(hex_len + 1)))
		return (0);
	hex[hex_len] = '\0';
	while (--hex_len >= 0)
	{
		if (dec % 16 <= 9)
			hex[hex_len] = dec % 16 + '0';
		else
			hex[hex_len] = dec % 16 + 'A' - 10;
		dec = dec / 16;
	}
	return (hex);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	i = 0;
	j = 0;
	while(i < ft_strlen(s1))
		ret[i++] = s1[j++];
	j = 0;
	while (i < len)
		ret[i++] = s2[j++];
	return (ret);
}

// int make_color(char *image, int x, int y, int size_line)
// {
//     int r_i;
//     int g_i;
//     int b_i;

//     r_i = ft_atoi((const char *)image[x * 4 + size_line * y]);
//     g_i = ft_atoi(image[x * 4 + size_line * y + 1]);
//     b_i = ft_atoi(image[x * 4 + size_line * y + 2]);

//     char *r_cp;
//     char *g_cp;
//     char *b_cp;

//     r_cp = dec_to_hex(r_i);
//     g_cp = dec_to_hex(g_i);
//     b_cp = dec_to_hex(b_i);
//     char *rg;
//     rg = ft_strjoin(r_cp, g_cp);

//     char *rgb;
//     rgb = ft_strjoin(rg, b_cp);
    
//     printf("%s\n", rgb);
//     return (0);

// }


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
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

    mlx_put_image_to_window(mlx, win, img, 0, 0);

    printf("bpp: %d\n", bpp);
    printf("endian: %d\n", endian);

    int tile_x;
    int i;
    tile_x = 20;
    unsigned char *image = (unsigned char *)img;
    printf("(%d, %d, %d, %d)\n", image[0], image[1], image[2], image[3]);
    printf("(%d, %d, %d, %d)\n", image_data[0], image_data[1], image_data[2], image_data[3]);
    i = -1;
    // make_color(image, tile_x, 0, size_line);
    // while (++i < img_h)
        // mlx_pixel_put(mlx, win, tile_x, i, make_color(image, tile_x, i, size_line));

    mlx_loop(mlx);
}
