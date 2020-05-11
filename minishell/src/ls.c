/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:21:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 00:29:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_ls(void)
{
	char			*cwd;
	DIR				*dir;
	int				flag;
	struct dirent	*file;

	cwd = getcwd(0, 1024);
	dir = opendir(cwd);
	flag = 0;
	while ((file = readdir(dir)))
	{
		if (flag != 0)
			ft_putstr_fd("  ", 1);
		if (!is_same(file->d_name, ".") && !is_same(file->d_name, ".."))
		{
			ft_putstr_fd(file->d_name, 1);
			flag = 1;
		}
	}
	ft_putstr_fd("\n", 1);
	closedir(dir);
	free(cwd);
}
