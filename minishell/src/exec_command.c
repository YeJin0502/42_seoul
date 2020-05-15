/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/15 18:42:42 by gmoon            ###   ########.fr       */
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





int fork_process(char **args, t_list *envs, char **envp)
{
	int fd[2];
	pid_t pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		command_switch(args, envs, envp, fd[1]);
	}
	else
	{
		wait(0);
	}
	return (fd[0]);
}

int get_command_len(char *str)
{
	int len;
	int quote;

	len = 0;
	quote = 0;
	while (*str)
	{
		if (quote == 0 && (*str == '\'' || *str == '\"'))
			quote += *str;
		else if (quote != 0 && *str == quote)
			quote -= *str;
		else if (quote == 0 && (*str == '>' || *str == '|')) // 허술한데..
			break ;
		len++;
		str++;
	}
	return (len);
}



void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**semicolon;
	char	**mover;
	// char	*command;
	int		fd;
	char	**args;

	semicolon = semicolon_split(line);
	mover = semicolon;
	while (*mover)
	{
		int len;
		char *command;
		char *command_tmp;
		command_tmp = *mover;
		while (*command_tmp) // 뭔가 불안한데...
		{
			len = get_command_len(command_tmp);
			command = ft_substr(command_tmp, 0, len);
			args = get_args(command, envs);
			fd = fork_process(args, envs, envp);
			char buffer[1024];
			read(fd, buffer, 1024);
			printf("[%s]\n", buffer);
			command_tmp += len; // 이렇게는 어떻게되지?
		}

		// redirection_split(*mover, &command, &fd);
		// if (fd > 0)
		// {

		// 	args = get_args(command, envs);
		// 	// int i = 0;
		// 	// while (args[i])
		// 	// {
		// 	// 	printf("[%s]\n", args[i]);
		// 	// 	i++;
		// 	// }
		// 	command_switch(args, envs, envp, fd);
		// 	free(command);
		// 	double_char_free(&args);
		// }
		// if (fd > 2)
		// 	close(fd);
		mover++;
	}
	double_char_free(&semicolon);
}

// 남은 문제
// cd 같은 것들. fork 신경쓰기.
// 리다이렉션이나 파이프.
// 리다이렉션이나 파이프 없을때 1로 출력.