/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:14:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/27 00:14:27 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		count;

	curr = lst->next;
	count = 0;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
