# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:24:06 by pillesca          #+#    #+#              #
#    Updated: 2024/05/09 14:58:19 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = args_chk.c aux.c aux_stack.c aux_swap.c aux_push.c aux_rotate.c 
SRC += aux_reverse.c aux_best.c aux_sort.c aux_apply.c debug.c aux_find.c
SRC += main.c push_swap.c

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