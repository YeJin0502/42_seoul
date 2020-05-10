NAME = minishell

SRCDIR = ./src
INCDIR = ./inc
OBJDIR = ./obj

SRC = main.c 
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

FTDIR = ./libft
FT_LIB = $(addprefix $(FTDIR)/,libft.a)
FT_INC = -I $(FTDIR)
FT_LNK = -L $(FTDIR) -lft

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