# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 21:00:54 by gmoon             #+#    #+#              #
#    Updated: 2020/05/14 00:26:02 by gmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = ./src
INCDIR = ./inc
OBJDIR = ./obj

SRC =	command_split.c \
		env_util.c \
		exec_command.c \
		get_fd.c \
		main.c \
		print_commandline.c \
		quote.c \
		sh_cd.c \
		sh_echo.c \
		sh_env.c \
		sh_exec.c \
		sh_export.c \
		sh_ls.c \
		sh_pwd.c \
		sh_unset.c \
		signal.c \
		split.c \
		util.c
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

FTDIR = ./libft
FT_LIB = $(addprefix $(FTDIR)/,libft.a)
FT_INC = -I $(FTDIR)
FT_LNK = -L $(FTDIR) -l ft

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FTDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

run: $(NAME)
	@./minishell

.PHONY : all bonus clean fclean re run