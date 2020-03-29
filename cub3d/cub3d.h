/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/30 08:20:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // 허용함수 아니면 나중에 삭제
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h> // open
# include "libft/libft.h"

# define PI 3.1415926535
# define FOV 60.0 * PI / 180.0
# define ROTATION_SPEED 2.0 * PI / 180.0
# define MOVE_SPEED 2.0 // 그냥 2하면 왠지 오류날 것 같은... 되나?
# define DISPLAY_WIDTH 1920
# define DISPLAY_HEIGHT 1080
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct  s_parsing
{
    int fd;
    char *line;
    int map_start;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *s;
    // char *f;
    // char *c;
    // char *map; // 이중으로 하기 어려울 듯...
    // int r_complete;
    // int no_complete;
    // int so_complete;
    // int we_complete;
    // int ea_complete;
    // int s_complete;
    // int f_complete;
    // int c_complete; // 필요할까?
}               t_ps;

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
    int     win_width;
    int     win_height;
    int     f[3];
    int     c[3];
    char    **map;
    int     map_width;
    int     map_height;
    double  tile_width;
    double  tile_height;
    double  x;
    double  y;
    double  view_angle;
    void    *mlx;
    void    *win;
    t_img   *no;
    t_img   *so;
    t_img   *we;
    t_img   *ea;
    t_img   *s; // 아직 안함
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

void    make_first_scene(t_info *info);
int     key_hook(int keycode, void *param);
void    raycast(t_info *info, t_rc *rc);
int     is_wall(double intersection_x, double intersection_y, t_info *info);
void    find_ray_dist(t_info *info, t_rc *rc);
void    render(t_info *info, t_rc *rc, int i);
void    init_horz(t_info *info, t_rc *rc, t_fd *horz);
void    init_vert(t_info *info, t_rc *rc, t_fd *vert);
void    init_ray_dist(t_rc *rc, t_fd *fd);
int     make_color(int r, int g, int b);
int     get_color(t_img *img, int x, int y);
void    change_color(t_img *img, int x, int y, int color);
void    init_info(char *filename, t_info *info);
void init_map_size(char *line, t_info *info);
void init_map(t_info *info, t_ps *ps, char *filename);
void ps_texture(char *line, char *wall, t_ps *ps);
void init_texture(t_info *info, t_ps *ps);

#endif