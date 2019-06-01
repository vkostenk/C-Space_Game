# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/25 23:44:14 by vkostenk          #+#    #+#              #
#    Updated: 2019/01/27 18:50:58 by vkostenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro

SRC		= maintest.cpp Player.cpp Enemy.cpp bullet.cpp Window.cpp Entity.cpp
CFLAG	=  -lcurses -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -o $(NAME)


clean:

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
