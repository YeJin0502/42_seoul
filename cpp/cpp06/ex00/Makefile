NAME = convert

CPPC = clang++
FLAGS = -Wall -Wextra -Werror -g

SRC = Conversion.cpp main.cpp
# 아래 Makefile에서는 오브젝트 파일에서 오류가 생겼었다.
# 따라서 간단한 경우, 이런 식으로 아예 OBJ 파일 없이 만드는게 편하다.

$(NAME):
	$(CPPC) $(FLAGS) $(SRC) -o $(NAME) 


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


### ----------------------------------------------------------------------
# NAME = convert

# CPPC = clang++
# FLAGS = -Wall -Wextra -Werror -g

# SRC = Conversion.cpp main.cpp
# OBJ = $(addpreffix SRC:.cpp=.o) # addpreffix를 안하면 컴파일러가 자동으로 설정되어 버림. 왜일까?

# $(NAME): $(OBJ)
# 	$(CPPC) $(FLAGS) $(SRC) -o $(NAME)

# all: $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all


### ----------------------------------------------------------------------
### 원래는 이렇게 했음. 처음 배웠던 Makefile의 형태. 대신 오브젝트 파일이 남는다.
# NAME = convert

# CPPC = clang++
# FLAGS = -Wall -Wextra -Werror -g

# SRC = Conversion.cpp main.cpp
# OBJ = $(SRC:.cpp=.o)

# $(NAME): $(OBJ)
# 	$(CPPC) $(FLAGS) $(SRC) -o $(NAME)

# %.o: %.cpp
# 	$(CPPC) $(FLAGS) -c $< -o $(NAME)

# all: $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all
