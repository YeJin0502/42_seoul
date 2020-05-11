/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 02:21:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_switch(char *command, t_list *envs, char **envp)
{
	if (is_command(command, "exit"))
		exit(0);
	else if (is_command(command, "echo"))
		sh_echo(command);
	else if (is_command(command, "pwd"))
		sh_pwd();
	else if (is_command(command, "cd"))
		sh_cd(command, envs);
	else if (is_command(command, "env"))
		sh_env(envs);
	else if (is_command(command, "export"))
		sh_export(command, envs);
	else if (is_command(command, "unset"))
		sh_unset(command, envs);
	else if (is_command(command, "ls"))
		sh_ls();
	else if (ft_strncmp(command, "./", 2) == 0)
		sh_exec(command, envp);
	else
	{
		ft_putstr_fd("moong_shell: command not found: ", 1);
		ft_putendl_fd(command, 1);
	}
}

static void	exec_command(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command;

	commands = ft_split(line, ';');
	mover = commands;
	while (*mover)
	{
		command = ft_strtrim(*mover, " ");
		command_switch(command, envs, envp);
		free(command);
		free(*mover);
		mover++;
	}
	free(commands);
}

int			main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;

	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle); // 왜 컨트롤\는 안먹히지?
	if (!argc && argv)
		exit(1);
	envs = make_envs(envp);
	// 복사본 만들 필요가 있나? envp로 받은건 수정해도 값에 의한 참조라 원본은 수정이 안되지 않나?
	// 연결리스트가 오히려 더 귀찮나? 복사본 만들 필요가 없다면, 그냥도 해볼까?
	print_commandline();
	while (get_next_line(0, &line) > 0)
	{
		exec_command(line, envs, envp);
		print_commandline();
		free(line);
	}
	free(line);
}
