# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/01 20:59:37 by gmoon             #+#    #+#              #
#    Updated: 2020/04/20 06:20:36 by gmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCDIR = ./src
INCDIR = ./inc
OBJDIR = ./obj

SRC = main.c \
	error.c \
	init_info.c \
	init_map.c \
	init_texture.c \
	is_wall.c \
	key_hook.c \
	make_first_scene.c \
	map_check.c \
	raycast.c \
	rc_color.c \
	rc_find_ray_dist_init.c \
	rc_find_ray_dist.c \
	rc_render.c \
	save_bmp_image.c \
	rc_item.c
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC = clang
#CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g3

MLXDIR = ./minilibx_linux
MLX_LIB = $(addprefix $(MLXDIR)/,mlx.a)
MLX_INC = -I $(MLXDIR)
MLX_LNK =  -L $(MLXDIR) -lmlx -lX11 -lXext
#MLX_LNK = -lmlx -framework OpenGL -framework AppKit

FTDIR = ./libft
FT_LIB = $(addprefix $(FTDIR)/,libft.a)
FT_INC = -I $(FTDIR)
FT_LNK = -L $(FTDIR) -lft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FTDIR)

$(MLX_LIB):
	make -C $(MLXDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -lbsd -o $(NAME)
	# $(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

bonus: $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

.PHONY : all bonus clean fclean re

# comment is for macos.