# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/01/06 15:53:03 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC	= *.c

LIB	= -Llibft/ -lft

VTEST	= test/test

CFLAGS	= -o $(NAME) -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	
	gcc $(CFLAGS) $(SRC) $(LIB)
test: re
	clear
	cat $(VTEST)0
	@./$(NAME) $(VTEST)0
fclean:
	@rm -f $(NAME)

re:	fclean all
