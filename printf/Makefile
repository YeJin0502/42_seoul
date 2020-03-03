NAME = libftprintf.a

LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c ft_printf_utils.c

CC = clang
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCS = .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -rcs $@ $(OBJS)

all: $(NAME)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

re: fclean all