/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:50:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/02/28 04:50:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_gnl_strdup(const char *s);
char	**ft_gnl_split(char const *s, char c);

int get_next_line(int fd, char **line);

#endif