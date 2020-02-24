CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

TARGET = libft.a
SRCS = ft_strlen.c
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