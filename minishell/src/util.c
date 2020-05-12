/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:39:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 16:47:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int is_same(char *a, char *b)
{
	if (ft_strncmp(a, b, ft_max(ft_strlen(a), ft_strlen(b))) == 0)
		return (1);
	return (0);
}

int is_command(char *a, char *b) // shell에서 실험 후 수정 필요
{
	char	*b_space;
	int		ret;

	b_space = ft_strjoin(b, " ");
	if (is_same(a, b))
		ret = 1;
	else if (ft_strncmp(a, b_space, ft_strlen(b_space)) == 0)
		ret = 1;
	else
		ret = 0;
	free(b_space);
	return (ret);
}

void print_commandline()
{
	char *cwd;

	cwd = getcwd(0, 1024); // 1024가 의미하는 것이 뭐지? gnl때도 1024로 했던것같은데...
	ft_putstr_fd("(", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd(") >> ", 1);
	free(cwd); // 바로바로 free해주게 바꿨음. 뭐가 나은지는 아직 모르겠음.
}

void double_char_free(char ***str)
{
	char **str_adr;

	str_adr = *str;
	while (**str)
	{
		free(**str);
		(*str)++;
	}
	free(str_adr);
}
