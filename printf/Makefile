NAME = libftprintf.a

LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c \
		pf_apply_flag_utils.c \
		pf_apply_flag.c \
		pf_convert_process_utils.c \
		pf_convert_process.c \
		pf_find_spec_adr.c \
		pf_make_f_info.c \
		pf_make_info_utils.c \
		pf_make_info.c \
		pf_printf_process.c 
		
CC = clang
CFLAGS = -g3 -Wall -Wextra -Werror
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