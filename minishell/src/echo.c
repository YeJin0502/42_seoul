/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 22:15:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int echo_count(char *str)
{
	int wc;
	int flag;

	wc = 0;
	flag = 0;
	while (*str)
	{
		if (flag == 0 && (*str == '\'' || *str == '\"'))
			flag += *str;
		else if (flag != 0 && *str == flag)
			flag -= *str;
		if (flag == 0 && *str != ' ' && (*(str + 1) == ' ' || !*(str + 1)))
			wc++;
		str++;
	}
	return (wc);
}

void echo_print(char **str, int fd)
{
	int flag;

	flag = 0;
	while (**str)
	{
		if (flag == 0 && (**str == '\'' || **str == '\"'))
			flag += **str;
		else if (flag != 0 && **str == flag)
			flag -= **str;
		if (flag == 0 && (**str == ' ' || !**str))
			return ;
		if (flag == 0 && !(**str == '\'' || **str == '\"'))
			ft_putchar_fd(**str, fd);
		else if (flag != 0 && **str != flag)
			ft_putchar_fd(**str, fd);
		(*str)++;
	}
	return ;
}

void echo_process(char *str, int fd)
{
	int wc;
	int i;

	wc = echo_count(str);
	if (wc == 0)
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	i = -1;
	while (++i < wc)
	{
		while (*str == ' ')
			str++;
		echo_print(&str, fd);
		if (i != wc - 1)
			ft_putchar_fd(' ', fd);
		else
			ft_putchar_fd('\n', fd);
	}
	return ;
}

void sh_echo(char *command, t_list *envs, int fd)
{
	char *str;

	if (!envs)
		return ;
	str = command + 4;
	echo_process(str, fd);
}
