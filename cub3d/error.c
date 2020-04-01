/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:45:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 18:38:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_exit(int errno)
{
    if (errno == 1)
    {
        perror("Error\n"); // errno을 직접 수정해서 메시지 띄울까? 함수 분리해서 좀 만들어야 할 듯.
        exit(1);
    }
    else if (errno == 2)
    {
        ft_putstr_fd("Error\n: Some elements is missing.\n", 1); // fd_putstr 쓰는게 나을수도.
        exit(1); // 두 줄을 함수로 만들어버리는게 나을수도. 더 세분화시키고.
    }
    else if (errno == 3)
    {
        ft_putstr_fd("Error\n: Map is wrong.\n", 1);
        exit(1);
    }
    else if (errno == 4)
    {
        ft_putstr_fd("Error\n: Duplicate elements.\n", 1);
        exit(1);
    }
}