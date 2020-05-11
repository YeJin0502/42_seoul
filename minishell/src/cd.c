/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:41:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 20:48:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_cd(char *line, t_list *envs)
{
	char	*mover;
	char	*home;

	mover = line + 2;
	if (ft_strlen(line) == 2)
	{
		home = find_value(envs, "HOME");
		if (chdir(home) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putendl_fd(home, 1);
		}
	}
	else
	{
		while (*mover == ' ')
			mover++;
		if (chdir(mover) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putendl_fd(mover, 1);
		}
	}
}
