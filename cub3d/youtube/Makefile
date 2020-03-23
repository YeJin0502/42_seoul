# 베끼다가 포기... 일단은 그냥 하나하나 컴파일하고 나중에 만들자...

PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

NAME	=   cub3d
SRCS	=	cub3d.c plot_line.c
			
OBJS	= $(SRCS:.c=.o)
CC		= gcc
INCS	= -I. -Ilibft/ -Iminilibx_opengl/
FLAGS	= -g3 -Wall -Wextra -Werror
FRWRKS	= -lmlx -lX11 -lXext
LIBS_P	= ${PROJECT_ROOT}/libmlx.dylib ${PROJECT_ROOT}/libft/libft.a

%.o: $(PROJECT_ROOT)%.c
	${CC} ${FLAGS} -c $(CPPFLAGS) -o $@ $< ${INCS}

$(NAME): ${OBJS}
	make libs -C ${PROJECT_ROOT}
	gcc $(OBJS) ${FLAGS} ${FRWRKS} -o $(NAME) ${LIBS_P}

all: $(NAME)

libs:
	make -C ${PROJECT_ROOT}/minilibx_mms_beta
	make -C ${PROJECT_ROOT}/libft
	cp ${PROJECT_ROOT}/minilibx_mms_beta/libmlx.dylib ./libmlx.dylib

clean:
	rm -fr cub3d $(OBJS)
	rm -rf .*.o
	rm -rf .*.dylib
    
fclean: clean
	$(RM) $(NAME)
    
re: fclean all

bonus:
	echo ${FILE}
	make re BONUS=1 -C ${PROJECT_ROOT}

libs-clean:
	make clean -C ${PROJECT_ROOT}/minilibx_mms_beta
	make fclean -C ${PROJECT_ROOT}/libft

norm:
	norminette *.[ch]

test: all
	sh ./tests/test_unit.sh

.PHONY: all bonus clean fclean re .c.o libs libs-clean norm test