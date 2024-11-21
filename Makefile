# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 16:37:10 by tafocked          #+#    #+#              #
#    Updated: 2024/11/21 15:45:02 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME    = cub3D

# Compilation
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g #-fsanitize=address

# Détection du système
UNAME   = $(shell uname)
ifeq ($(UNAME), Darwin)
	LDLIBS  = includes/libft_updated/libft.a -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
	LDLIBS  = includes/libft_updated/libft.a -Lincludes/mlx_linux -lmlx -Iincludes/mlx_linux -lXext -lX11 -lm
endif

# Répertoires
SRC_DIR = ./
OBJ_DIR = .obj
LIBFT_DIR = includes/libft_updated

# Recherche des fichiers source
SRC_FILES = $(shell find $(SRC_DIR) -path $(SRC_DIR)includes -prune -o -type f -name '*.c' -print)
# Génération des objets
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:$(SRC_DIR)%.c=%.o))

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
	$(CFLAGS) = -g
	$(MAKE) -C includes/mlx_linux
endif

# Phony targets
.PHONY: all clean fclean re libs