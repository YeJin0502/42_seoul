/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 21:23:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 21:23:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft_strchr로 공백을 검사해서... 아니다.


// 일단은 한줄씩 읽고, 시작이 R 이면...
void parsing(char *filename, t_info *info)
{
    int fd;
    char *line;
    line = 0; // 이거 기억이 안나네...
    fd = open(filename, O_RDONLY);
    int line_count;
    line_count = 0;
    while ((get_next_line(fd, &line) || ft_strlen(line)) && ++line_count)
    {
        printf("[%s] %ld, %d\n", line, ft_strlen(line), line_count);
        free(line);
    }
    printf("%d\n", line_count);
    
}

