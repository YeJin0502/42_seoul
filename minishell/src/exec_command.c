/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/16 22:29:00 by gmoon            ###   ########.fr       */
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

// int fork_process(char **args, t_list *envs, char **envp)
// {
// 	int fd[2];
// 	pid_t pid;

// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		command_switch(args, envs, envp, fd[1]);
// 	}
// 	else
// 	{
// 		wait(0);
// 	}
// 	return (fd[0]);
// }

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**semicolon_mover;

	if (!envp && !envs)
		printf("zz\n");
	semicolon = semicolon_split(line);
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		char **args;

		args = get_args(*semicolon_mover, envs);
		char **args_mover;
		args_mover = args;
		while (*args_mover)
		{
			pid_t pid;
			int fds[2];

			pipe(fds);
			pid = fork();

		}
		
		
		semicolon_mover++;
	}
	double_char_free(&semicolon);
}

// 수정할 점.
// echo "$HOME>me" 등 특문이 들어가면 다 돼야함. 현재는 띄어쓰기같은거만 분리되게 해놓음.

// 할 것.
// [ ] char **의 substr같은 기능 구현해놔야? >나 | 앞까지만 일단 실행하게?
// [ ] sh 함수들을 fork로 할 수 있게..? 해보기