# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/11/19 15:34:08 by fimazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME	= cub3D

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread

# Détection du système
UNAME	= $(shell uname)
ifeq ($(UNAME), Darwin)
LDLIBS	= includes/libft_updated/libft.a -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
LDLIBS	= includes/libft_updated/libft.a -Lincludes/mlx_linux -lmlx -Iincludes/mlx_linux -lXext -lX11 -lm
endif

# Répertoires
SRC_DIR = ./
OBJ_DIR = .obj
CHECKER_DIR = checker
PARSER_DIR = parser
TEXTURE_DIR = textures
UTILS_DIR = utils
LIBFT_DIR = includes/libft_updated

# Liste des fichiers sources
SRC_FILES = \
	cub3d.c \
	color.c \
	error.c \
	free.c \
	hooks.c \
	init_game.c \
	movement.c \
	rays.c \
	rendering.c \
	textures.c \
	time.c \
	$(addprefix $(CHECKER_DIR)/, check_chars.c check_color.c check_player.c check_textures.c check_walls.c extension_cub.c) \
	$(addprefix $(PARSER_DIR)/, fill_map.c read_map.c) \
	$(addprefix $(UTILS_DIR)/, utils.c utils_1.c)

# Génération des objets
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Règle par défaut
all: libs $(NAME)

# Compilation du programme
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LDLIBS) -o $(NAME)

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des objets
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
ifeq ($(UNAME), Linux)
	$(MAKE) -C includes/mlx_linux clean
endif

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

# Compilation des bibliothèques
libs:
	$(MAKE) -C $(LIBFT_DIR)
ifeq ($(UNAME), Linux)
	$(MAKE) -C includes/mlx_linux
endif

# Phony targets
.PHONY: all clean fclean re libs
