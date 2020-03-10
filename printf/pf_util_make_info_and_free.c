/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_info_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:49:16 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/10 13:14:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_spec(const char c)
{
	char	*spec_set;

	spec_set = "cspdiuxX";
	while (*spec_set)
	{
		if (*spec_set == c)
			return (1);
		spec_set++;
	}
	return (0);
}

int	is_flag(const char c)
{
	char	*flag_set;

	flag_set = "-.0123456789*";
	while (*flag_set)
	{
		if (*flag_set == c)
			return (1);
		flag_set++;
	}
	return (0);
}

char	**flags_free(char ***flag, int i)
{
	while (--i >= 0)
		free(flag[i]);
	free(flag);
	return (0);
}

void	all_free(t_list **lst, char **specs, char ***flags, int count_s)
{
	t_list	*tmp;
	int		i;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(*specs);
	i = 0;
	while (i < count_s)
		free((*flags)[i++]); // (*flag) 괄호 안해주면 에러.
	free(*flags);
}
