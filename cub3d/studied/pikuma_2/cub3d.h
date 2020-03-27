/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:59:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 19:10:46 by gmoon            ###   ########.fr       */
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
#define TILE_SIZE 64
#define MAP_NUM_ROWS 11 // 수정 필요
#define MAP_NUM_COLS 15 //
#define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE //
#define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE //
#define FOV_ANGLE 60.0 * PI / 180.0
#define WALL_STRIP_WIDTH 1
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

double norm_Angle(double angle);
int hasWallAt(double x, double y, t_info *info);
double point_distance(int x1, int y1, int x2, int y2);

int key_hook(int keycode, void *param);

#endif