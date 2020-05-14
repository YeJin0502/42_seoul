/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/15 00:38:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	command_switch(char **args, t_list *envs, char **envp, int fd)
{
	if (is_command(args[0], "exit"))
		exit(0);
	else if (is_command(args[0], "echo"))
		sh_echo(args + 1, fd);
	else if (is_command(args[0], "pwd"))
		sh_pwd(fd);
	else if (is_command(args[0], "cd"))
		sh_cd(args, envs);
	else if (is_command(args[0], "env"))
		sh_env(envs, fd);
	else if (is_command(args[0], "export"))
		sh_export(args + 1, envs);
	else if (is_command(args[0], "unset"))
		sh_unset(args + 1, envs);
	else if (is_command(args[0], "ls"))
		sh_ls(fd);
	else if (ft_strncmp(args[0], "./", 2) == 0)
		sh_exec(args[0], envp);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(args[0], 1);
	}
}

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command;
	int		fd;
	char	**args;

	commands = semicolon_split(line);
	mover = commands;
	while (*mover)
	{
		redirection_split(*mover, &command, &fd);
		if (fd > 0)
		{
			args = get_args(command, envs);
			// int i = 0;
			// while (args[i])
			// {
			// 	printf("[%s]\n", args[i]);
			// 	i++;
			// }
			command_switch(args, envs, envp, fd);
			free(command);
			double_char_free(&args);
		}
		if (fd > 2)
			close(fd);
		mover++;
	}
	double_char_free(&commands);
}

// echo a | cat -e > b
// 우선순위는 > 인듯. 어떻게 해야할지 아직 모르겠음.
// echo a | cat -e ; pwd
// 우선순위는 ;이다.