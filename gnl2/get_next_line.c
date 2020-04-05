/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 05:15:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/04/06 06:06:43 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int ret;
	char *buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	
	while ((ret = read(fd, buf, BUFFER_SIZE) 
	
}

int main()
{
	
}
