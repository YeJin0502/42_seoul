/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:50:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 00:11:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;

	if (!argc && argv)
		exit(1);
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle); // 컨트롤\는 안먹힘.
	envs = make_envs(envp);
	print_commandline();
	while (get_next_line(0, &line) > 0)
	{
		exec_command(line, envs, envp);
		print_commandline();
		free(line);
	}
	free(line);
}
