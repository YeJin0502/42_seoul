NAME = libasm.a
SRC =	src/ft_strlen.s \
		src/ft_write.s \
		src/ft_strcpy.s \
		src/ft_strcmp.s \
		src/ft_read.s \
		src/ft_strdup.s
OBJ = $(SRC:.s=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NA = nasm
NAFLAGS = -f macho64
# NAFLAGS = -f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	$(NA) $(NAFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# makefile if문을 통해 linux랑 mac 구분해서 해보고싶은데... 폴더명 연습까지.
