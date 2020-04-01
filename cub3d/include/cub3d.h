/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/02 00:01:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define PI 3.1415926535
# define FOV 60.0 * PI / 180.0
# define ROTATION_SPEED 2.0 * PI / 180.0
# define MOVE_SPEED 2.0
# define DISPLAY_WIDTH 1920
# define DISPLAY_HEIGHT 1080

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct      s_parsing
{
    int             fd;
    char            *line;
    int             map_start;
    int             r_complete;
    int             f_complete;
    int             c_complete;
    char            *no;
    char            *so;
    char            *we;
    char            *ea;
    char            *s;
}                   t_ps;

typedef struct      s_image
{
    int             width;
    int             height;
    void            *image;
    int             bpp;
    int             size_line;
    int             endian;
    unsigned char   *image_data;
}                   t_img;

typedef struct      s_info
{
    int             argc;
    void            *mlx;
    void            *win;
    int             win_width;
    int             win_height;
    int             f[3];
    int             c[3];
    char            **map;
    int             map_width;
    int             map_height;
    double          tile_width;
    double          tile_height;
    double          x;
    double          y;
    double          view_angle;
    t_img           *no;
    t_img           *so;
    t_img           *we;
    t_img           *ea;
    t_img           *s;
    t_img           *scene;
}                   t_info;

typedef struct      s_raycast
{
    int             keycode;
    int             move_dir;
    int             rotation_dir;
    int             is_move;
    double          ray_angle;
    int             is_ray_up;
    int             is_ray_down;
    int             is_ray_right;
    int             is_ray_left;
    double          ray_dist;
    double          tile_x;
    int             tile_hit_dir;
    double          projection_dist;
    int             bar_height;
    int             bar_start;
    int             bar_end;
    t_img           *wall_image;
    double          wall_image_x;
    double          wall_image_y;
    int             is_item_hit;
    double          item_ray_dist;
    double          item_tile_x;
    double          item_image_x;
    double          item_image_y;
    double          item_bar_height;
    double          item_bar_start;
    double          item_bar_end;
}                   t_rc;

typedef struct      s_find_ray_dist
{
    int             is_horz;
    int             is_vert;
    double          intersection_x;
    double          intersection_y;
    double          dx;
    double          dy;
    int             is_wall_hit;
    double          ray_dist;
    double          tile_x;
    int             tile_hit_dir; // 타일의 위부터 시계방향으로 1, 2, 3, 4
    int             is_item_hit;
}                   t_fd;

void    error_exit(int errno);
t_info  *init_info(int argc, char *filename);
void    init_map_size(char *line, t_info *info);
void    init_map(t_info *info, t_ps *ps, char *filename);
void    ps_texture(char *line, char *wall, t_ps *ps);
void    init_fc(char *line, char *fc, t_info *info, t_ps *ps);
void    init_texture(t_info *info, t_ps *ps);
int     is_wall(double intersection_x, double intersection_y, t_info *info);
int     key_hook(int keycode, void *param);
void    make_first_scene(t_info *info);
void    char_check(char *line);
void    wall_check(t_info *info);
void    raycast(t_info *info, t_rc *rc);
int     make_color(int r, int g, int b);
int     get_color(t_img *img, int x, int y);
void    change_color(t_img *img, int x, int y, int color);
void    init_horz(t_info *info, t_rc *rc, t_fd *horz);
void    init_vert(t_info *info, t_rc *rc, t_fd *vert);
void    init_ray_dist(t_rc *rc, t_fd *fd);
void    find_ray_dist(t_info *info, t_rc *rc);
void    render(t_info *info, t_rc *rc, int i);
void    save_bmp_image(t_img *scene, char *filename);

#endif