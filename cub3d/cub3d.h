/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 02:39:57 by gmoon            ###   ########.fr       */
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
# define KEY_ESC 65307

typedef struct  s_img
{
    int             width;
    int             height;
    void            *image;
    int             bpp;
    int             size_line;
    int             endian;
    unsigned char   *image_data;
}               t_img;

typedef struct  s_info
{
    int     win_width; // tile을 double로 만들기 위해서 이걸 꼭 double로 만들어야하나? R이랑 map이 int면 double이 잘 안되네...
    int     win_height; // double이었는데 int로 바꿔줬으니, 필요할 때 double로 바꿔줘야.
    int     *f;
    int     *c;
    int     (*map)[15]; // 원래는 1중 배열로 받아야 할듯? 뒤의 숫자를 모르니까. 아닌가..? // 괄호 안해주면 안됨.
    int     map_width;
    int     map_height;
    double  tile_width;
    double  tile_height;
    double  x; // int로 했더니 더하는 값들이 double이니까 계산이 이상하게 되더라.
    double  y;
    double  view_angle;
    void    *mlx;
    void    *win;
    t_img   *no;
    t_img   *so;
    t_img   *we;
    t_img   *ea;
    t_img   *scene;
}               t_info;

typedef struct  s_raycast
{
    int     keycode;
    int     move_dir;
    int     rotation_dir;
    double  move_dist;
    int     is_move;
    double  ray_angle;
    int     is_ray_up;
    int     is_ray_down;
    int     is_ray_right;
    int     is_ray_left;
    double  intersection_x;
    double  intersection_y;
    double  ray_dist;
    double  tile_x;
    int     tile_hit_dir;
    double  corrected_ray_dist;
    double  projection_dist;
    int     bar_height;
    int     bar_start;
    int     bar_end;
    t_img   *wall_img;
    double  image_x;
    double  image_y;
    // int     color;
}               t_rc;

typedef struct  s_find_dist // 작명이...
{
    double  intersection_x;
    double  intersection_y;
    double  dx;
    double  dy;
    int     is_wall_hit;
    double  ray_dist;
    double  tile_x;
    int     tile_hit_dir; // 타일의 위부터 시계방향으로 1, 2, 3, 4
}               t_fd;

t_info  *init_info(); // 아마 매개변수로 argc, argv 받지않을까?
void    make_first_scene(t_info *info);
int     key_hook(int keycode, void *param);
void    raycast(t_info *info, t_rc *rc);
int     is_wall(double intersection_x, double intersection_y, t_info *info);
void    find_ray_dist(t_info *info, t_rc *rc);
void    render(t_info *info, t_rc *rc, int i);
void    init_horz(t_info *info, t_rc *rc, t_fd *horz);
void    init_vert(t_info *info, t_rc *rc, t_fd *vert);
void    init_rc_ray_dist(t_rc *rc, t_fd *fd);
int     make_color(int r, int g, int b);
int     get_color(t_img *img, int x, int y);
void    change_color(t_img *img, int x, int y, int color);

#endif