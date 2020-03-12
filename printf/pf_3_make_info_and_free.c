/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_3_make_info_and_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:15:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/11 18:04:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_specs(t_list *spec_adr, int count_s)
{
	char	*specs;
	int		i;
	
	if (!(specs = (char *)malloc(count_s + 1)))
		return (0);
	specs[count_s] = '\0';
	i = -1;
	while (++i < count_s)
	{
		specs[i] = *((char *)spec_adr->content);
		spec_adr = spec_adr->next;
	}
	return (specs);
}

static char	**make_flags(t_list *spec_adr, int count_s)
{
	char	**flags;
	char	*s_a;
	int		len;
	int		i;
	int		len_save;

	if (!(flags = (char **)malloc(sizeof(char *) * count_s)))
		return (0);
	i = -1;
	while (++i < count_s)
	{
		len = 0;
		s_a = (char *)spec_adr->content;
		while (*(s_a - len - 1) != '%')
			len++;
		if (!(flags[i] = (char *)malloc(len + 1)))
			return (flags_free(&flags, i));
		flags[i][len++] = '\0';
		len_save = len - 1;
		while (--len > 0)
			flags[i][len_save - len] = *(s_a - len);
		spec_adr = spec_adr->next;
	}
	return (flags);
}

static t_info	*make_info(char *specs, char **flags)
{
	int		info_size;
	t_info	*info;
	int		i;

	info_size = ft_strlen(specs);
	if (!(info = (t_info *)malloc(sizeof(t_info) * info_size)))
		return (0);
	ft_memset(info, 0, sizeof(info));
	i = -1;
	while (++i < info_size)
	{
		info[i].spec = specs[i];
		if (!(info[i].flag = (char *)malloc(ft_strlen(flags[i]) + 1)))
		{
			while (--i >= 0)
				free(info[i].flag);
			free(info);
			return (0);
		}
		info[i].flag[ft_strlen(flags[i])] = '\0';
		info[i].flag = ft_memmove(info[i].flag, flags[i], ft_strlen(flags[i]));
	}
	return (info);
}

t_info	*make_info_and_free(t_list *spec_adr, int count_s)
{
	char	*specs;
	char	**flags;
	t_info	*info;
	
	if (!(specs = make_specs(spec_adr, count_s)))
		return (0);
	if (!(flags = make_flags(spec_adr, count_s)))
	{
		free(specs);
		return (0);
	}
	if (!(info = make_info(specs, flags)))
	{
		free(specs);
		while (*flags)
			free(*(flags++));
		return (0);
	}
	all_free(&spec_adr, &specs, &flags, count_s);
	return (info);
}
