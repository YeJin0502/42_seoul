NAME = libftprintf.a

LIBFT = libft.a
LIBFT_PATH = ./libft

CC = gcc
CFLAG = -Wall -Wextra -Werror -g3

SRC =	src/ft_printf.c \
		src/pf_check_and_init.c \
		src/pf_check_and_init_sub.c \
		src/pf_print_and_count.c \
		src/pf_spec_switch.c \
		src/pf_apply_flag.c \
		src/pf_apply_flag_sub.c \
		src/pf_util.c \
		src/pf_apply_flag_s.c
OBJ = $(SRC:.c=.o)
INC = ./inc

$(NAME): $(OBJ)
	make all -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
