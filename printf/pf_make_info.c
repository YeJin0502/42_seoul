/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/09 08:05:41 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char	*make_specs(t_list *spec_adr, int count_s)
{
	char	*ret;
	int		i;
	
	if (!(ret = (char *)malloc(count_s + 1)))
		return 0;
	ret[count_s] = '\0';
	i = 0;
	while (i < count_s)
	{
		ret[i] = *((char *)spec_adr->content);
		spec_adr = spec_adr->next;
		i++;
	}
	return (ret);
}

char	**make_flags(t_list *spec_adr, int count_s)
{
	char	**ret;
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (!(ret = (char **)malloc(sizeof(char *) * count_s)))
		return 0;
	i = 0;
	while (i < count_s)
	{
		len = 0;
		tmp = (char *)spec_adr->content;
		while (*(tmp - len - 1) != '%')
			len++;
		ret[i] = (char *)malloc(len + 1);
		ret[i][len] = '\0';
		j = len;
		while (len > 0)
		{
			ret[i][j - len] = *(tmp - len); // 이런거 너무 불편한데. 못줄이나 ㅠㅠ
			len--;
		}
		i++;
		spec_adr = spec_adr->next;
	}
	return ret;
}

t_info	*make_info(char *specs, char **flags)
{
	int		size;
	t_info	*ret;
	int		i;

	size = ft_strlen(specs);
	if (!(ret = (t_info *)malloc(sizeof(t_info) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i].spec = specs[i];
		if (!(ret[i].flag = (char *)malloc(ft_strlen(flags[i]) + 1)))
		{
			while (--i >= 0)
				free(ret[i].flag);
			free(ret);
			return (0);
		}
		ret[i].flag[ft_strlen(flags[i])] = '\0';
		ret[i].flag = ft_memmove(ret[i].flag, flags[i], ft_strlen(flags[i]));
		ret[i].width_star = 0;
		ret[i].prec_star = 0; // 여기서 해주는게 순서 맞겠지?
		i++;
	}
	return (ret);
}

t_info	*make_info_and_free(t_list *spec_adr, int count_s)
{
	char	*specs;
	char	**flags;
	t_info	*ret;
	int		i;
	
	if (!(specs = make_specs(spec_adr, count_s)))
		return (0);
	if (!(flags = make_flags(spec_adr, count_s)))
	{
		free(specs);
		return (0);
	}
	if (!(ret = make_info(specs, flags)))
	{
		free(specs);
		while (*flags)
			free(*(flags++));
		return (0);
	}
	free(specs);
	i = 0;
	while (i < count_s)
		free(flags[i++]);
	free(flags);
	return (ret);
}