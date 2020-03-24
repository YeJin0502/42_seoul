/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 19:53:45 by nam               #+#    #+#             */
/*   Updated: 2020/03/22 11:55:26 by nam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_key = 0;

//int		deal_key(int key, void *param)
//{
//	g_key = key;
//	printf("g_key : %d\n", g_key);
//	return (0);
//}
int		deal_key(int button, int x, int y, void *param)
{
	printf("mouse : (%d, %d)\n", x, y);
}

void	move(t_gra *a, t_pos *p)
{
	int k;
	int	kk;
	g_key = 0;
	for (p->x = 0;p->x < w;p->x++)
		cal_dda(a, p);
	k = mlx_mouse_hook(a->win, deal_key, (void *)0);
	//printf("k : %d\n", k);
	//p->posX -= 1;
	if (g_key == 65362)
		p->posX += 1;
	else if (g_key == 65364)
		p->posY -= 1;
	mlx_loop(a->mlx);
}

int		main(void)
{
	t_gra		a;
	t_pos		p;

	start(&a, &p);
	while (1)
	{
		move(&a, &p);
	}
}
