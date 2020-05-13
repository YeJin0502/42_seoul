/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/13 19:56:28 by gmoon            ###   ########.fr       */
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

static int	get_redirection(char *str, int *command_len)
{
	int	flag;

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
		(*command_len)++;
	}
	return (0);
}

static void	get_command_and_fd(char *mover, char **command, int *fd)
{
	char	*command_tmp;
	int		command_len;
	int		redirection;
	char	*filename;

	command_tmp = ft_strtrim(mover, " ");
	command_len = 0;
	redirection = get_redirection(command_tmp, &command_len);
	*command = ft_substr(command_tmp, 0, command_len);
	if (redirection == 0)
		*fd = 1;
	else if (redirection == -1)
	{
		ft_putendl_fd("moong_shell: parse error near `>'", 1); // 에러 함수로 대체 필요.
		*fd = -1;
	}
	filename = ft_strtrim(command_tmp + command_len + redirection, " ");
	free(command_tmp);
	if (redirection == 1)
		*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (redirection == 2)
		*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND , 0744);
	free(filename);
}

void		exec_commands(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command;
	int		fd;

	commands = ft_split(line, ';');
	// 이부분 수정 필요.
	// quote 안의 것은 무시되게 바꿔야.
	// 여기서 아예 환경변수를 입력해줘야.
	mover = commands;
	while (*mover)
	{
		get_command_and_fd(*mover, &command, &fd);
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

void		print_commandline()
{
	char	*cwd;

	cwd = getcwd(0, 1024); // 1024가 의미하는 것이 뭐지?
	ft_putstr_fd("(", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd(") >> ", 1);
	free(cwd);
}
