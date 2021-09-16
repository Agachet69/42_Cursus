# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 17:27:52 by agachet           #+#    #+#              #
#    Updated: 2021/09/15 14:54:44 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = Annuaire

SRCS  = annuaire.cpp Repertoire_class.cpp

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
