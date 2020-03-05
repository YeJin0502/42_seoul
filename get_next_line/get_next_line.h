/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:50:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 20:41:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

void	pull_buf(int *read_len, char *buf);
int		is_make_line(char **line, char *buf, int *read_len);
void 	free_and_null(char **buf);
int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		ft_strlen_until_lf(char *str);
int		ft_strlen_after_lf(char *str, int read_len);
void	*ft_memmove(void *dest, void *src, int n);
char	*ft_strjoin(char *s1, char *s2, int read_len, int is_contain_lf);

#endif