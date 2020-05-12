/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:40:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 20:27:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// # include "../inc/minishell.h"
# include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

////////////////////

int word_count(char *str)
{
	int wc;
	int flag;

	wc = 0;
	flag = 0;
	while (*str)
	{
		// if (flag == 0 && *str == '\'')
		// 	flag = 1;
		// else if (flag == 0 && *str == '\"')
		// 	flag = 2;
		// else if (flag == 1 && *str == '\'')
		// {
		// 	flag = 0;
		// 	wc++;
		// }
		// else if (flag == 2 && *str == '\"')
		// {
		// 	flag = 0;
		// 	wc++;
		// }
		// if (flag == 0 && *str != ' ' && *(str + 1) == ' ') // 아 이게 될까..?
		// 	wc++;
		if (flag == 0 && (*str == '\'' || *str == '\"'))
			flag += *str;
		else if (flag != 0 && (*str == '\'' || *str == '\"'))
			flag -= *str;
		if (flag == 0 && *str != ' ' && (*(str + 1) == ' ' || !*(str + 1))) // 어떻게 되려나?
			wc++;
		str++;
	}
	return (wc);
}

// int main()
// {
// 	char *str;

// 	str = " hello 'hi'asdf'world'  ";
// 	printf("<%d>\n", word_count(str));
// }

void word_len(char **str)
{
	int wl;
	int flag;

	wl = 0;
	flag = 0;
	while (**str)
	{
		if (flag == 0 && (**str == '\'' || **str == '\"'))
			flag += **str;
		else if (flag != 0 && (**str == '\'' || **str == '\"'))
			flag -= **str;
		if (flag == 0 && (**str == ' ' || !**str))
		{
			// printf("[%c]", **str);
			return ;
		}
		if (flag == 0 && !(**str == '\'' || **str == '\"'))
			// wl++;
			ft_putchar_fd(**str, 1);
		else if (flag != 0 && **str != flag) // 맞나?
			// wl++;
			ft_putchar_fd(**str, 1);
			// return (wl);
		(*str)++;
	}
	return ;
}

void echo_split(char *str) // echo 이후의 것들만 받아오기?
{
	int wc;
	char **ret;
	int wl;
	int i;

	wc = word_count(str);
	// ret = (char **)malloc(sizeof(char *) * (wc + 1));
	// ret[wc] = 0; // 맞나?
	i = -1;
	while (++i < wc)
	{
		while (*str == ' ')
			str++;
		word_len(&str);
		ft_putchar_fd('/', 1);
		// printf("wl: %d\n", wl);
		// ret[i] = (char *)malloc(wl + 1);
		// ret[i][wl] = '\0';
		// ft_memcpy(ret[i], str, wl);
		// str += wl;
	}
	return ;
}

int main()
{

	echo_split("hello 'hi'asdf'world'  ");

}

// void sh_echo(char *command, t_list *envs) // 나중에..
// {
// 	char **args_adr;
// 	char **args;

// 	if (!envs)
// 		return ; // 임시
// 	args_adr = ft_split(command, ' '); // split 대용 함수를 따로 만들어야겠는데.
// 	args = args_adr + 1;
// 	while (*args)
// 	{
// 		ft_putendl_fd(*args, 1);
// 		args++;
// 	}
// 	// ft_putstr_fd(command, 1);
// 	// ft_putchar_fd('\n', 1);
// }

// '랑 " 개수 체크? 홀수면 에러?
// '' 안의 환경변수는 이름으로
// "" 안의 환경변수는 변수내용으로