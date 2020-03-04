/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 01:50:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 01:55:18 by gmoon            ###   ########.fr       */
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
} // 되나? 테스트 안해봄

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
} // 되나?

int	ft_memlen(void *str)
{
	char	*s;
	int		i;
	
	s = (char *)str;
	i = 0;
	while (s[i])
		i++;
	return (i);
}