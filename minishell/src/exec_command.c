/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:36:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/17 03:22:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// echo만 되게 해놨는데, 'echo'와 "echo"도 되게 고쳐야.

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

void exec_cmd(char ***cmd, t_list *envs, char **envp)
{
	int fd[2];
	pid_t pid;
	int fdd;

	fdd = 0; // 아직 모름.
	while (*cmd)
	{
		pipe(fd);
		if ((pid = fork()) == -1)
			ft_putstr_fd("pid error.\n", 2); // 임시
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(cmd + 1))
				dup2(fd[1], 1);
			close(fd[0]);
			command_switch(*cmd, envs, envp, 1);
			exit(1); // 아 모르겠는데. 
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
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

		// 출력 테스트
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

		exec_cmd(cmd, envs, envp);
		semicolon_mover++;
	}
	double_char_free(&semicolon);
}

// 수정할 점.
// [ ] echo "$HOME>me" 등 특문이 들어가면 다 돼야함. 현재는 띄어쓰기같은거만 분리되게 해놓음. - 나중에...
// [ ] fork를 도입하다보니 아직 exit랑 cd같은건 안됨.
// [ ] 아직 리다이렉션 구현 안함.