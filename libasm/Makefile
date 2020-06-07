NAME = libasm.a
SRC =	src/ft_strlen.s \
		src/ft_write.s \
		src/ft_strcpy.s
OBJ = $(SRC:.s=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NA = nasm
# NAFLAGS = -f macho64
NAFLAGS = -f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	# $(NA) $(NAFLAGS) -o $@ $<
	$(NA) $(NAFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all