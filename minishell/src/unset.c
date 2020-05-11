/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:43:23 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 20:19:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sh_unset(char *line, t_list *envs)
{
	char **args;
	char **mover;
	t_list *curr;
	t_list *next;

	args = get_args(line, "unset");
	mover = args;
	while (*mover)
	{
		curr = envs;
		while (curr->next)
		{
			next = curr->next;
			if (is_same(((t_env *)next->content)->key, *mover))
			{
				curr->next = next->next;
				free(((t_env *)next->content)->key);
				free(((t_env *)next->content)->value);
				free(next->content);
				free(next);
				break ;
			}
			curr = next;
		}
		free(*mover);
		mover++;
	}
	free(args);
}
