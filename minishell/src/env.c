/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 18:44:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sh_env(t_list *envs)
{
	t_list *curr;

	curr = envs;
	while (curr)
	{
		ft_putstr_fd(((t_env *)curr->content)->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(((t_env *)curr->content)->value, 1);
		curr = curr->next;
	}
}
