# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 12:19:39 by equiana           #+#    #+#              #
#    Updated: 2019/10/11 12:17:15 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = clang

SRC = ft_find_solution.c ft_read_in.c ft_validate.c main.c support.c \
  	  ft_list_size.c ft_lstadd.c ft_lstnew.c ft_strnew.c ft_strsplit.c \
	  ft_memcpy.c ft_strdel.c ft_strlen.c ft_putchar.c ft_putstr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@
	
clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f fillit.h.gch
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
