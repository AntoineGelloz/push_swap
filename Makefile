# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 11:32:25 by agelloz           #+#    #+#              #
#    Updated: 2019/09/05 14:41:28 by agelloz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
EXEC1 = checker
EXEC2 = push_swap
FLAGS = -Wall -Wextra
LIBH = libft/inc
LIBA = libft/libft.a

SRC1 = checker.c instructions1.c instructions2.c functions.c display.c
SRC2 = push_swap.c instructions1.c instructions2.c functions.c \
	   display.c quicksort.c
OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(LIBA) $(OBJ1)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(EXEC1) -g3 $(OBJ1)
	printf "$(GREEN)created: $@\n$(NC)"

$(EXEC2): $(LIBA) $(OBJ2)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(EXEC2) -g3 $(OBJ2)
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
	rm -f $(EXEC1)
	rm -f $(EXEC2)
	printf "$(RED)deleted: $(EXEC1)\n$(NC)"
	printf "$(RED)deleted: $(EXEC2)\n$(NC)"

re: fclean all

CYAN=\033[0;36m
GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

.PHONY: all clean fclean re
.SILENT:
