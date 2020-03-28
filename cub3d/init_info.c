/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 00:22:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 08:24:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int w = 700; // 전역변수는 나중에 맵에서 읽어야할 정보들.
int h = 500; // 지금은 임시로 전역변수로.
double d = 0.0; // (1 / 2 * PI) 로 계산하면 0 나옴. 앞의 계산이 정수 나눗셈으로 0이 되어버려서.
int F[3] = {20, 20, 20};
int C[3] = {200, 200, 200};
int Map[11][15] =
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


// void init_test(t_info *info) // 포인터랑 배열 연습중인데 아직 잘 모르겠다.
// {
//     int w = 700; // 전역변수는 나중에 맵에서 읽어야할 정보들.
//     int h = 500; // 지금은 임시로 전역변수로.
//     double d = 0.0; // (1 / 2 * PI) 로 계산하면 0 나옴. 앞의 계산이 정수 나눗셈으로 0이 되어버려서.
//     int F[3] = {20, 20, 20};
//     int C[3] = {200, 200, 200};
//     int Map[11][15] =
//     {
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//         {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
//         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//     };

//     info->win_width = w;
//     info->win_height = h;
//     info->view_angle = d; // 이렇게 하면 init_info까지는 정보가 잘 가는데... 오류가 난다.
//     // 전역변수랑 지역변수랑 저장위치가 다른가? 지역변수는 사라지니까 malloc을 해줘야하는 상황 같다.
//     int *f;
//     f = (int *)malloc(sizeof(int) * 3); // 아 이거 기억이 안나네.
//     f = ft_memcpy((void *)f, (void *)F, sizeof(f)); // 이거 제대로 복사가 안되네. 20,20,-123412341234(대충큰값) 이렇게 나오는데?
//     info->f = f; // 이렇게..?
//     printf("(%d,%d,%d)\n", info->f[0], info->f[1], info->f[2]);
//     int *c;
//     c = (int *)malloc(sizeof(int) * 3);
//     c = ft_memcpy(c, C, sizeof(c));
//     info->c = c;

//     int **map;
//     map = (int **)malloc(sizeof(int *) * 11); // 이중배열은 힘드려나...? 근데 다 이중배열 기준으로 만들었는데. 고쳐야할까?
//     int i;
//     i = -1;
//     while (++i < 11) // 아 근데 어렵다... free도 어려울거같은데...
//         map[i] = (int *)malloc(sizeof(int) * 15);
//     map = ft_memcpy(map, Map, sizeof(map));
//     info->map = map;
//     printf("[%d]\n", map[0][0]); // 아예 안된다.

//     // i = -1;
//     // while (++i < 15)
//     //     printf("%d\n", (info->map[0][i]));
// }

static t_img *make_img(char *filename, t_info *info)
{
    t_img *img;

    img = (t_img *)malloc(sizeof(t_img));
    img->image = mlx_xpm_file_to_image(info->mlx, filename, &(img->width), &(img->height));
    img->image_data = mlx_get_data_addr(img->image, &(img->bpp), &(img->size_line), &(img->endian));
    return (img);
}

static void init_info_img(t_info *info)
{
    char *no;
    char *so;
    char *we;
    char *ea;

    no = "./texture/n_wall_pixel.xpm"; // 나중엔 직접 찾아야함.
    so = "./texture/s_wall_pixel.xpm"; // 나중엔 직접 찾아야함.
    we = "./texture/w_wall_pixel.xpm"; // 나중엔 직접 찾아야함.
    ea = "./texture/e_wall_pixel.xpm"; // 나중엔 직접 찾아야함.

    info->no = make_img(no, info);
    info->so = make_img(so, info);
    info->we = make_img(we, info);
    info->ea = make_img(ea, info);
}

t_info *init_info() // 아마 매개변수로 argc, argv 받지않을까?
{
    t_info  *info;
    void    *mlx_value;
    void    *win_value;

    info = (t_info *)malloc(sizeof(t_info));
    // ft_memset(info, 0, sizeof(info)); // 필요없으면 빼도...

    info->win_width = w;
    info->win_height = h;
    info->f = F;
    info->c = C;
    info->map = Map;
    info->view_angle = d;

    // init_test(info);
    info->map_width = 15;
    info->map_height = 11;
    info->tile_width = (double)info->win_width / info->map_width; // 맵이 화면보다 더 큰경우 있어서 또 예외처리 해줘야됨.
    info->tile_height = (double)info->win_height / info->map_height;
    info->x = info->tile_width * 2;
    info->y = info->tile_height * 2;
    mlx_value = mlx_init();
    win_value = mlx_new_window(mlx_value, info->win_width, info->win_height, "moon");
    info->mlx = mlx_value;
    info->win = win_value;
    init_info_img(info);
    return (info);
}
