# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 17:27:52 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 16:12:24 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= Annuaire

CC		= clang++

SRCS 	= main.cpp Repertoire_class.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean:
	rm -rf ${NAME} ${OBJS}

re: fclean all

.PHONY: all fclean re
