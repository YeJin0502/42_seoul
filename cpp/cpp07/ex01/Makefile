NAME = iter

CPPC = clang++
FLAGS = -Wall -Wextra -Werror -g

SRC = iter.cpp

$(NAME):
	$(CPPC) $(FLAGS) -o $(NAME) $(SRC)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)