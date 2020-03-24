/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 22:09:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/25 00:47:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int Map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main()
{
	void *mlx_value;
	void *win_value;
	t_info *info;

	mlx_value = mlx_init();
	win_value = mlx_new_window(mlx_value, WINDOW_WIDTH, WINDOW_HEIGHT, "test");
	info = (t_info *)malloc(sizeof(t_info));
	info->mlx = mlx_value;
	info->win = win_value;
	info->grid = Map;
	info->x = WINDOW_WIDTH / 2;
	info->y = WINDOW_HEIGHT / 2;
	info->turnDirection = 0;
	info->walkDirection = 0;
	info->rotationAngle = PI / 2;
	info->moveSpeed = 2;
	info->rotationSpeed = 2 * (PI / 180);

	mlx_key_hook(info->win, key_hook, info);
	mlx_loop(info->mlx);
}
