/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 00:22:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 04:23:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int w = 700; // 전역변수는 나중에 맵에서 읽어야할 정보들.
int h = 700; // 지금은 임시로 전역변수로.
double d = 0.0; // (1 / 2 * PI) 로 계산하면 0 나옴. 앞의 계산이 정수 나눗셈으로 0이 되어버려서.
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

t_img *make_img(char *filename, t_info *info)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	img->image = mlx_xpm_file_to_image(info->mlx, filename, &(img->width), &(img->height)); // 이게..맞나?
	img->image_data = mlx_get_data_addr(img->image, &(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

void init_info_img(t_info *info)
{
	char *no;
	char *so;
	char *we;
	char *ea;

	no = "redbrick.xpm"; // 나중엔 직접 찾아야함.
	so = "redbrick.xpm"; // 나중엔 직접 찾아야함.
	we = "redbrick.xpm"; // 나중엔 직접 찾아야함.
	ea = "redbrick.xpm"; // 나중엔 직접 찾아야함.

	info->no = make_img(no, info);
	info->so = make_img(so, info);
	info->we = make_img(we, info);
	info->ea = make_img(ea, info);
}

t_info *init_info() // 아마 매개변수로 argc, argv 받지않을까?
{
	t_info *info;
	void *mlx_value;
	void *win_value;

	info = (t_info *)malloc(sizeof(t_info));
	info->win_width = w;
	info->win_height = h;
	info->view_angle = d;
	info->map = Map;
	info->map_width = 15;
	info->map_height = 11;
	info->tile_width = info->win_width / info->map_width; // 맵이 화면보다 더 큰경우 있어서 또 예외처리 해줘야됨.
	info->tile_height = info->win_height / info->map_height;
	info->x = info->tile_width * 2;
	info->y = info->tile_height * 2;
	mlx_value = mlx_init();
	win_value = mlx_new_window(mlx_value, info->win_width, info->win_height, "moon");
	info->mlx = mlx_value;
	info->win = win_value;
	init_info_img(info);
	return (info);
}
