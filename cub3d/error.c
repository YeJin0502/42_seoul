/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 00:45:12 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/01 00:46:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_exit(int errno)
{
    perror("Error\n"); // errno을 직접 수정해서 메시지 띄울까? 함수 분리해서 좀 만들어야 할 듯.
    exit(1); // 숫자는 뭘 넣는거지? 그리고 return하고 차이가 있나? return은 다시 돌아가고, exit은 바로 종료하는건가?
    // return;
}