/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 21:59:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/24 03:18:31 by gmoon            ###   ########.fr       */
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
#include "libft/libft.h"
#include <stdio.h> //

#define w 640
#define h 480
#define mapWidth 24
#define mapHeight 24

typedef struct s_info
{
	void *mlx;
	void *win;
	int (*worldMap)[mapHeight];
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double frameTime;
	int key_flag;
}				t_info;

int key_hook(int keycode, void *param);

#endif