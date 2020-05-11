/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 13:24:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_max(int a, int b) // 이런건 libft로 가야?
{
	if (a < b)
		return (b);
	else
		return (a);
}

int is_same(char *a, char *b) // strcmp 구현 귀찮아서... 대충
{
	if (ft_strncmp(a, b, ft_max(ft_strlen(a), ft_strlen(b))) == 0)
		return (1);
	else
		return (0);
}

void ft_echo(char *line) // 나중에..
{
	ft_putstr_fd(line, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	char *line;
	char *cwd;

	cwd = getcwd(0, 1024); // 1024가 의미하는 것이 뭐지? gnl때도 1024로 했던것같은데...
	ft_putstr_fd("(", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd(") >> ", 1);
	while (get_next_line(0, &line) > 0)
	{
		if (is_same(line, "exit") || !ft_strncmp(line, "exit ", 5))
			exit(0);
		else if (is_same(line, "echo") || !ft_strncmp(line, "echo ", 5))
			ft_echo(line);
		else if (is_same(line, "pwd") || !ft_strncmp(line, "pwd ", 4)) // shell에서 실험 후 수정 필요
			ft_putendl_fd(cwd, 1);
		else
		{
			ft_putstr_fd("moong_shell: command not found: ", 1);
			ft_putendl_fd(line, 1);
		}
		free(line);
		free(cwd);
		cwd = getcwd(0, 1024);
		ft_putstr_fd("(", 1);
		ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
		ft_putstr_fd(") >> ", 1);
	}
	free(line);
	free(cwd);
}
