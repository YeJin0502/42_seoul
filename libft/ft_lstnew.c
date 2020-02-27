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
		new->content = malloc(size); // 널문자까지 가져오기를 바라고 +1 추가해줄까했는데..
		if (new->content == NULL) // 생각해보니 char인지도 알 수 없는 것이고.
			return (NULL); // 그냥 포인터를 가져오는게 낫나?
		ft_memmove(new->content, content, size); // 근데 value를 가져와야한다고 나와있어서.. 헷갈리네.
	}
	new->next = NULL;
	return (new);
}
