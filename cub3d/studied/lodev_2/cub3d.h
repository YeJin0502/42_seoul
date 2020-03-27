/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:59:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 20:51:42 by gmoon            ###   ########.fr       */
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

#define w 320
#define h 200
#define mapWidth 24
#define mapHeight 24

typedef struct s_info
{
	void *mlx;
	void *win;
	int (*worldMap)[mapHeight];
	double posX; // 내가 생각하는 x,y축이랑 맵에서의 x,y축이 다르지 않나?
	double posY;
	double dirX;
	double dirY;
	double planeX; // 이거 초기값 도대체 어떻게 계산하지? 변수 fov 입력하면 자동으로 계산하고 싶은데
	double planeY;
	double frameTime;
	// int key_flag;
}				t_info;

typedef struct	s_cal
{
	double cameraX;
	double rayDirX; // 광선이 가르키는 방향
	double rayDirY;
	int mapX; // 블록(격자) 좌표
	int mapY;
	double sideDistX; // 첫 x 격자에 도달할 때 까지의 거리 // 여기부터 dda
	double sideDistY;
	double deltaDistX; // 광선이 첫 x,y격자에서 다음 x,y 격자까지 이동하는 거리
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;
}				t_cal;

int key_hook(int keycode, void *param);

#endif