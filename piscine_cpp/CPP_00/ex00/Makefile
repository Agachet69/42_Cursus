# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 18:52:17 by agachet           #+#    #+#              #
#    Updated: 2021/09/13 17:22:21 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = megaphone

SRCS  = megaphone.cpp

FLAGS = -Wall -Wextra -Werror

%.o:		%.c
			clang++ $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):
			clang++ $(FLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf ${NAME}

re: fclean all

.PHONY: all fclean re
