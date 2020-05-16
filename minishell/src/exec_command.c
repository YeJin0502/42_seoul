/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 02:55:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// echo만 되게 해놨는데, 'echo'와 "echo"도 되게 고쳐야.

// static void	command_switch(char **args, t_list *envs, char **envp, int fd)
// {
// 	if (is_command(args[0], "exit"))
// 		exit(0);
// 	else if (is_command(args[0], "echo"))
// 		sh_echo(args + 1, fd);
// 	else if (is_command(args[0], "pwd"))
// 		sh_pwd(fd);
// 	else if (is_command(args[0], "cd"))
// 		sh_cd(args, envs);
// 	else if (is_command(args[0], "env"))
// 		sh_env(envs, fd);
// 	else if (is_command(args[0], "export"))
// 		sh_export(args + 1, envs);
// 	else if (is_command(args[0], "unset"))
// 		sh_unset(args + 1, envs);
// 	else if (is_command(args[0], "ls"))
// 		sh_ls(fd);
// 	else if (ft_strncmp(args[0], "./", 2) == 0)
// 		sh_exec(args[0], envp);
// 	else
// 	{
// 		ft_putstr_fd("moong_shell: command not found: ", 1);
// 		ft_putendl_fd(args[0], 1);
// 	}
// }

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

// void check_redirection(char **args)
// {
// 	char **mover;

// 	mover = args;
// 	while (*mover)
// 	{

// 		else if (is_same(*mover, ">"))
// 		{

// 		}
// 		else if (is_same(*mover, ">>"))
// 		{

// 		}
// 		else if (is_same(*mover, "<"))
// 		{

// 		}
// 		mover++;
// 	}

// }



// void exec_args(char **args, t_list *envs, char **envp)
// {
// 	int fd[2];
// 	pid_t pid;


// }

int get_cmd_count(char **args)
{
	int ret;

	ret = 0;
	while (*args)
	{
		if ((**args != '|' && !*(args + 1)) ||
			(**args != '|' && **(args + 1) == '|')) // 아 이거 되게 헷갈리네.
			ret++;
		args++;
	}
	return (ret);
}

int get_args_count(char **args)
{
	int ret;

	ret = 0;
	while (*args)
	{
		if (**args == '|')
			break ;
		ret++;
		args++;
	}
	return (ret);
}

char ***pipe_split(char **args)
{
	char ***ret;
	int cmd_count;
	int i;
	int args_count;
	int j;

	cmd_count = get_cmd_count(args);
	ret = (char ***)malloc(sizeof(char **) * (cmd_count + 1));
	ret[cmd_count] = 0;
	i = -1;
	while (++i < cmd_count)
	{
		args_count = get_args_count(args);
		ret[i] = (char **)malloc(sizeof(char *) * (args_count + 1));
		ret[i][args_count] = 0;
		j = -1;
		while (++j < args_count)
		{
			ret[i][j] = ft_strdup(*args);
			args++;
		}
		args++; // 될까?
	}
	return (ret);
}



void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**semicolon_mover;

	if (!envp && !envs)
		printf("zz\n");
	semicolon = semicolon_split(line); // 아마 확정.
	semicolon_mover = semicolon;
	while (*semicolon_mover)
	{
		char **args;
		char ***cmd;

		args = get_args(*semicolon_mover, envs); // 아마 확정?
		cmd = pipe_split(args); // pipe 기준으로 자르는...게 될까?

		// int test;
		// while (*cmd)
		// {
		// 	test = 0;
		// 	while (**cmd)
		// 	{
		// 		printf("%d: %s\n", test, **cmd);
		// 		(*cmd)++;
		// 		test++;
		// 	}
		// 	cmd++;
		// }

		semicolon_mover++;
	}
	double_char_free(&semicolon);
}

// 수정할 점.
// echo "$HOME>me" 등 특문이 들어가면 다 돼야함. 현재는 띄어쓰기같은거만 분리되게 해놓음.

// 삼중포인터로 자르는거 해야하나?