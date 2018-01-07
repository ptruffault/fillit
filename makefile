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

NAME		= fillit

LIB_PATH	= ./libft/
LIB			= -Llibft/ -lft

SRC			= *.c
CFLAGS		= -Wall -Werror -Wextra

VTEST		= test/test

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH) all
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "\033[92mCreate $(NAME)\033[0m"

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[92mClean $(NAME)\033[0m"

re:	fclean all

test: re
	clear
	cat $(VTEST)0
	@./$(NAME) $(VTEST)0

.PHONY: all clean fclean re test
