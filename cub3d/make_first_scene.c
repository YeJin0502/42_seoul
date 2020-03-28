/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_first_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:13:41 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/28 17:13:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void make_first_scene(t_info *info)
{
    t_rc    *rc;

    info->scene = (t_img *)malloc(sizeof(t_img));
    rc = (t_rc *)malloc(sizeof(t_rc));
    // init_rc_key(rc, 0); // 이거 뭔가 release를 이용해서 바꿀 듯?
    // move_and_rotate(info, rc);
    raycast(info, rc);
    free(rc);
}