# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/11/22 13:20:34 by fimazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRC_DIR = .
SRC_FILES = cub3d.c \
            checker/check_chars.c \
            checker/check_color.c \
            checker/check_player.c \
            checker/check_textures.c \
            checker/check_walls.c \
            checker/extension_cub.c \
            initialization/init_game.c \
            initialization/init_textures.c \
            inputs/hooks.c \
            inputs/movement.c \
            parser/fill_map.c \
            parser/read_map.c \
            parser/read_map2.c \
            raycasting/color.c \
            raycasting/rays.c \
            raycasting/rendering.c \
            utils/error.c \
            utils/free.c \
            utils/time.c \
            utils/utils.c \
            utils/utils_1.c

UNAME	= $(shell uname)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

ifeq ($(UNAME), Darwin)
LDLIBS	= includes/libft_updated/libft.a \
			-lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
LDLIBS	= includes/libft_updated/libft.a \
			-Lincludes/mlx_linux -lmlx -Iincludes/mlx_linux -lXext -lX11 -lm
endif

OBJ_DIR = .obj
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: libs $(NAME)

libs:
ifeq ($(UNAME), Darwin)
	$(MAKE) -C includes/libft_updated
endif
ifeq ($(UNAME), Linux)
	$(MAKE) -C includes/libft_updated
	$(MAKE) -C includes/mlx_linux
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
ifeq ($(UNAME), Darwin)
	$(MAKE) -C includes/libft_updated clean
endif
ifeq ($(UNAME), Linux)
	$(MAKE) -C includes/libft_updated clean
	$(MAKE) -C includes/mlx_linux clean
endif

fclean: clean
	rm -f $(NAME)
ifeq ($(UNAME), Darwin)
	$(MAKE) -C includes/libft_updated fclean
endif
ifeq ($(UNAME), Linux)
	$(MAKE) -C includes/libft_updated fclean
endif

re: fclean all

.PHONY: all libs clean fclean re
