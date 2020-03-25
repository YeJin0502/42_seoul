/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 23:26:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/26 00:17:24 by gmoon            ###   ########.fr       */
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
	int R_height;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int *F[3];
	int *C[3];
	double dir;
	void *mlx;
	void *win;
}				t_info;

#endif