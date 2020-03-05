/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:50:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 07:38:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, fd);
		ft_putnbr_u(n % 10, fd);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	return ;
}

static unsigned int	n_size_u(unsigned int n)
{
	int	size;
	
	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_u(unsigned int n)
{
	int		size;
	char	*ret;

	size = n_size_u(n);
	ret = (char *)malloc(size + 1);
	if (!ret)
		return 0;
	ret[size] = '\0';
	while (size > 0)
	{
		ret[(size--) - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

int	ft_memlen(void *str) // 쓰이나?
{
	char	*s;
	int		i;
	
	s = (char *)str;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
