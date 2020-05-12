/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 23:28:13 by gmoon            ###   ########.fr       */
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

int is_redirection(char *str, int *len)
{
	int flag;

	flag = 0;
	while (*str)
	{
		if (flag == 0 && (*str == '\'' || *str == '\"'))
			flag += *str;
		else if (flag != 0 && *str == flag)
			flag -= *str;
		if (flag == 0 && *str == '>' && *(str + 1) == '>' && *(str + 2) == '>')
			return (-1);
		if (flag == 0 && *str == '>' && *(str + 1) == '>')
			return (2);
		else if (flag == 0 && *str == '>' && *(str + 1) != '>')
			return (1);
		str++;
		(*len)++;
	}
	return (0);
}
static void	exec_commands(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command_tmp;
	char	*command;
	int		len;
	char	*filename;
	int		fd;
	int		redirection;

	len = 0;
	commands = ft_split(line, ';');
	mover = commands;
	while (*mover)
	{
		command_tmp = ft_strtrim(*mover, " ");
		redirection = is_redirection(command_tmp, &len);
		if (redirection == 1)
		{
			command = ft_substr(command_tmp, 0, len);
			filename = ft_strtrim(command_tmp + len + 1, " ");
			fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
		}
		else if (redirection == 2)
		{
			command = ft_substr(command_tmp, 0, len);
			filename = ft_strtrim(command_tmp + len + 2, " ");
			fd = open(filename, O_WRONLY | O_CREAT | O_APPEND , 0744);
		}
		else if (redirection == 0)
		{
			command = ft_strdup(command_tmp);
			fd = 1;
		}
		if (redirection != -1)
		{
			command_switch(command, envs, envp, fd);
			free(command);
		}
		else
			ft_putendl_fd("moong_shell: parse error near `>'", 1); // 에러 함수로 대체 필요.
		free(command_tmp);
		free(*mover);
		mover++;
		close(fd);
	}
	free(commands);
}

int			main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;

	if (!argc && argv)
		exit(1);
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle); // 왜 컨트롤\는 안먹히지?
	envs = make_envs(envp);
	print_commandline();
	while (get_next_line(0, &line) > 0)
	{
		exec_commands(line, envs, envp);
		print_commandline();
		free(line);
	}
	free(line);
}
