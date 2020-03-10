NAME = libftprintf.a

LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c \
		pf_1_find_spec_adr.c \
		pf_2_no_spec_print.c \
		pf_3_make_info_and_free.c \
		pf_3sub_make_f_info.c \
		pf_4_print_and_count.c \
		pf_4sub1_convert_to_str.c \
		pf_4sub2_apply_flag.c \
		pf_4sub3_apply_flag_sub.c \
		pf_util_apply_flag.c \
		pf_util_convert_to_str.c \
		pf_util_make_info_and_free.c
		
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