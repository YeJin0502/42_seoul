/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:19:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/27 00:19:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list *curr = lst->next;
	while (curr != NULL)
	{
		if (curr->next == NULL) // 꼭 여기 써야하나.... 아래로 뺄 방법은 없는지. 어렵네.
			return (curr);
		curr = curr->next;
	}
}

// typedef struct		s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;