# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:24:06 by pillesca          #+#    #+#              #
#    Updated: 2024/05/04 23:40:47 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = aux.c aux_stack.c aux_rotate.c aux_swap.c aux_reverse.c
SRC += args_chk.c push_swap.c main.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

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

.PHONY: all, clean, fclean