NAME = serialize

CPPC = clang++
FLAGS = -Wall -Wextra -Werror -g

SRC = Serialization.cpp main.cpp

$(NAME):
	$(CPPC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all