/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 00:11:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_switch(char *command, t_list *envs, char **envp, int fd)
{
	if (is_command(command, "exit"))
		exit(0);
	else if (is_command(command, "echo"))
		sh_echo(command, envs, fd);
	else if (is_command(command, "pwd"))
		sh_pwd(fd);
	else if (is_command(command, "cd"))
		sh_cd(command, envs);
	else if (is_command(command, "env"))
		sh_env(envs, fd);
	else if (is_command(command, "export"))
		sh_export(command, envs);
	else if (is_command(command, "unset"))
		sh_unset(command, envs);
	else if (is_command(command, "ls"))
		sh_ls(fd);
	else if (ft_strncmp(command, "./", 2) == 0)
		sh_exec(command, envp);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(command, 1);
	}
}

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command;
	int		fd;

	commands = command_split(line);
	mover = commands;
	while (*mover)
	{
		get_fd(*mover, &command, &fd);
		if (fd > 0)
		{
			command_switch(command, envs, envp, fd);
			free(command);
		}
		if (fd > 2)
			close(fd);
		mover++;
	}
	double_char_free(&commands);
}
