# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:24:06 by pillesca          #+#    #+#              #
#    Updated: 2024/05/07 20:13:13 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = aux.c aux_stack.c aux_rotate.c aux_swap.c aux_reverse.c aux_sort.c
SRC += aux_best.c aux_best2.c aux_utils.c aux_push.c args_chk.c push_swap.c
SRC += main.c aux_debug.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: makelib $(NAME)

makelib:
	make -C $(LIBFTDIR)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTDIR)/$(LIBFTSRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all, clean, fclean, re