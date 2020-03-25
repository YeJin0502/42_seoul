/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:59:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 22:20:36 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// #include "libft/libft.h"
#include <stdio.h> //


#define PI 3.141592
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 704
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15
#define TILESIZE_X WINDOW_WIDTH / MAP_NUM_COLS
#define TILESIZE_Y WINDOW_HEIGHT / MAP_NUM_ROWS
#define FOV_ANGLE 60.0 * PI / 180.0
#define WALL_STRIP_WIDTH 1 // 되게하려면 코드에 사각형 그리는거같은거 추가해야함.
#define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

typedef struct	s_info
{
	void *mlx;
	void *win;
	int (*grid)[MAP_NUM_COLS];
	double x;
	double y;
	double turnDirection;
	double walkDirection;
	double rotationAngle;
	double moveSpeed;
	double rotationSpeed;
}				t_info;

typedef struct s_cal
{
	double moveStep;
	double rayAngle;
	double wallHitX;
	double wallHitY;
	double distance;
	int wasHitVertical;
	int isRayFacingDown;
	int isRayFacingUp;
	int isRayFacingRight;
	int isRayFacingLeft;
	double xintercept;
	double yintercept;
	double xstep;
	double ystep;
	double WallDistance;
	double distancePlane;
	double wallStripeHeight;
	double wallStart;
	double wallEnd;
}				t_cal;

typedef struct s_line
{
	int foundWallHit;
	double WallHitX;
	double WallHitY;
	double nextTouchX;
	double nextTouchY;
	double HitDistance;
}				t_line;

double norm_Angle(double angle);
int hasWallAt(double x, double y, t_info *info);
double point_distance(int x1, int y1, int x2, int y2);

int key_hook(int keycode, void *param);

#endif