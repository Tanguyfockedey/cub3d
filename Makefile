# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/10/18 16:22:31 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

FILES	= $(wildcard *.c) \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread
LDLIBS	= includes/libft_updated/libft.a \
			-lmlx -framework OpenGL -framework AppKit

FILES_DIR = ./
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:%.c=%.o))

all: libs $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

libs:
	$(MAKE) -C includes/libft_updated

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C includes/libft_updated clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C includes/libft_updated fclean

.PHONY: all re clean fclean