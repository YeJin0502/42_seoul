/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 03:08:31 by gmoon            ###   ########.fr       */
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

int args_count(char *command)
{
	int count;
	int quote;

	count = 0;
	quote = 0;
	while (*command)
	{
		if (quote == 0 && (*command == '\'' || *command == '\"'))
			quote += *command;
		else if (quote != 0 && *command == quote)
			quote -= *command;
		if (quote == 0 && *command != ' ' && (*(command + 1) == ' ' || !*(command + 1)))
			count++;
		command++;
	}
	return (count);
}

int key_len(char *str)
{
	int len;

	len = 0;
	while (*str && !(*str == ' ' || *str == '\'' || *str == '\"'))
	{
		str++;
		len++;
	}
	// printf("len: %d\n", len);
	return (len);
}

char *char_to_str(char c)
{
	char *ret;

	ret = (char *)malloc(2);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char *convert_arg(char **command, t_list *envs) // 한글자씩 join하는게 더 쉬울거같기도?
{
	char *ret_tmp;
	char *ret;
	int quote;
	char *key;
	char *to_add;

	quote = 0;
	ret = ft_strdup("");
	ret_tmp = ret;
	while (**command)
	{
		if (quote == 0 && (**command == '\'' || **command == '\"'))
			quote += **command;
		else if (quote != 0 && **command == quote)
			quote -= **command;
		else if (quote == 0 && **command == ' ') // 아 else if인지 if인지 헷갈리네.
			break;
		else if (quote != '\'' && **command == '$')
		{
			(*command)++;
			key = ft_substr(*command, 0, key_len(*command));
			to_add = find_value(envs, key);
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(to_add);
			*command += ft_strlen(key) - 1; // 맞나?
			free(ret);
			ret = ret_tmp;
		}
		else
		{
			to_add = char_to_str(**command); // 이게 안될거같은데..?
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(to_add);
			free(ret);
			ret = ret_tmp;
		}
		(*command)++;
	}
	return (ret); // 되나?
}

char **get_args(char *command, t_list *envs) // 변환을 여기서 하고 echo는 프린트만 하자...
{
	int count;
	char **args;
	int i;

	count = args_count(command);
	args = (char **)malloc(sizeof(char *) * (count + 1));
	args[count] = 0;
	i = -1;
	while (++i < count)
	{
		while (*command == ' ' && *command)
			command++;
		args[i] = convert_arg(&command, envs);
	}
	return (args);
}

// ''는 환경변수명, ""는 환경변수내용.
// echo "hello '$HOME' world" -> hello '/home/guadesktop' world
// echo 'hello "$HOME" world' -> hello "$HOME" world

void		exec_command(char *line, t_list *envs, char **envp)
{
	char	**commands;
	char	**mover;
	char	*command;
	int		fd;
	char	**args;

	if (!envp)
		printf("zz\n"); // 임시
	commands = command_split(line);
	mover = commands;
	while (*mover)
	{
		get_fd(*mover, &command, &fd);
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
		}
		if (fd > 2)
			close(fd);
		double_char_free(&args);
		mover++;
	}
	double_char_free(&commands);
}
