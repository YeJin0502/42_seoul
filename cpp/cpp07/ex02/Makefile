NAME = array

CPPC = clang++
FLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp

$(NAME):
	$(CPPC) $(FLAGS) -o $(NAME) $(SRC)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean $(NAME)