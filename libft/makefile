CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

TARGET = libft.a
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c \
		ft_memcpy.c ft_memset.c ft_memmove.c ft_memccpy.c ft_memcmp.c \
		ft_calloc.c ft_bzero.c ft_memchr.c ft_atoi.c

OBJS = $(SRCS:.c=.o)
INCS = .

all: $(TARGET)

$(TARGET): $(OBJS)
	ar cr $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $(<:.c=.o) -I $(INCS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(TARGET)

re: fclean all