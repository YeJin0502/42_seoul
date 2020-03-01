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

char	*ft_strjoin(char const *s1, char const *s2, int read_len);
char	*ft_strjoin_until_lf(char const *s1, char const *s2);
void	pull_buf(int *read_len, char *buf);
int		is_make_line(char **line, char *buf, int *read_len);
int		get_next_line(int fd, char **line);

int		ft_strlen(const char *str);
int		ft_strlen_after_lf(const char *str, int read_len);
void	*ft_memmove(void *dest, const void *src, int n);
char	*ft_strdup(const char *s, int read_len);
char	*ft_strdup_until_lf(const char *s);

#endif