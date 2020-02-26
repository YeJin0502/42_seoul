/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:24:20 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/26 23:24:20 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	content_size(void *content)
{
	unsigned char	*c;
	int				i;

	c = (unsigned char *)content;
	i = 0;
	while (c[i])
		i++;
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	int		size;
	t_list	*new;

	size = content_size(content);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		new->content = malloc(size);
		if (new->content == NULL)
			return (NULL);
		ft_memmove(new->content, content, size);
	}
	new->next = NULL;
	return (new);
}
