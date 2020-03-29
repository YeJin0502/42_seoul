/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:50:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/29 21:55:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
// # include "../libft/libft.h"

# define BUFFER_SIZE 1 // 몇으로 하는게 빠르려나..?

int		get_next_line(int fd, char **line);

int		gnl_strlen(char *str);
int		gnl_strlen_until_lf(char *str);
int		gnl_strlen_after_lf(char *str, int read_len);
void	*gnl_memmove(void *dest, void *src, int n);
char	*gnl_strjoin(char *s1, char *s2, int read_len, int is_contain_lf);

#endif