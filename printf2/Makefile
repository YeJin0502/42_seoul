NAME = libftprintf.a

LIBFT = libft.a
LIBFT_PATH = ./libft

CC = gcc
CFLAG = -Wall -Wextra -Werror -g3
# CFLAG = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC =	src/ft_printf.c \
		src/pf_check_and_init.c \
		src/pf_print_and_count.c \
		src/pf_spec_switch.c \
		src/pf_apply_flag.c \
		src/pf_util.c \
		src/pf_apply_flag_s.c
		# 폴더 안에 안넣고 하는거 연습 하자.
OBJ = $(SRC:.c=.o)
# 폴더 따로 만드는 연습 하자.
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