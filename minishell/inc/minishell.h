/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:29:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/05/12 21:58:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

void			sh_cd(char *line, t_list *envs);
void			sh_echo(char *line, t_list *envs, int fd);
char			*get_key(char *str);
char			*get_value(char *str);
t_list			*make_envs(char **envp);
char			*find_value(t_list *envs, char *key);
void			sh_env(t_list *envs, int fd);
void			sh_export(char *line, t_list *envs);
void			sh_unset(char *line, t_list *envs);
void			sh_ls(int fd);
int				ft_max(int a, int b);
int				is_same(char *a, char *b);
int				is_command(char *a, char *b);
void			print_commandline();
char			**get_args(char *line, char *command);
void			sh_pwd(int fd);
void			sigint_handle();
void			sigquit_handle();
void			sh_exec(char *command, char **envp);
void			sigint_handle();
void			sigquit_handle();
void			double_char_free(char ***str);

#endif