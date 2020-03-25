/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 00:58:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h> // 

# define PI 3.141592
# define FOV (60 * 180 / PI) // 괄호 써도 되나?

typedef struct	s_info
{
	int R_width;
	int R_height; // x,y 쌍을 다 구조체로 만들까?
	// char *NO;
	// char *SO;
	// char *WE;
	// char *EA;
	// int *F[3];
	// int *C[3]; // 나중에 추가 필요
	int (*map)[15]; // 원래는 1중 배열로 받아야 할듯? 뒤의 숫자를 모르니까.
	// 아닌가..? 만들 수 있나? // 괄호 안해주면 안됨
	int map_width;
	int map_height;
	int tile_width;
	int tile_height;
	int x;
	int y;
	double dir;
	void *mlx;
	void *win;
}				t_info;

#endif