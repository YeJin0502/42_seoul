/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:48:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/11 13:55:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ci_process(char **mover, t_info *info)
{
	t_cont	*flag;
	int		ret;

	flag = (t_cont *)malloc(sizeof(t_cont));
	ft_memset(flag, 0, sizeof(t_cont));
	ret = ci_sub(mover, flag, info);
	if (ret != 0)
		free(flag);
	return (ret);
}

int			check_and_init(const char *fmt, t_info *info)
{
	char *mover;

	mover = (char *)fmt;
	while (*mover)
	{
		if (*mover == '%')
		{
			mover++;
			if (ci_process(&mover, info) != 0)
				return (1);
		}
		mover++;
	}
	return (0);
}
