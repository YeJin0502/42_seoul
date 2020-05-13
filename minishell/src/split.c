/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:19:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/14 00:13:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **get_args(char *line, char *command) // 이거 옮기고 뭔가 작명도, 기능도 수정 필요.
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
