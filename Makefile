# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/11/15 20:27:01 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

FILES	= $(wildcard *.c) \

UNAME	= $(shell uname)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread

ifeq ($(UNAME), Darwin)
LDLIBS	= includes/libft_updated/libft.a \
			-lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux) #Debian ?
LDLIBS	= includes/libft_updated/libft.a \
			-Lincludes/mlx_linux -lmlx -Iincludes/mlx_linux -lXext -lX11 -lm
endif

FILES_DIR = ./
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))

all: libs $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

ifeq ($(UNAME), Darwin)
libs:
	$(MAKE) -C includes/libft_updated

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C includes/libft_updated clean
endif

ifeq ($(UNAME), Linux) #Debian ?
libs:
	$(MAKE) -C includes/libft_updated
	$(MAKE) -C includes/mlx_linux

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C includes/libft_updated clean
	$(MAKE) -C includes/mlx_linux clean
endif

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C includes/libft_updated fclean

.PHONY: all re clean fclean