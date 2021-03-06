/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/20 21:21:10 by gmoon            ###   ########.fr       */
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

# define PI 3.141592
# define FOV 1.0472
# define ROTATION_SPEED 0.05236
# define MOVE_SPEED 3.0
# define DISPLAY_WIDTH 1920
# define DISPLAY_HEIGHT 1080

/*
** FOV = 60 * PI / 180
** ROTATION_SPEED = 3 * PI / 180
*/

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 8
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

/*
** linux key
** define KEY_W 119
** define KEY_S 115
** define KEY_A 97
** define KEY_D 100
** define KEY_LEFT 65361
** define KEY_RIGHT 65363
** define KEY_ESC 65307
*/

typedef struct		s_parsing
{
	int				fd;
	char			*line;
	int				map_start;
	int				r_complete;
	int				f_complete;
	int				c_complete;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_ps;

typedef struct		s_image
{
	int				width;
	int				height;
	void			*image;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned char	*image_data;
}					t_img;

typedef struct		s_info
{
	int				argc;
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	int				f[3];
	int				c[3];
	char			**map;
	int				map_width;
	int				map_height;
	double			tile_width;
	double			tile_height;
	int				item_count;
	double			x;
	double			y;
	double			view_angle;
	t_img			*no;
	t_img			*so;
	t_img			*we;
	t_img			*ea;
	t_img			*s;
	t_img			*scene;
}					t_info;

typedef struct		s_item
{
	double			x;
	double			y;
	double			ray_dist;
	double			vec_x;
	double			vec_y;
	double			dirvec_x;
	double			dirvec_y;
	double			dir_angle;
	double			bar_height;
	double			bar_start;
	double			bar_end;
	double			render_width;
	int				i;
	int				i_min;
	int				i_max;
	double			image_x;
	double			image_y;
}					t_item;

typedef struct		s_raycast
{
	int				keycode;
	int				move_dir;
	int				rotation_dir;
	int				is_move;
	double			ray_angle;
	int				is_ray_up;
	int				is_ray_down;
	int				is_ray_right;
	int				is_ray_left;
	double			ray_dist;
	double			tile_x;
	int				tile_hit_dir;
	double			projection_dist;
	int				bar_height;
	int				bar_start;
	int				bar_end;
	t_img			*wall_image;
	double			wall_image_x;
	double			wall_image_y;
	double			item_x;
	double			item_y;
	double			*ray_dists;
	t_item			**item;
	int				i_item;
}					t_rc;

typedef struct		s_find_ray_dist
{
	int				is_horz;
	int				is_vert;
	double			intersection_x;
	double			intersection_y;
	double			dx;
	double			dy;
	int				is_wall_hit;
	double			ray_dist;
	double			tile_x;
	int				tile_hit_dir;
}					t_fd;

void				error_exit(int errno);
t_info				*init_info(int argc, char *filename);
void				init_map_size(char *line, t_info *info);
void				init_map(t_info *info, t_ps *ps, char *filename);
void				ps_texture(char *line, char *wall, t_ps *ps);
void				init_fc(char *line, char *fc, t_info *info, t_ps *ps);
void				init_texture(t_info *info, t_ps *ps);
int					is_wall(double intersection_x, double intersection_y,
							t_info *info, t_rc *rc);
int					key_hook(int keycode, void *param);
void				make_first_scene(t_info *info);
int					char_check(char *line);
void				wall_check(t_info *info);
void				raycast(t_info *info, t_rc *rc);
int					make_color(int r, int g, int b);
int					get_color(t_img *img, int x, int y);
void				change_color(t_img *img, int x, int y, int color);
void				init_horz(t_info *info, t_rc *rc, t_fd *horz);
void				init_vert(t_info *info, t_rc *rc, t_fd *vert);
void				init_ray_dist(t_rc *rc, t_fd *fd);
void				find_ray_dist(t_info *info, t_rc *rc);
void				render(t_info *info, t_rc *rc, int i);
void				save_bmp_image(t_img *scene, char *filename);
double				distance(double x1, double y1, double x2, double y2);
void				render_item(t_info *info, t_rc *rc, t_item **item);
int					press_x_button(void *param);
void				check_filename(char *filename);

#endif
