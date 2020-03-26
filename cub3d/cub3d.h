/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/27 07:26:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // 허용함수 아니면 나중에 삭제
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define PI 3.1415926535
# define FOV 60.0 * PI / 180.0
# define ROTATION_SPEED 2.0 * PI / 180.0
# define MOVE_SPEED 2.0 // 그냥 2하면 왠지 오류날 것 같은... 되나?

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct	s_info
{
	double win_width; // tile을 double로 만들기 위해서 이걸 꼭 double로 만들어야하나? R이랑 map이 int면 double이 잘 안되네...
	double win_height;
	// char *no;
	// char *so;
	// char *we;
	// char *ea;
	// int *f[3];
	// int *c[3]; // 나중에 추가 필요
	int (*map)[15]; // 원래는 1중 배열로 받아야 할듯? 뒤의 숫자를 모르니까. 아닌가..? // 괄호 안해주면 안됨.
	int map_width;
	int map_height;
	double tile_width;
	double tile_height;
	double x; // int로 했더니 더하는 값들이 double이니까 계산이 이상하게 되더라.
	double y;
	double view_angle;
	void *mlx;
	void *win;
}				t_info;

typedef struct s_raycasting
{
	int keycode;
	int move_dir;
	int rotation_dir;
	double move_dist;
	double ray_angle;
	int is_ray_up;
	int is_ray_down;
	int is_ray_right;
	int is_ray_left;
	double intersection_x;
	double intersection_y;
	double ray_dist;
	double corrected_ray_dist;
	double projection_dist;
	double projection_height;
	double projection_start;
	double projection_end;
}				t_rc;

typedef struct s_find_dist // 작명이...
{
	double intersection_x;
	double intersection_y;
	double dx;
	double dy;
	int is_wall_hit;
	double ray_dist;
}				t_fd;

void *init_info(); // 아마 매개변수로 argc, argv 받지않을까?
void render_first_scene(t_info *info);
int key_hook(int keycode, void *param);
void raycast(t_info *info, t_rc *rc);
double distance(double x1, double y1, double x2, double y2);
int is_wall(double intersection_x, double intersection_y, t_info *info);
void find_ray_dist(t_info *info, t_rc *rc);

#endif