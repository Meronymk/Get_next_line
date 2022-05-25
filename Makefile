# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/05/25 15:22:31 by krochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

# Fichiers sources.
SRCS_FILES = get_next_line.c get_next_line_utils.c main.c
SRCS_PATH = ./
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Compilateurs
AR = ar
CC = gcc

# Flags
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Macros
REMOVE = rm -rf
COMMIT = $(shell date "+%d %B %T")

# Transforme les fichiers .c en fichiers .o
# La premiere utilise le contenu de la 2e pour compiler.
# J'imprime un tiret (sans newline) pour créer ma ligne de progression.
OBJS= $(SRCS:%.c=%.o)
%.o: %.c
	@printf "."
	@$(CC) $(CFLAGS) -o $@ -c $<

# On appel la commande INIT et NAME puis on imprime le message final.
all: init $(NAME)
	@echo "\n"
	@echo "\033[32m     _    _\033[0m"
	@echo "\033[32m    (\033[33m\033[3m0\033[0m\033[32m)--(\033[33m0\033[32m)\033[0m"
	@echo "\033[32m   /  )___. \ \033[0m    Done!"
	@echo "\033[32m   \________/\033[0m     $(NAME) Compiled!"
	@echo "\033[32m  ./        \.\033[0m"
	@echo "\033[32m ( .        , )\033[0m"
	@echo "\033[32m  \ \_\\//_/ /\033[0m"
	@echo "\033[32m___~~  ~~  ~~___\033[0m"

# On Appel le fichier Make de la librairie Libft et on imprime
# le début de la compilation de pipex à l'écran (sans newline).4
init:
	@echo "Preparing $(NAME)"
	@printf "Compiling ."

# On appel la création des OBJS et ensuite on compile le programme.
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

# Commande de nettoyage.
clean:
	@$(REMOVE) $(OBJS)
	@@$(MAKE) -s clean -C 
fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -s fclean -C

# On nettoie et recompile.
re:	fclean all

# On peut choisir le nom de commit avec "make git COMMIT="
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push