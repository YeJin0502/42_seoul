/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:26:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/24 23:56:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>

#define TILE_SIZE 32
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15

#define WINDOW_WIDTH MAP_NUM_ROWS * TILE_SIZE
#define WINDOW_HEIGHT MAP_NUM_COLS * TILE_SIZE

typedef struct	s_info
{
	void *mlx;
	void *win;
}				t_info;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

#endif