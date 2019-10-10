# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: equiana <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 12:19:39 by equiana           #+#    #+#              #
#    Updated: 2019/10/10 20:39:00 by equiana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_find_solution.c ft_read_in.c ft_validate.c main.c support.c 

HDR = -I ./

ORC = $(SRC:.c=.o)

MUL = -c -Wall -Wextra -Werror

LIB = ./libft/libft.a

$(NAME): $(ORC)
	@make -C ./libft
	@gcc $(MUL) $(ORC) $(HDR) $(LIB) -o $(NAME) 	
		
all: $(NAME)

clean:
	@/bin/rm -f $(ORC)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
