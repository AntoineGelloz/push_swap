# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 11:32:25 by agelloz           #+#    #+#              #
#    Updated: 2019/09/12 14:59:00 by agelloz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = checker
NAME2 = push_swap
FLAGS = -Wall -Wextra
LIBH = libft/inc
LIBA = libft/libft.a
SRC_DIR = src/

SRC1_FILES = checker.c instructions.c init.c cleanup.c display.c
SRC2_FILES = push_swap.c instructions.c init.c sort.c sort_a.c sort_b.c \
	   		 cleanup.c display.c

SRC1 = $(addprefix $(SRC_DIR), $(SRC1_FILES))
SRC2 = $(addprefix $(SRC_DIR), $(SRC2_FILES))
OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)

all: $(NAME) $(NAME2)

$(NAME): $(LIBA) $(OBJ1)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(NAME) -g3 $(OBJ1)
	printf "$(GREEN)created: $@\n$(NC)"

$(NAME2): $(LIBA) $(OBJ2)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(NAME2) -g3 $(OBJ2)
	printf "$(GREEN)created: $@\n$(NC)"

$(LIBA):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBH) -Iinc -o $@ -c $<
	printf "$(CYAN)compiling: $<\n$(NC)"

clean:
	make -C libft fclean
	@rm -f $(OBJ1)
	@rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	printf "$(RED)deleted: $(NAME)\n$(NC)"
	printf "$(RED)deleted: $(NAME2)\n$(NC)"

re: fclean all

CYAN=\033[0;36m
GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

.PHONY: all clean fclean re
.SILENT:
