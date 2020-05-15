/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/15 22:11:45 by gmoon            ###   ########.fr       */
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
	int		fd;
	char	**args;

	semicolon = semicolon_split(line);
	mover = semicolon;
	while (*mover)
	{
		int len;
		char *command;
		char *queue;

		queue = *mover;
		while (*queue) // 뭔가 불안한데...
		{
			int redirection = 0;
			int pipe = 0;
			if (*queue == '>')
			{
				redirection = 1;
				queue++;
				if (*queue == '>' && *(queue + 1) == '>')
				{
					ft_putendl_fd("moong_shell: parse error near `>'", 2);
					break ;
				}
				else if (*queue == '>')
				{
					redirection = 2;
					queue++;
				}
			}
			else if (*queue == '|')
			{
				pipe = 1;
				queue++;
				if (*queue == '|')
					break ;
			}
			while (*queue && *queue == ' ')
				queue++;
			if (!*queue)
				break ;
			if (redirection == 1)
			{

			}
			else if (redirection == 2)
			{

			}
			else if (pipe = 1)
			{

			}
			len = get_command_len(queue); // > 나 | 전까지 길이 구함.
			command = ft_substr(queue, 0, len); // 전까지의 문자열 malloc
			args = get_args(command, envs); // 명령 실행하기 위해 args 구함.
			free(command);
			fd = fork_process(args, envs, envp); // 명령 실행.
			queue += len; // queue 밀기.
		}

		mover++;
	}
	double_char_free(&semicolon);
}

// 남은 문제
// cd 같은 것들. fork 신경쓰기.
// 리다이렉션이나 파이프.
// 리다이렉션이나 파이프 없을때 1로 출력.


// 두개 단위로 자른다.
// 실행한다.

// '>', '>>' 앞에꺼를 fd에 받아오고,
// 뒤꺼를 fd 열고, dup2를 쓴다.

// '<' 뒤꺼 fd를 무조건 먼저 얻어오고 실행해야하지 않나?
// pipe를 써야만한다?

// 2개만 실행하고 

// echo a | cat -e < b

// 중첩 파이프는 자식의..자식의..자식 느낌?
// 일단 파이프 하나, 리다이렉션 하나인 경우 먼저 생각해야 할듯...
// 내 실력으론 리다이렉션하고 파이프 같이 있는 경우는 못할듯?
// 결국은 모두다 뒤부터 순차적으로 해야하는것같은데.
// 파이프도 그렇고 리다이렉션도 뒤부터 오픈해야하고.