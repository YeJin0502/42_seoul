/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:19:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/11 23:20:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **get_args(char *line, char *command)
{
	char **args;

	if (ft_strlen(line) == ft_strlen(command))
		return (0);
	args = 0;
	line += ft_strlen(command);
	line = ft_strtrim(line, " "); // 공백만 있으면 ft_strtrim은 어떻게되지?
	args = ft_split(line, ' ');
	free(line); // 맞나?
	return (args);
}
