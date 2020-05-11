/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 23:27:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void command_switch(char *line, char *cwd, t_list *envs)
{
	if (is_command(line, "exit"))
		exit(0);
	else if (is_command(line, "echo"))
		sh_echo(line);
	else if (is_command(line, "pwd"))
		ft_putendl_fd(cwd, 1);
	else if (is_command(line, "cd"))
		sh_cd(line, envs);
	else if (is_command(line, "env"))
		sh_env(envs);
	else if (is_command(line, "export"))
		sh_export(line, envs);
	else if (is_command(line, "unset"))
		sh_unset(line, envs);
	else if (is_command(line, "ls"))
		sh_ls(cwd);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(line, 1);
	}
}

// char **get_commands(char *line)
// {
// 	char **ret;

// 	ret = ft_split(line, ';');

// }

int	main(int argc, char **argv, char **envp)
{
	t_list *envs;
	char *cwd;
	char *line;
	char **commands;

	if (!argc && argv)
		exit(1);
	envs = make_envs(envp);
	print_commandline(&cwd);
	while (get_next_line(0, &line) > 0)
	{
		commands = ft_split(line, ';'); // ; 없으면 어떻게되지?
		while (*commands)
		{
			command_switch(line, cwd, envs);
			commands++;
		}
		print_commandline(&cwd);
		free(line);
		free(cwd);
	}
	free(line);
	free(cwd);
}
