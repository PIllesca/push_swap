# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:24:06 by pillesca          #+#    #+#              #
#    Updated: 2024/05/03 12:48:34 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = push_swap.out

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

makelib:
	make -C $(LIBFTDIR)
	@mv $(LIBFTDIR)/$(LIBFTSRC) .

$(NAME): makelib $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) $(PRINTSRC) $(LIBFTSRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFTSRC)

.PHONY: all, clean, fclean