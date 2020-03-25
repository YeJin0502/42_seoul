/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 04:53:22 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // 허용함수 아니면 나중에 삭제

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define PI 3.141592
# define FOV 60.0 * PI / 180.0
# define ROTATION_SPEED 2.0 * PI / 180.0
# define MOVE_SPEED 2.0 // 그냥 2하면 왠지 오류날 것 같은... 되나?

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97 // 반대?
# define KEY_D 100
# define KEY_LEFT 65361 // 반댄가?
# define KEY_RIGHT 65363

typedef struct	s_pair
{
	int x;
	int y; // int? double?
}				t_pair;

typedef struct	s_info
{
	double R_width; // tile을 double로 만들기 위해서 이걸 꼭 double로 만들어야하나? R이랑 map이 int면 double이 잘 안되네...
	double R_height; // x,y 쌍을 다 구조체로 만들까?
	// char *NO;
	// char *SO;
	// char *WE;
	// char *EA;
	// int *F[3];
	// int *C[3]; // 나중에 추가 필요
	int (*map)[15]; // 원래는 1중 배열로 받아야 할듯? 뒤의 숫자를 모르니까.
	// 아닌가..? 만들 수 있나? // 괄호 안해주면 안됨
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
	double ray_angle;
	double rotation_speed;
	double move_speed;
	double move_dist;
}				t_rc;

void *make_info(); // 아마 매개변수로 argc, argv 받지않을까?
void make_2d_map(t_info *info);
void make_first_scene(t_info *info);
void draw_line(t_pair p1, t_pair p2, t_info *info); // 구조체, 구조체의 포인터 장단점을 모르겠다.
int key_hook(int keycode, void *param);
void ray_casting(t_info *info, t_rc *rc);

#endif