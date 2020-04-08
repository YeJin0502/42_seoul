/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:04:56 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/08 20:51:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int free_and_ret(t_info *info, int ret)
{
	// t_flag *curr;
	// t_flag *next;

	// curr = info->flag;
	// while (curr)
	// {
	// 	next = curr->next;
	// 	printf("%c\n", curr->spec);
	// 	free(curr);
	// 	curr = next;
	// }

	t_list *curr;

	curr = info->flag;
	while (curr)
	{
		printf("[%c]\n", curr->(t_cont *)content->spec);
		curr = curr->next;
	}
	free(info); // free는 **로 받아야하나? 아니네 이렇게 하면 되네..? 아오 헷갈려.
	return (ret);
}

t_info *make_info(void) // 이거 norm 뭐지?
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	ft_memset(info, 0, sizeof(t_info));
	// if (!(info->flag = (t_flag *)malloc(sizeof(t_flag))))
	// {
	// 	free(info);
	// 	return (0);
	// }
	// ft_memset(info->flag, 0, sizeof(t_flag));
	return (info);
}

int	ft_printf(const char *fmt, ...)
{
	t_info	*info;

	info = make_info();
	va_start(info->va, fmt);
	if (check_and_init(fmt, info) != 0)
		return (free_and_ret(info, 0));
	if (info->arg_num == 0)
	{
		// 그냥 출력하고 카운트.
		// 리턴.
		// va_list 개수 알 수 있는 방법 있나? 아무것도 안들어가면 0 반환하면
		// va_start 다음에 바로 리턴시켜버릴 수 있음.
	}
	// return (print_and_count(fmt, info)); // 출력하고 개수세는 함수.
	// printf("%s\n", fmt);
	return (free_and_ret(info, 0));
}

