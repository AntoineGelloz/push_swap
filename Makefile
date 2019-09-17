# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 11:32:25 by agelloz           #+#    #+#              #
#    Updated: 2019/09/16 15:37:55 by agelloz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = checker
NAME2 = push_swap
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -Wpadded -g3 -fsanitize=address,undefined
LIBH = libft/inc
INC = inc/
HEAD = $(INC)push_swap.h
LIBA = libft/libft.a
SRC_DIR = src/

SRC1_FILES = checker.c instructions.c instructions2.c init.c cleanup.c \
			 display.c
SRC2_FILES = push_swap.c instructions.c instructions2.c init.c sort.c \
			 sort2.c sort_a.c sort_b.c cleanup.c display.c

SRC1 = $(addprefix $(SRC_DIR), $(SRC1_FILES))
SRC2 = $(addprefix $(SRC_DIR), $(SRC2_FILES))
OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)

all: $(NAME) $(NAME2)

$(NAME): $(LIBA) $(OBJ1) 
	$(CC) $(CFLAGS) -I$(LIBH) -I$(INC) -Llibft -lft -o $@ -g3 $(OBJ1)
	printf "$(GREEN)created: $@\n$(NC)"

$(NAME2): $(LIBA) $(OBJ2)
	$(CC) $(CFLAGS) -I$(LIBH) -I$(INC) -Llibft -lft -o $@ -g3 $(OBJ2)
	printf "$(GREEN)created: $@\n$(NC)"

$(LIBA): FORCE
	$(MAKE) -C libft

FORCE:

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(LIBH) -I$(INC) -o $@ -c $<
	printf "$(CYAN)compiling: $<\n$(NC)"

clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	printf "$(RED)deleted: $(NAME)\n$(NC)"
	printf "$(RED)deleted: $(NAME2)\n$(NC)"

re: fclean all

CYAN=\033[0;36m
GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

.PHONY: all clean fclean re
.SILENT:
