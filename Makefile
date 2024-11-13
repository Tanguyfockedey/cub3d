# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/11/13 15:51:11 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

FILES	= $(wildcard *.c) \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror  -g #-fsanitize=thread
LDLIBS	= includes/libft_updated/libft.a \
			-Lincludes/mlx_linux -lmlx -Iincludes/mlx_linux -lXext -lX11 -lm
# -lmlx -framework OpenGL -framework AppKit

FILES_DIR = ./
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))
#OBJ		= $(FILES:.c=.o)

all: libs $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

libs:
	$(MAKE) -C includes/libft_updated
	$(MAKE) -C includes/mlx_linux

clean:
	rm -rf $(OBJ_DIR)
#	rm -f $(OBJ)
	$(MAKE) -C includes/libft_updated clean
	$(MAKE) -C includes/mlx_linux clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C includes/libft_updated fclean

.PHONY: all re clean fclean