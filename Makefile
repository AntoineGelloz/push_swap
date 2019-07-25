# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agelloz <agelloz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 11:32:25 by agelloz           #+#    #+#              #
#    Updated: 2019/07/25 18:40:20 by agelloz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
EXEC1 = checker
EXEC2 = push_swap
FLAGS = -Wall -Wextra
LIBH = libft/includes
LIBA = libft/libft.a

SRC1 = checker.c instructions.c functions.c get_next_line.c
SRC2 = push_swap.c instructions.c functions.c selection_sort.c \
	   insertion_sort.c display.c
OBJ1 = $(SRC1:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(LIBA) $(OBJ1)
	#$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -g3 -fsanitize=address -fno-omit-frame-pointer -o $(EXEC1) $(OBJ1)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(EXEC1) -g3 $(OBJ1)

$(EXEC2): $(LIBA) $(OBJ2)
	#$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -g3 -fsanitize=address -fno-omit-frame-pointer -o $(EXEC2) $(OBJ2)
	$(CC) $(FLAGS) -I$(LIBH) -Llibft -lft -o $(EXEC2) -g3 $(OBJ2)

$(LIBA):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBH) -Iinc -o $@ -c $<

clean:
	make -Clibft fclean
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(EXEC1)
	rm -f $(EXEC2)

re: fclean all
