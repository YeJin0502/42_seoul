/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:59:15 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/23 17:59:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h> // 지워도 되나?

// int worldMap[6][6]=
// {
// 	{1,1,1,1,1,1},
// 	{1,0,0,1,0,1},
// 	{1,0,2,0,0,1},
// 	{1,1,0,0,0,1},
// 	{1,1,1,1,1,1}
// };

typedef struct	s_info
{
	void *mlx;
	void *win;
}				t_info;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_boundary
{
	t_point *a;
	t_point *b;
}				t_boundary;

typedef struct	s_ray
{
	t_point *pos;
	t_point *dir;
}				t_ray;

void plot_line(t_point *p1, t_point *p2, t_info *info);
t_point *make_point(int x_value, int y_value);
t_boundary *make_boundary(int x1, int y1, int x2, int y2);
t_ray *make_ray(int x1, int y1, int x2, int y2);

#endif