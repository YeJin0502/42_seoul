/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:55:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 16:32:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int args_count(char *command)
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

static int key_len(char *str)
{
	int len;

	len = 0;
	while (*str && !(*str == ' ' || *str == '\'' || *str == '\"'))
	{
		str++;
		len++;
	}
	return (len);
}

static char *convert_arg(char **command, t_list *envs)
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
		else if (quote == 0 && **command == ' ')
			break;
		else if (quote != '\'' && **command == '$')
		{
			(*command)++;
			key = ft_substr(*command, 0, key_len(*command));
			to_add = ft_strdup(find_value(envs, key));
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(to_add);
			*command += ft_strlen(key) - 1;
			free(ret);
			ret = ret_tmp;
		}
		else
		{
			to_add = char_to_str(**command);
			ret_tmp = ft_strjoin(ret_tmp, to_add);
			free(to_add);
			free(ret);
			ret = ret_tmp;
		}
		(*command)++;
	}
	return (ret);
}

// ''는 환경변수명, ""는 환경변수내용.
// echo "hello '$HOME' world" -> hello '/home/guadesktop' world
// echo 'hello "$HOME" world' -> hello "$HOME" world

char **get_args(char *command, t_list *envs)
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

// echo "hello$HOMEworld" 안됨. 수정 필요.