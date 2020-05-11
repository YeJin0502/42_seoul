/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 18:05:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int ft_max(int a, int b) // 이런건 libft로 가야?
{
	if (a < b)
		return (b);
	else
		return (a);
}

int is_command(char *a, char *b) // shell에서 실험 후 수정 필요
{
	char *b_space;

	b_space = ft_strjoin(b, " ");
	if (ft_strncmp(a, b, ft_max(ft_strlen(a), ft_strlen(b))) == 0)
		return (1);
	else if (ft_strncmp(a, b_space, ft_strlen(b_space)) == 0)
		return (1);
	else
		return (0);
} // 지금은 스페이스만 들어가면 뒤에 뭐가 오든 일단 실행됨.

void sh_echo(char *line) // 나중에..
{
	ft_putstr_fd(line, 1);
	ft_putchar_fd('\n', 1);
}

void sh_cd(char *line)
{
	char *mover;

	mover = line + 2;
	if (ft_strlen(line) == 2)
		chdir("/home/guadesktop"); // 환경변수 가져와서 HOME으로 변경해야할듯.
	else
	{
		while (*mover == ' ')
			mover++;
		if (chdir(mover) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putendl_fd(mover, 1);
		}
	}
}

void sh_env(t_list *envs)
{
	t_list *curr;

	curr = envs;
	while (curr)
	{
		ft_putstr_fd(((t_env *)curr->content)->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(((t_env *)curr->content)->value, 1);
		curr = curr->next;
	}
}

char *get_key(char *str)
{
	int len;
	char *key;

	len = 0;
	while (str[len] != '=')
		len++;
	key = (char *)malloc(len + 1);
	key[len] = '\0';
	key = ft_memcpy(key, str, len);
	return (key);
}

char *get_value(char *str)
{
	int len;
	char *value;

	len = 0;
	while (*str != '=')
		str++;
	str++;
	while (str[len])
		len++;
	value = (char *)malloc(len + 1);
	value[len] = '\0';
	value = ft_memcpy(value, str, len);
	return (value);
}

t_list *make_envs(char **envp)
{
	t_list *envs;
	t_env *env;

	envs = 0;
	while (*envp)
	{
		env = (t_env *)malloc(sizeof(t_env));
		env->key = get_key(*envp);
		env->value = get_value(*envp);
		ft_lstadd_back(&envs, ft_lstnew(env));
		envp++;
	}
	return (envs);
}

void sh_export(char *line, t_list *envs)
{
	t_env *env;

	line += 6;
	while (*line == ' ')
		line++;
	env = (t_env *)malloc(sizeof(t_env));
	env->key = get_key(line);
	env->value = get_value(line);
	
	t_list *curr;
	curr = envs;

	while (curr)
	{
		if (ft_strncmp(((t_env *)curr->content)->key, env->key,
			ft_max(ft_strlen(((t_env *)curr->content)->key), ft_strlen(env->key))) == 0)
		{
			free(((t_env *)curr->content)->value);
			((t_env *)curr->content)->value = env->value;
			free(env->key);
			break ;
		}
		curr = curr->next;
	}
	if (!curr)
		ft_lstadd_back(&envs, ft_lstnew(env));
}

// void sh_unset(char *line, t_list *envs)
// {
	
// }

void print_commandline(char **cwd) // 작명이...
{
	*cwd = getcwd(0, 1024); // 1024가 의미하는 것이 뭐지? gnl때도 1024로 했던것같은데...
	ft_putstr_fd("(", 1);
	ft_putstr_fd(ft_strrchr(*cwd, '/') + 1, 1);
	ft_putstr_fd(") >> ", 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_list *envs;
	char *cwd;
	char *line;

	if (!argc && argv)
		exit(1);
	envs = make_envs(envp);
	print_commandline(&cwd);
	while (get_next_line(0, &line) > 0)
	{
		if (is_command(line, "exit"))
			exit(0);
		else if (is_command(line, "echo"))
			sh_echo(line);
		else if (is_command(line, "pwd"))
			ft_putendl_fd(cwd, 1);
		else if (is_command(line, "cd"))
			sh_cd(line);
		else if (is_command(line, "env"))
			sh_env(envs);
		else if (is_command(line, "export"))
			sh_export(line, envs);
		// else if (is_command(line, "unset"))
		// 	sh_unset(line, envs);
		else
		{
			ft_putstr_fd("moong_shell: command not found: ", 1);
			ft_putendl_fd(line, 1);
		} 
		free(line);
		free(cwd);
		print_commandline(&cwd);
	}
	free(line);
	free(cwd);
}
