/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:42:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 20:54:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_env(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

void		sh_export(char *line, t_list *envs)
{
	char	**args;
	char	**mover;
	t_env	*env;
	t_list	*curr;

	args = get_args(line, "export");
	mover = args;
	while (*mover)
	{
		if (is_valid_env(*mover))
		{
			env = (t_env *)malloc(sizeof(t_env));
			env->key = get_key(*mover);
			env->value = get_value(*mover);
			curr = envs;
			while (curr)
			{
				if (is_same(((t_env *)curr->content)->key, env->key))
				{
					free(((t_env *)curr->content)->value);
					((t_env *)curr->content)->value = env->value;
					free(env->key);
					free(env);
					break ;
				}
				curr = curr->next;
			}
			if (!curr)
				ft_lstadd_back(&envs, ft_lstnew(env));
		}
		free(*mover);
		mover++;
	}
	free(args);
}
